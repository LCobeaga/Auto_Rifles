
// Shadow Price Firing & ammo counter code
// Written by Luca Cobeaga, go to https://github.com/LCobeaga/Auto_Rifles for updates
// Contact me at lucaslegos@gmail.com

#include <Servo.h>            //brushless motor control library
#include <Adafruit_GFX.h>     //oled display library
#include <Adafruit_SSD1306.h> //monocrome I2C library (pairs with above library)
#include <JC_Button.h>        //button control library
#include <AmmoCounter.h>      //Monty's oled ammocounter code conerted to a library

//pins for button
#define SOLENOID_PIN 6        //solenoid pin
#define RELOAD_BTN_PIN 3      //magazine sensor
#define TRIGGER_BTN_PIN 2     //trigger pin
#define FIRE_MODE_PIN 5       //firing mode toggle 
#define MAG_SZ_TOG_BTN_PIN 4  //mag size toggle
#define MOTOR_PIN 10           //brushless motor pin
#define POT_PIN A3            //potentiometer pin

#define TEXT_SIZE 6  // multiplier on text size
#define ROTATION 1   // rotation of text i.e. 0 = 0deg, 1 = 90deg, 2 = 180deg, 3 = 270deg
#define WIDTH 0      // how far to move from long edge (128 pixel edge)
#define HEIGHT -32   // fow far from edge with wires (32 pixel edge)
#define DEBOUNCE 20  // button debounce time in ms
#define MAXPWM 2000  // motor max PWM 
#define MINPWM 1100  // motor min PWM
#define STOPPWM 1000 // motor stopped PWM

uint32_t ms_last = 0;     // pusher timing
uint32_t ms_last_rev = 0; // revup timing
unsigned int pwm;         // PWM signal for motors
int winddown  = 3100;     // time for motor to go from MINRPM to stopped
int mosfetState = HIGH;   // state memory of solenoid
bool fire = false;        // shooting command
byte modeArr[] = {0,1,2,3}; // array of fire modes (0 is full auto, rest are # of darts per trigger pull
byte currentModeInd = 0;    // index of selected mode (starts counting from 0)
byte currentMode = modeArr[currentModeInd]; // actual value of selected mode

/////////////////////////////////////////////////////
// please note that my version of the ammo counter //
// has them written vertically, so my height and   //
// width are reversed compared to the screen orign //
/////////////////////////////////////////////////////

Servo flywheel;                                                                              //create servo object to control the esc 
Button selectFire(FIRE_MODE_PIN, DEBOUNCE, true, true);                                      //create button for select fire
Button trigger(TRIGGER_BTN_PIN, 30, true, true);                                             //create button for trigger
AmmoCounter AC = AmmoCounter(TRIGGER_BTN_PIN, RELOAD_BTN_PIN, MAG_SZ_TOG_BTN_PIN, DEBOUNCE); //create ammo counter object

void setup() {
  AC.begin(TEXT_SIZE, ROTATION, WIDTH, HEIGHT); // ammo counter start
  selectFire.begin();                           // select fire button start
  trigger.begin();                              // trigger button start
  flywheel.attach(MOTOR_PIN);                   // brushless motor attach
  pinMode(SOLENOID_PIN,OUTPUT);                 // solenoid attach

////////////////////////////////////////////
// DO NOT USE WITH BLHELI ESCS. THIS CODE //
// WILL BURN OUT YOUR MOTORS. BLHELI      //
// SPECIFIC CODE COMING SOON              //
////////////////////////////////////////////
  //Serial.begin(9600);
  
}

