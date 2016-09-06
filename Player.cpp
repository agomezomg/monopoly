#include "Table.h"
#include "Player.h"

Player::Player() {

}

Player::Player(string name, int moneyOwned) : name(name), moneyOwned(moneyOwned) {

}

Player::~Player() {

}



void Player::setTurnControl(int turnControl){
	if((this -> turnControl + turnControl) >= 40){
		int temp =(this -> turnControl + turnControl) - 40 ;
		this -> turnControl = temp;
		this -> moneyOwned += 200;
	} else {
		this -> turnControl += turnControl;
	}
}

Player::toString() {
	stringstream ss;
	ss << "Name: " << name << " you have $" << moneyOwned << " and you are in the square " << turn;
return ss.str();
}