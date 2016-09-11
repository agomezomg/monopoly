#include "Player.h"
#include "Properties.h"
#include "Avenue.h"
using namespace std;
#include <iostream>

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
	return this -> spaces;
}

void Player::TurnControl(int spaces) {
	if((this -> spaces + spaces) >= 40) { //if number of spaces moved is >= 40 
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
string Player::toString(int SobreCarga) {
	stringstream ss;
	ss << name << " " << moneyOwned <<" " << spaces;
	return ss.str();
}

int Player::getMoneyOwned() {
	return this->moneyOwned;
}

void Player::setMoneyOwned(int Price) {
	this -> moneyOwned = this -> moneyOwned - Price;
}

void Player::setMoney_Owned(int Price){
	this -> moneyOwned = this -> moneyOwned + Price;
}
void Player::setProperties(Properties* Properties){
	this -> properties.push_back(Properties);
}

string Player::getProperties() {
	stringstream ss;
	ss << "\n       Your Properties     \n";
	
	for (int i = 0; i < properties.size(); ++i)
	{
		ss << "     " << properties.at(i) -> toString() << "\n";
	}
	return ss.str();
}
string Player::getProperties(int SobreCarga) {
	stringstream ss;
	for (int i = 0; i < properties.size(); ++i)
	{
		ss<< properties.at(i)->getTitle()<<"\n";
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
	}

	return false;
}

void Player::setInJail(bool inJail){
	this -> inJail = inJail;
}

bool Player::checkInJail(){
	return this -> inJail;
}

void Player::setPosition(int NewPosition){
	this -> spaces = NewPosition;
}

bool Player::canBuildOnLot(int position) {
	string toCheck = properties.at(position) -> getColor();
	int brown = 0;
	int lightBlue = 0;
	int pink = 0;
	int orange = 0;
	int red = 0;
	int yellow = 0;
	int green = 0;
	int darkBlue = 0;

	for (int i = 0; i < properties.size(); ++i)
	{
		if ((toCheck == "Brown") && (properties.at(i) -> getColor() == toCheck))
		{
			brown++;
		} else if ((toCheck == "Light Blue") && (properties.at(i) -> getColor() == toCheck))
		{
			lightBlue++;
		} else if ((toCheck == "Pink") && (properties.at(i) -> getColor() == toCheck))
		{
			pink++;
		} else if ((toCheck == "Orange") && (properties.at(i) -> getColor() == toCheck))
		{
			orange++;
		} else if ((toCheck == "Red") && (properties.at(i) -> getColor() == toCheck))
		{
			red++;
		} else if ((toCheck == "Yellow") && (properties.at(i) -> getColor() == toCheck))
		{
			yellow++;
		} else if ((toCheck == "Green") && (properties.at(i) -> getColor() == toCheck))
		{
			green++;
		} else if ((toCheck == "Dark Blue") && (properties.at(i) -> getColor() == toCheck))
		{
			darkBlue++;
		}
	}

	if (brown == 2)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (lightBlue == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (pink == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (orange == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (red == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (yellow == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (green == 3)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	} else if (darkBlue == 2)
	{
		properties.at(position) -> setRent(properties.at(position) -> getRent() * 2);
		return true;
	}
	
	return false;
}

void Player::sellProperty(int position) {
	this -> properties.erase(properties.begin() + position);
}

Player* Player::removeProperty(Player* p, Properties* agh) {
	bool canErase = false;
	int qualifier;
	for (int i = 0; i < properties.size(); ++i)
	{
		if (properties.at(i) -> getTitle() == agh -> getTitle())
		{
			qualifier = i;
			canErase = true;
		}
	}

	if (canErase)
	{
		p -> sellProperty(qualifier);
	}

	return p;
}

Player* Player::mortgageProperty(Player* p, Properties* ugh) {
	/*if (ugh -> getTitle() == "Mediterranean Avenue")
    {
        ugh -> setMortgage((ugh -> getPrice() / 2));
    } else if (ugh -> getTitle() == "Baltic Avenue")
    {
    	ugh -> setMortgage((ugh -> getPrice() / 2));
    } else if (ugh -> getTitle() == "Oriental Avenue")
    {

    } else if (ugh -> getTitle() == "Vermont Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Connecticut Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "St. Charles Place")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "States Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Virginia Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "St. James Place")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Tennessee Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "New York Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Kentucky Avenue")
    {
		ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Indiana Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Illinois Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Atlantic Avenue")
    {
        ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Ventnor Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Marvin Gardens")
    {
		ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Pacific Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "North Carolina Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Pennsylvania Avenue")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Park PLace")
    {
    	ugh -> setMortgage(30);
    } else if (ugh -> getTitle() == "Boardwalk")
    {
    	ugh -> setMortgage(30);
    } //else esa papada no existe*/

    ugh -> setMortgage((ugh -> getPrice() / 2));

    for (int i = 0; i < properties.size(); ++i)
    {
    	if (ugh -> getTitle() == properties.at(i) -> getTitle())
    	{
    		this -> properties.at(i) -> setMortgage(ugh -> getMortgage());
    	}
    }
}

void Player::payMortgage(int payM, Properties* mortgagedP) {
	for (int i = 0; i < properties.size(); ++i)
	{
		if (mortgagedP -> getTitle() == properties.at(i) -> getTitle())
		{
			this -> properties.at(i) -> setMortgage(0);
		}
	}

	this -> moneyOwned = ((mortgagedP -> getMortgage()) * 0.1) + mortgagedP -> getMortgage();
}