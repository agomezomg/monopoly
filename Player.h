#pragma once
#include "Table.h"
#include "Propiedades.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::stringstream;
using std::string;

class Player
{
protected:
	vector<Propiedades*> properties;
	string name;
	bool inJail = false;
	int moneyOwned;
	int position;
	bool getOutJail;
public:
	Player();
	~Player();
	Player(string, moneyOwned); //player name or piece name
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
};