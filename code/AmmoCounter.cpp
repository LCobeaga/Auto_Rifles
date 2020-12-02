//AmmoCounter

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <JC_Button.h>
#include <Arduino.h>
#include <AmmoCounter.h> 

/*----------------------------------------------------------------------*
 * nerf-ammo-counter                                                    *
 * Monty Choy, 2017     												*
 * converted to library by Luca Cobeaga									*
 *                                                                      *
 * Arduino sketch for ammo counters in NERF blasters                    * 
 * Be sure to check out the links:                                      *
 * Youtube Video: https://goo.gl/KjQfdK                                 *
 * Tutorial: https://goo.gl/8JSXbc                                      *
 *----------------------------------------------------------------------*/

byte MSA[11] = {5, 6, 10, 12, 15, 18, 20, 22, 25, 35, 0};  //keep track of the magazine sizes

AmmoCounter::AmmoCounter( int TRIGGER_BTN_PIN, int RELOAD_BTN_PIN, int MAG_SZ_TOG_BTN_PIN, int DEBOUNCE) {
	_oled_reset = 4;
	_invert = true;
	_pullup = true;
//	DEBOUNCE = 20;
	
	display = new Adafruit_SSD1306(_oled_reset);     //display

//	triggerBtn = new Button(TRIGGER_BTN_PIN, DEBOUNCE, _pullup, _invert);       //trigger button
	reloadBtn = new Button(RELOAD_BTN_PIN, DEBOUNCE, _pullup, _invert);         //reloading button
	magSzTogBtn = new Button(MAG_SZ_TOG_BTN_PIN, DEBOUNCE, _pullup, _invert);   //magazine size toggle button
	
	//stuff to help keep track of magazine stuff
	//if you want to add/remove magazine sizes, do that here. Remember, they go in order when you toggle between them, from left to right in this.
	//
	//when you change the value, the "currentMagSize"(several lines below) has to be less than the number of different magazines sizes, 
	//the number of different magazine size values in the "magSizeArr" you can change "currentMagSize" to whatever you want. 
	//When it program first starts, when the microcontroller turns on, the 5th element of "magSizeArr" is the current magazine size,
	//starting from 0. 0 is used for count-up mode. 
	//Ex: byte array = {1(0), 2(1), 3(2), 4(3)} - the numbers without parenthesis are the values this array/list 
	//stores, and the number between the parenthesis indicates which place they are, their "index", where they are in the list/array. 
	//If I want to access the value 1, which is the first value of the array/list, which the computer sees as the 
	//"zeroith" value, I would do array[0]. If I want to access the value 3, the third value of the array, I would do array[2]

	magSizeArr = MSA;
	currentMagSize = 0;  //keep track of the current magazine size
	currentAmmo = magSizeArr[currentMagSize];    //keep track of how much ammo there currently is
	maxAmmo = magSizeArr[currentMagSize];    //keep track of what the max ammo is, for use when reloading 
}



void AmmoCounter::begin (int ts, int r, int h, int w) {
	display->begin(SSD1306_SWITCHCAPVCC, 0x3C);    //begin stuff for the display
//	triggerBtn->begin();
	reloadBtn->begin();
	magSzTogBtn->begin();
	TEXT_SIZE = ts;
	ROTATION = r;
	HEIGHT = r;
	WIDTH = w;
	initDisplayAmmo();     //show the ammo
}

//actually dispaly ammo onto screen
void AmmoCounter::displayAmmo (String ammoToDisplay) {
  display->clearDisplay();           //clear the display, so the stuff that was here before is no longer here
  display->setTextSize(TEXT_SIZE);   //set the size of the text
  display->setTextColor(WHITE);      //set the color of text text
  display->setRotation(ROTATION);
  display->setCursor(HEIGHT , WIDTH);  //center text
  display->print(ammoToDisplay);     //print the text
  display->display();                //display the text
}

//set up ammo to be displayed
void AmmoCounter::initDisplayAmmo () {
  //if the ammo to print, current ammo, is less that 10, make it like '01' or '04'  
  String ammoToDisplay = currentAmmo < 10 ? ("0" + (String)currentAmmo) : (String)currentAmmo;
  displayAmmo(ammoToDisplay);  //display the text, the ammo
}

void AmmoCounter::countAmmo (bool state) {
  //triggerBtn->read();              //read trigger button
  TRIGGER = state;
  if (TRIGGER) {   //trigger button pressed
    if (maxAmmo != 0 && currentAmmo < 99 && currentAmmo > 0) {  //make sure that the ammo is less than 99 so it doesnt overflow the display and not in count-up mode
      currentAmmo--;    //increment ammo
    } else if (maxAmmo == 0 && currentAmmo < 99) { //make sure that the ammo is more than 0 so no negative numbers are displayed and in count-up mode
      currentAmmo++;    //decrement ammo
    }
    initDisplayAmmo();    //display ammo
  }
}

void AmmoCounter::reload () {
  reloadBtn->read();               //read reload button
  if (reloadBtn->wasPressed()) {   //reload button pressed
    currentAmmo = maxAmmo;        //reset ammo
    initDisplayAmmo();            //display ammo
  }
}

void AmmoCounter::toggleMags () {
  magSzTogBtn->read();               //read magazine size toggle button
  if (magSzTogBtn->wasPressed()) {    //magazine size toggle button pressed
    //cycle through mag sizes based on array, and make sure array doens't overflow
    currentMagSize = (currentMagSize < (sizeof(MSA)/sizeof(MSA[0]) - 1)) ? currentMagSize + 1 : 0;    

    //there's a new max ammo, because there's a new magazine size
    maxAmmo = magSizeArr[currentMagSize];
    currentAmmo = maxAmmo;

    initDisplayAmmo();      //display ammo
  }
}