#pragma once
#include "Properties.h"
#include "Table.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::stringstream;
using std::string;

class Player 
{
protected:
	vector<Properties*> properties;
	string name;
	bool inJail;
	int moneyOwned;
	int position;
	bool getOutJail;

	int turnControl;
public:
	Player();
	~Player();
	Player(string, int); //player name or piece name, money owned
	string getName();
	void setName(string);
	bool checkInJail();
	void setInJail(bool);
	int getMoneyOwned();
	void setMoneyOwned(int);
	int getPosition();
	void setPosition(int);
	bool canGetOutJail();
	void setCanGetOutJail();
	string toString();
	int getTurnControl();
	void setTurnControl(int);

};