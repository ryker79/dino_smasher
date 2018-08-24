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
#define WORLD_HEIGHT 4
#define WORLD_WIDTH 20

int game_state = GAME_TITLE;
int world[WORLD_HEIGHT][WORLD_WIDTH] = 
{
	{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 }
};

// Define Functions below here or use other .ino or cpp files
//
void drawWorld()
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 20; ++x)
		{
			arduboy.print(world[y][x]);
		}
		arduboy.print("\n");
	}
}

void titleScreen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Dino Smasher \n");
	
	if (arduboy.justPressed(A_BUTTON))
	{
		++game_state;
	}
}

void gamePlayScreen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Gameplay \n");
	drawWorld();
	if (arduboy.justPressed(A_BUTTON))
	{
		++game_state;
	}
}

void gameOverScreen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("Game Over \n");
	if (arduboy.justPressed(A_BUTTON))
	{
		++game_state;
	}
}

void highScoreScreen()
{
	arduboy.setCursor(0, 0);
	arduboy.print("High Score: \n");
	if (arduboy.justPressed(A_BUTTON))
	{
		game_state = GAME_TITLE;
	}
}

void gameLoop()
{
	switch(game_state)
	{
	case GAME_TITLE:
		titleScreen();
		break;
	case GAME_PLAY:
		gamePlayScreen();
		break;
	case GAME_OVER:
		gameOverScreen();
		break;
	case GAME_HIGH:
		highScoreScreen();
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
	
	gameLoop();

	arduboy.display();
}


