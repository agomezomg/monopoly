#include "Table.h"
#include "Player.h"

Player::toString() {
	stringstream ss;
	ss << "Name: " << name << " you have $" << moneyOwned << " and you are in the square " << turn;
return ss.str();
}