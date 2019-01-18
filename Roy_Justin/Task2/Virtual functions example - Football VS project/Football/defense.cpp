/*
* Implementation for the defense class, this should include tackles made,
* minutes played and printing starts.
*
* Will use Name from the base class.
*
* Justin Roy CSC 4111 Task 2
*/

#include "defense.h"

//Had to make changes to my naming convention (I wouldn't use lowercase name for file and uppercase for class, but main.CPP chose upper).

Defense::Defense(string name) : Player(name)
{
	//base class.
}

void Defense::setMinutesPlayed(int minutes)
{
	//set Minutes.
	this->minutes = minutes;
}


void Defense::setTackles(int tackles)
{
	//set Tackles.
	this->tackles = tackles;
}

void Defense::printStats() const
{
	//Print
	Player::printStats();
	cout << "\tMinutes: " << minutes << "\tTackles: " << tackles << endl;

}