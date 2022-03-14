#pragma once
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

//------------------------------------------------------//
/*
Here we will put the text files that will display on the screen. 
*/

//The intro to set the mood a bit.
void intro()
{
	cout << "You wake up to the sound of lightning. As you open your eyes, you awaken in the dark. " << endl;
	cout << "You notice a flashlight on the ground and turn it on. You see three zombies in front " << endl;
	cout << "you and you run screaming. Without noticing you are at the corner of the house. " << endl;

	cout << "You can't stay here. You gotta get out. You hear rummaging through the house. " << endl;
	cout << "Guess you gotta make it out alive and not become one of those...THINGS." << endl;
	cout << "--------------------------------------------------------------" << endl;
}

//If the player reaches the end of the map, they escape and win. Trigger win conditions
void endingGood()
{
	cout << endl;
	cout << " As you escape the house, you turn around to gaze upon the horrid place once more." << endl;
	cout << " But as you look behind at the house, it starts to fade into the hazy mist." << endl;
	cout << "It's almost like if it never happenned. You walk to your car and the experience escapes your mind. " << endl;
	cout << endl;
}

//If the player gets bitten too many times by a zombie, then it is game over.
void endingBad()
{
	cout << endl;
	cout << "           GAME OVER             " << endl;
	cout << "The zombies have overtaken you and munched on your brain. You now join the undead locked into this house." << endl;
}

//Credits for acknoledgments.
void endingCredits()
{
	cout << endl;
	cout << "//--------------------------------------------------------------------------//" << endl;
	cout << "|                         GENERIC CREDIT STUFF                              |" << endl;
	cout << "|                         --------------------                              |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                          Player - YOU                                     |" << endl;
	cout << "|                          Zombie 1 - Juan                                  |" << endl;
	cout << "|                          Zombie 2 - Nico                                  |" << endl;
	cout << "|                          Zombie 3 - Tommy Wiseu                           |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                              Created by:                                  |" << endl;
	cout << "|                             Ethan Letrong                                 |" << endl;
	cout << "|                               890390305                                   |" << endl;
	cout << "|                          CPSC 386 Maze Game                               |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "|                                                                           |" << endl;
	cout << "//--------------------------------------------------------------------------//" << endl;

}

void easterEgg()
{
	cout << "You feel a jingle in your pocket. You pull out 5 gold coins which illuminate in your hands. " << endl;
	cout << "The lights focus on one point in the ground. Soon after it burst with lights and surges with electricity. " << endl;
	cout << "The light fades away. Moments later an arm comes sprouting out of the ground. You jump back in fright. " << endl;
	cout << "The arm digs itself out and the shadowy figure emerges from the ground. But can it be?! " << endl;
	cout << "The figure has long wavy hair. The being that exists in front of you is....Tommy Wiseu!? " << endl;
	cout << "Tommy says with a whismical smile...." << endl;
	cout << " Oh Hai Mark~" << endl;
}
