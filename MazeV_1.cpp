#include <iostream>
#include <cmath>
#include <time.h>
#include "TextFunction.h"
#include "Token.h"

/*
#include <Mmsystem.h>					//Music includes are here
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
*/

using namespace std;

/*------------------------------------------------------------------
Ethan Letrong
letronge@csu.fullerton.edu
890390305
CPSC 386

Maze Game Project
------------------------------------------------------------------*/

//---------------------Data Types-------------------------------

struct player
{
	string name;
	int xPos;						//X coordinates
	int yPos;						//Y coordinates
	char icon;
	int hp;
	int coins;
}hero;

struct zombie
{
	int xPos;						//X coordinates
	int yPos;						//Y coordinates
	char iconZombie;
};

//-----------------------Actions and Functions-----------------------------

//If the zombie bites the player, lower the HP and the player restarts from origin point
void hero_bit()
{
	cout << "A zombie bit you and you blacked out. Apparently you ran back to start." << endl;
	hero.xPos = 1;
	hero.yPos = 1;
	hero.hp --;
}

//Function checks the PLAYER and returns a status message to alert the player what their health is.
void playerHealth()
{
	if (hero.hp == 3)
	{
		cout << "You are at full strength!" << endl;
	}
	if (hero.hp == 2)
	{
		cout << "A zombie took a bite out of you. Seems you ran to start." << endl;
	}
	if (hero.hp == 1)
	{
		cout << "You don't feel so good. " << endl;
	}
}

//Function displays the PLAYER's stats and outlines some symbols for reference. Can be altered to include some simple attribures
void playerUI()
{

	cout << endl;
	cout << "==========Map Key============   ==================Player Stats=================" << endl;
	cout << "  = : Wall     # : Blockade" << "   |  Hero: " << hero.name << " | Player's Coordinates: " << "("<< hero.xPos << "," << hero.yPos << ")" << endl;
	cout << "  @ : Player   Z : Zombie  " << "   |  Health: " << hero.hp << endl;
	cout << "=============================   ===============================================" << endl;
	playerHealth();																				//Displayes the PLAYER's health condition.
	cout << "******************************************************************** \n";
	cout << "Press [D] [A] [W] or [S] and then return: This will count as a move." << endl;
	cout << "Press [Q] and then return: This will end the game." << endl;
	cout << "******************************************************************** ";
}

//
void coinCount()
{
	if (hero.coins == 0)
	{
		cout << "Seems like you escaped the house without any coins. " << endl;
		cout << "Makes you wonder what happens if you collect them all? " << endl;
	}
	if (hero.coins < 5)
	{
		cout << "Even though the house faded away, you feel a jingle in your pocket. " << endl;
		cout << "You pull out a few gold coins. How did they end up there? " << endl;
		cout << "Where did you get them from? How come...you feel like you are missing something? " << endl;
		cout << "...." << endl;
		cout << "Best not to think about it. " << endl;
	}
	if (hero.coins == 5)
	{
		easterEgg();
	}
}

