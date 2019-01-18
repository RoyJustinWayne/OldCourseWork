/*
* Header for the defense class, this should include tackles made,
* minutes played and printing starts.
*
* Will use Name from the base class.
*
* Justin Roy CSC 4111 Task 2
*/

#include "player.h"

//Had to make changes to my naming convention (I wouldn't use lowercase name for file and uppercase for class, but main.CPP chose upper).
using namespace std;
class Defense : public Player
{
public:
	Defense(string name);
	virtual void setMinutesPlayed(int minutes);
	void setTackles(int tackles);
	virtual void printStats() const;

private:

	int tackles;
};
