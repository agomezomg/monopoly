#pragma once
#include "Propiedades.h"
#include "Table."
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::stringstream;
using std::string;

class Player : public Table
{
protected:
	vector<Propiedades*> properties;
	string name;
	bool inJail = false;
	int moneyOwned;
	int position;
	bool getOutJail;

	int turnControl;
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

//-------------------------------------------------------------------------------------------------------------------------
	int Player::getTurnControl();
	void Player::setTurnControl(int);

};