// LCD nerf ammo counter 

// Luca Cobeaga's conversion of Monty Choy's ammo counter code to a library

#ifndef AmmoCounter_h
#define AmmoCounter_h

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <JC_Button.h>
#include <arduino.h>

class AmmoCounter
{
	public:
		AmmoCounter(int TRIGGER_BTN_PIN, int RELOAD_BTN_PIN, int MAG_SZ_TOG_BTN_PIN, int DEBOUNCE);
		
		void begin (int TEXT_SIZE, int ROTATION, int HEIGHT, int WIDTH);
		void countAmmo (bool TRIGGER);
		void displayAmmo (String ammoToDisplay);
		void reload ();
		void toggleMags ();

		int TRIGGER_BTN_PIN;
		int RELOAD_BTN_PIN;
		int MAG_SZ_TOG_BTN_PIN;
		
		int TEXT_SIZE;
		int ROTATION;
		int HEIGHT;
		int WIDTH;
		int DEBOUNCE;
		bool TRIGGER;
		
//		Button *triggerBtn;    //trigger button
		Button *reloadBtn;     //reloading button
		Button *magSzTogBtn;   //magazine size toggle button
	private:
		int _oled_reset;
		bool _invert;
		bool _pullup;

		
		Adafruit_SSD1306 *display;     //display
		
		void initDisplayAmmo ();

		byte currentMagSize;
		byte currentAmmo;
		byte maxAmmo;
		byte *magSizeArr;
};

#endif		