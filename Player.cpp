#include "Player.h"
using namespace std;
#include <iostream>

Player::Player() {

}

Player::Player(string name, int moneyOwned) : name(name), moneyOwned(moneyOwned) {
	this -> inJail = false;
	this -> getOutJail = false;
	this -> moneyOwned = 2000;
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
	return this -> spaces;
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

int Player::getMoneyOwned(){
	return this->moneyOwned;
}

void Player::setMoneyOwned(int Price){
	this->moneyOwned=this->moneyOwned-Price;
}

void Player::setMoney_Owned(int Price){
	this->moneyOwned=this->moneyOwned+Price;
}
void Player::setProperties(Properties* Properties){
	this->properties.push_back(Properties);
}

string Player::getProperties(){
	stringstream ss;
	ss<<"\n       Your Properties     \n";
	for (int i = 0; i < properties.size(); ++i)
		{
			ss<<"     "<<properties.at(i)->toString()<<"\n";
		}	
return ss.str();
}

bool Player::validarProperties(string Nombre){
	for (int i = 0; i < properties.size(); ++i)
	{
		if (properties.at(i)->getTitle()==Nombre)
		{
			return true;
		}
	return false;
	}
}

