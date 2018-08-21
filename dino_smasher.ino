// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       dino_smasher.ino
    Created:	8/21/2018 7:29:38 AM
    Author:     VML\jrice
*/

// Define User Types below here or use a .h file
//
#include <Arduboy2.h>;
Arduboy2 arduboy;

// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
	arduboy.begin();
	arduboy.setFrameRate(45);
	arduboy.display();

	arduboy.initRandomSeed();

	arduboy.clear();
}

// Add the main program code into the continuous loop() function
void loop()
{
	if(!arduboy.nextFrame())
	{
		return;
	}

	arduboy.pollButtons();

	arduboy.clear();

	arduboy.setCursor(0, 0);
	arduboy.print(F("Hello!"));

	arduboy.display();
}
