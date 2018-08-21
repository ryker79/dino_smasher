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

#define GAME_TITLE 0
#define GAME_PLAY 1
#define GAME_OVER 2
#define GAME_HIGH 3
int game_state = GAME_TITLE;

// Define Functions below here or use other .ino or cpp files
//
void title_screen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Dino Smasher \n");
}

void game_play_screen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Gameplay \n");
}

void game_over_screen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Game Over \n");
}

void high_score_screen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("High Score: \n");
}

void game_loop()
{
	switch(game_state)
	{
	case GAME_TITLE:
		title_screen();
		break;
	case GAME_PLAY:
		game_play_screen();
		break;
	case GAME_OVER:
		game_over_screen();
		break;
	case GAME_HIGH:
		high_score_screen();
		break;
	}
}

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
	
	game_loop();

	arduboy.display();
}


