#pragma once
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

/*
struct player
{
	string name;
	int xPos;						//X coordinates
	int yPos;						//Y coordinates
	char icon;
	int hp;
	int coins;
};
*/
class Character
{
public:
	//Public Variables
	string userInput;


	//Functions listed
	void nameChar();

};

void Character::nameChar()
{

	cout << "What is the name of this potential lost soul?" << endl;
	cin >> userInput;
	//player.name() = userInput;


}