#include "Player.h"

Player::Player() {

}

Player::Player(string name, int moneyOwned) : name(name), moneyOwned(moneyOwned) {
	this -> inJail = false;
	this -> getOutJail = false;
}

Player::~Player() {

}

string Player::getName() {
	return this -> name;
}

void Player::setName(string name) {
	this -> name = name;
}

int Player::getPosition() {
	return this -> position;
}

void Player::TurnControl(int spaces){
	if((this -> spaces + spaces) >= 40){ //if number of spaces moved is >= 40 
		int temp =(this -> spaces + spaces) - 40 ;
		this -> spaces = temp;
		this -> moneyOwned += 200;
	} else {
		this -> spaces += spaces;
	}
}

string Player::toString() {
	stringstream ss;
	ss << "Name: " << name << " you have $" << moneyOwned << " and you are in square: " << spaces;
return ss.str();
}