void loop() {
  int potVal = analogRead(POT_PIN); // checks to see current 
  trigger.read();                   // checks if button pressed
  if(trigger.wasPressed()) {            // self explanatory
    pwm = map(potVal,0,1023,1300,1800); // maps potentiometer to the PWM value to send to the motors
    fire = true;                        // input to pusher 
    rev(pwm);                           // input to flywheels
    
    if(currentMode == 0){               // check for full auto
      while(trigger.isPressed()){       // self explanatory
        pusher(fire);                   // pusher function
        AC.countAmmo(fire);             // count ammo, must be fed boolean 
        trigger.read();                 // check trigger again so not to get stuck in while loop
      }
    }
    
    else {                                      // for all other fire modes
      for(int i = 0; i<= (currentMode-1); i++){ // loop for the amount of shots in the burst
      pusher(fire);                             // pusher function
      AC.countAmmo(fire);                       //count ammo, must be fed boolean 
      }
    }
  }
  else {
    fire = false;                         // input to pusher
    flywheel.writeMicroseconds(STOPPWM);  // stops motors but keeps ESCs on
    pusher(fire);                         // keeps pusher off
  }

  currentMode = mode(); // function to check if mode swapped
  AC.reload();          //reload, constantly check for the magazine switch to be pressed/not pressed
  AC.toggleMags();      //toggle between magazine sizes, constanly check for the magazine toggle switch to be pressed
}

void pusher (bool fire) {
  int change = 0;             // for loop exit variable

  while(change<2){            // loop to keep pusher timing
    uint32_t ms = millis();   // timing variable
    if (ms - ms_last >= 60) { // timing setup
      
      ms_last = ms;           // timing exit variable

      // state swapper for pusher
      if (mosfetState == LOW) mosfetState = HIGH; 
      else mosfetState = LOW;

      // saftey check to make sure pusher never gets stuck in out position
      if (!fire) {
        mosfetState = LOW; 
      }
      change ++;                                // indexing loop variable 
      digitalWrite(SOLENOID_PIN, mosfetState);  // actually moving the pusher
    }
  }
}

byte mode() {
  selectFire.read();  // check if select fire button was pressed
  if(selectFire.wasPressed()){
    currentModeInd = (currentModeInd < (sizeof(modeArr)/sizeof(modeArr[0]) - 1)) ? currentModeInd + 1 : 0; // indexing thru array with roll over protection

    currentMode = modeArr[currentModeInd]; // grabs burst value from array
    String dispMode = (String)currentMode; // prepares to display burst amount
    AC.displayAmmo(dispMode);              // displays burst amount
  }
  return currentMode; // pushes burst value out of function
}

void rev(int pwm){
  uint32_t ms = millis(); // timing variable
  
  winddown = map(pwm,MINPWM,MAXPWM,3200,5000); // mapping of cooldown time based off of potentiometer
  
  if (ms - ms_last_rev >= winddown){ // check to see if flywheels are still spinning 
    int currSpeed = MINPWM; // variable pwm value for ramping speed

    // adaptive delay
    int rampSize = map(pwm,MINPWM,MAXPWM,0,9);
    while (currSpeed < pwm){

      flywheel.writeMicroseconds(currSpeed); 
      
      currSpeed += rampSize;
      delayMicroseconds(5500);
    }

    flywheel.writeMicroseconds(pwm); // final speed to hold during firing
    
    ms_last_rev = ms; // saves time since last rev
  }
  
  else { // if flywheels still moving 
    unsigned int currSpeed = (ms - ms_last_rev)/(winddown)*pwm; // calculate speed based on linear deceleration 
    
    if (currSpeed <1100) currSpeed = 1100; // wheels stop below 1000 pwm so this pulls up any small values
    int rampSize = map(pwm,MINPWM,MAXPWM,1,10);
    
    // if below desired speed ramp up
    while (currSpeed < pwm){ 
      flywheel.writeMicroseconds(currSpeed); 
      
      currSpeed += rampSize;
    }
    // if above desired speed ramp down
    while (currSpeed > pwm){
      flywheel.writeMicroseconds(currSpeed); 
      
      currSpeed -= rampSize;
    }

    flywheel.writeMicroseconds(pwm); // hold speed
    
    ms_last_rev = ms; // saves time since last rev
  }
  
}
