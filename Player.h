#pragma once
#include "Properties.h"
#include "Avenue.h"
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
	bool getOutJail;
	int spaces;
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
	void setMoney_Owned(int);
	int getPosition();
	void setPosition(int);
	bool canGetOutJail();
	void setCanGetOutJail();
	string toString();
	string toString(int);
	void TurnControl(int);
	string getProperties();
	string getProperties(int);
	void setProperties(Properties*);
	bool validarProperties(string);
	bool canBuildOnLot(int);
	void sellProperty(int);
	Player* removeProperty(Player*, Properties*);
	Properties* mortgageProperty(Properties*);
	Properties* payMortgage(int, Properties*);
};