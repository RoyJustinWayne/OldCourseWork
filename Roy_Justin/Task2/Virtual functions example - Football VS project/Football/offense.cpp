/*
* Implementation for the offense class, this should include yards gained,
* minutes played and printing starts.
*
* Will use Name from the base class.
*
* Justin Roy CSC 4111 Task 2
*/

#include "offense.h"

//Had to make changes to my naming convention (I wouldn't use lowercase name for file and uppercase for class, but main.CPP chose upper).
Offense::Offense(string name) : Player(name)
{
	//base class.
}

void Offense::setMinutesPlayed(int minutes)
{
	//set Minutes.
	this->minutes = minutes;
}

void Offense::setYards(int yards)
{
	//set Yards.
	this->yards = yards;
}

void Offense::printStats() const
{
	//Print
	Player::printStats();
	cout << "\tMinutes: " << minutes << "\tYards: " << yards << endl;
}
