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

void Player::setPosition(int position) {
	this -> position = position;
}

void Player::setTurnControl(int spaces){
	if((this -> turnControl + turnControl) >= 40){
		int temp =(this -> turnControl + turnControl) - 40 ;
		this -> turnControl = temp;
		this -> moneyOwned += 200;
	} else {
		this -> turnControl += turnControl;
	}
}

string Player::toString() {
	stringstream ss;
	ss << "Name: " << name << " you have $" << moneyOwned << " and you are in square: " << turnControl;
return ss.str();
}