//---------------------------------------PROGRAM STARTS HERE----------------------------------------------//
int main()
{

	intro();
	cout << "What is your name?" << endl;
	cin >> hero.name;

	//Spawn the enemies in the maze
	zombie zombie_horizontal =	{ 13, 9, 'Z' };
	zombie zombie_vertical =	{ 11, 9, 'Z' };
	zombie zombie_jumper =		{ 1, 15, 'Z' };

	//Time to spawn and write the maze
	const char HEIGHT = 18;
	const char WIDTH = 18;

	//Actions that rewrite the maze
	bool refresh = false;
	char move_key = 'd';

	//spawn the player's HP and icon
	hero.hp = 3;
	hero.xPos = 1;
	hero.yPos = 1;
	hero.icon = '@';

	//We will use this maze since we can't randomly generate a maze
	// TOP --------------------------------------> BOTTOM
	unsigned char maze[WIDTH][HEIGHT] =
	{
			'+','|','|','|','|','|','|','|','|','|','|','|','|','|','|','|','|','+',
			'=',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#','$','#',' ','#','=',
			'=',' ','#','#',' ','#','#','$','#',' ','#','#',' ',' ','#',' ','#','=',
			'=',' ','#','#',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',
			'=',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','=',
			'=',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','=',
			'=','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','=',
			'=','#',' ',' ','#','#','#','#','#',' ','#',' ',' ','#','#',' ',' ','=',
			'=','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','$','=',
			'=',' ','#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ',' ','=',
			'=',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#','=',
			'=',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','=',
			'=',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ','#','#','#',' ','=',
			'=',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','=',
			'=','#','#',' ',' ','#','$','#','#',' ',' ','#',' ','#','#',' ','#','=',
			'=','#','#','#',' ','#','#','#','#',' ','#',' ',' ','#','#',' ','#','=',
			'=','#','#',' ',' ',' ','$','#','#',' ',' ',' ','#','#','#','#','#','=',
			'+','|','|','|','|','|','|','|','|','|','|','|','|','|','|','|','|','+',
	};
	//Display actions and instructions
	cout << "Press [D] [A] [W] or [S] and then return: This will start the game." << endl;
	cout << "Press [Q] and then return: This will end the game.";


	//If the user has not pressed 'Q', then the game will run.
	while (move_key != 'q')
	{

		//We need to base our actions off of time and the seed it generates
		srand(time(NULL));
		int random_move = rand() % 2 + 1; // random number between 1 and 2

		//Take in the user's input for movement
		cin >> move_key;
		refresh = true;					//We will now refresh the map after the action

		//-------------------This will be based off of the player's actions---------------------------//

		switch (move_key)
		{

		//Pressing 'W' will go NORTH. Note: Manipulate the y axis
		case 'w':

			refresh = true;
			if (maze[hero.xPos][hero.yPos - 1] != '#' && maze[hero.xPos][hero.yPos - 1] != '=')
			{

				maze[hero.xPos][hero.yPos] = ' ';
				hero.yPos -= 1;

				//if the player exists on the same tile as a coin
				if (maze[hero.xPos][hero.yPos] == '$')
				{
					hero.coins++;
				}

				//if the player exists on the same tile as a zombie
				if (maze[hero.xPos][hero.yPos] == maze[zombie_horizontal.xPos][zombie_horizontal.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_vertical.xPos][zombie_vertical.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_jumper.xPos][zombie_jumper.yPos])
				{
					hero_bit();
				}
			}

			else
			{
				//cout << hero.xPos << " " << hero.yPos << endl;
				cout << "You ran into a wall!";
			}
			break;

		//Pressing 'S' will go SOUTH. Note: Manipulate the y axis
		case 's':

			refresh = true;
			if (maze[hero.xPos][hero.yPos + 1] != '#' && maze[hero.xPos][hero.yPos + 1] != '=')
			{

				maze[hero.xPos][hero.yPos] = ' ';
				hero.yPos += 1;

				//if the player exists on the same tile as a coin
				if (maze[hero.xPos][hero.yPos] == '$')
				{
					hero.coins++;
				}

				//if the player exists on the same tile as a zombie
				if (maze[hero.xPos][hero.yPos] == maze[zombie_horizontal.xPos][zombie_horizontal.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_vertical.xPos][zombie_vertical.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_jumper.xPos][zombie_jumper.yPos])
				{
					hero_bit();
				}
			}

			else
			{
				// debugging: cout << hero.xPos << " " << hero.yPos << endl;
				cout << "You ran into a wall!";
			}
			break;

		//Pressing 'A' will go WEST. Note: Manipulate the x axis
		case 'a':

			refresh = true;
			if (maze[hero.xPos - 1][hero.yPos] != '#' && maze[hero.xPos - 1][hero.yPos] != '|')
			{

				maze[hero.xPos][hero.yPos] = ' ';
				hero.xPos -= 1;

				//if the player exists on the same tile as a coin
				if (maze[hero.xPos][hero.yPos] == '$')
				{
					hero.coins++;
				}

				//if the player exists on the same tile as a zombie
				if (maze[hero.xPos][hero.yPos] == maze[zombie_horizontal.xPos][zombie_horizontal.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_vertical.xPos][zombie_vertical.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_jumper.xPos][zombie_jumper.yPos])
				{
					hero_bit();
				}
			}

			else
			{
				//cout << hero.xPos << " " << hero.yPos << endl;
				cout << "You ran into a wall!";
			}
			break;

		//Pressing 'D' will go EAST. Note: Manipulate the x axis
		case 'd':

			refresh = true;
			if (maze[hero.xPos + 1][hero.yPos] != '#' && maze[hero.xPos + 1][hero.yPos] != '|')
			{

				maze[hero.xPos][hero.yPos] = ' ';
				hero.xPos += 1;

				//if the player exists on the same tile as a coin
				if (maze[hero.xPos][hero.yPos] == '$')
				{
					hero.coins++;
				}

				//if the player exists on the same tile as a zombie
				if (maze[hero.xPos][hero.yPos] == maze[zombie_horizontal.xPos][zombie_horizontal.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_vertical.xPos][zombie_vertical.yPos] ||
					maze[hero.xPos][hero.yPos] == maze[zombie_jumper.xPos][zombie_jumper.yPos])
				{
					hero_bit();
				}
			}

			else
			{
				//cout << hero.xPos << " " << hero.yPos << endl;
				cout << "You ran into a wall!";
			}
			break;

		}


		//----------------------Zombies' movements-----------------------//

		//This zombie randomly wanders the hallway left and right. Makes it harder for players to predict them
		switch (random_move)
		{
		case 1:
			if (maze[zombie_horizontal.xPos + 1][zombie_horizontal.yPos] != '#' && maze[zombie_horizontal.xPos + 1][zombie_horizontal.yPos] != '|')
			{
				maze[zombie_horizontal.xPos][zombie_horizontal.yPos] = ' ';
				zombie_horizontal.xPos += 1;
			}

			break;

		case 2:
			if (maze[zombie_horizontal.xPos - 1][zombie_horizontal.yPos] != '#' && maze[zombie_horizontal.xPos - 1][zombie_horizontal.yPos] != '|')
			{
				maze[zombie_horizontal.xPos][zombie_horizontal.yPos] = ' ';
				zombie_horizontal.xPos -= 1;
			}

			break;
		}

		//This zombie goes only down a hallway
		if (maze[zombie_vertical.xPos][zombie_vertical.yPos + 1] != '#')
		{
			maze[zombie_vertical.xPos][zombie_vertical.yPos] = ' ';
			zombie_vertical.yPos += 1;
		}
		else if (maze[zombie_vertical.xPos][zombie_vertical.yPos - 5] != '#')
		{
			maze[zombie_vertical.xPos][zombie_vertical.yPos] = ' ';
			zombie_vertical.yPos -= 6;
		}

		//This zombie goes through objects to throw off the player.
		if (maze[zombie_jumper.xPos + 2][zombie_jumper.yPos] != '#' && maze[zombie_jumper.xPos + 2][zombie_jumper.yPos] != '|')
		{
			maze[zombie_jumper.xPos][zombie_jumper.yPos] = ' ';
			zombie_jumper.xPos += 2;
		}
		else if (maze[zombie_jumper.xPos - 14][zombie_jumper.yPos] != '#')
		{
			maze[zombie_jumper.xPos][zombie_jumper.yPos] = ' ';
			zombie_jumper.xPos -= 14;
		}

		//This will constantly update the map
		if (refresh == true)
		{
			system("CLS");

			//We will update the zombies
			maze[zombie_horizontal.xPos][zombie_horizontal.yPos] = zombie_horizontal.iconZombie;
			maze[zombie_vertical.xPos][zombie_vertical.yPos] = zombie_vertical.iconZombie;
			maze[zombie_jumper.xPos][zombie_jumper.yPos] = zombie_jumper.iconZombie;

			//We will update the hero
			maze[hero.xPos][hero.yPos] = hero.icon;

			for (int y = 0; y < HEIGHT; y++)
			{
				cout << endl;

				for (int x = 0; x < WIDTH; x++)
				{

					cout << maze[x][y];

				}

			}
			//Let's display our hero's HP for the player
			playerUI();
			refresh = false;

			//LOSE CONDITION: If player's HP goes down to 0, the game will end.
			if (hero.hp == 0)
			{
				move_key = 'q';
				endingBad();
				endingCredits();
			}

			//WIN CONDITION: If player has HP and reaches the bottom of the map, the game will end.
			if (hero.yPos == 17)
			{
				endingGood();
				endingCredits();
				coinCount();
				cout << "Press [Q] to quit the program." << endl;
			}
		}

	}//The game loop ends here

	return 0;
}


//EXTRA NOTES:
/*

THIS SHOULD OPEN THE MP3. THE * is the file name
mciSendString("open \"*.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);

THIS REPLAYS THE SONG IN A LOOP
mciSendString("play mp3 repeat", NULL, 0, NULL);

THIS PAUSES THE MP3
mciSendString("pause mp3", NULL, 0, NULL);

THIS RESUMES THE MP3
mciSendString("resume mp3", NULL, 0, NULL);

THIS CLOSES THE MP3
mciSendString("close mp3", NULL, 0, NULL);

*/