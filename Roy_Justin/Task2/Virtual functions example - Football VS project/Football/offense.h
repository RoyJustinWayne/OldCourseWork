/*
* Header for the offense class, this should include yards gained, 
* minutes played and printing starts. 
*
* Will use Name from the base class.
* 
* Justin Roy CSC 4111 Task 2
*/

#include "player.h"
using namespace std;
//Had to make changes to my naming convention (I wouldn't use lowercase name for file and uppercase for class, but main.CPP chose upper).
class Offense : public Player
{
public:
	Offense(string name);
	virtual void setMinutesPlayed(int minutes);
	void setYards(int yards);
	virtual void printStats() const;

private:

	int yards;
};
