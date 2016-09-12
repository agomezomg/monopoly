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

bool Player::canBuildOnLot(Avenue* hereWeGoAgain) {
	Avenue* temporary;
	string toCheck = hereWeGoAgain -> getColor();
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
		temporary = dynamic_cast<Avenue*>(properties.at(i));
		if (((toCheck == "Brown") && (properties.at(i) -> getColor() == toCheck)))
		{
			brown++;
			if (brown == 2 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
		} else if ((toCheck == "Light Blue") && (properties.at(i) -> getColor() == toCheck))
		{
			if (lightBlue == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			lightBlue++;
		} else if ((toCheck == "Pink") && (properties.at(i) -> getColor() == toCheck))
		{
			if (pink == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			pink++;
		} else if ((toCheck == "Orange") && (properties.at(i) -> getColor() == toCheck))
		{
			if (orange == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			} 
			orange++;
		} else if ((toCheck == "Red") && (properties.at(i) -> getColor() == toCheck))
		{
			if (red == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			red++;
		} else if ((toCheck == "Yellow") && (properties.at(i) -> getColor() == toCheck))
		{
			if (yellow == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			yellow++;
		} else if ((toCheck == "Green") && (properties.at(i) -> getColor() == toCheck))
		{
			if (green == 3 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			green++;
		} else if ((toCheck == "Dark Blue") && (properties.at(i) -> getColor() == toCheck))
		{
			if (darkBlue == 2 && temporary -> getHouses() <= hereWeGoAgain -> getHouses())
			{
				properties.at(i) -> setRent(properties.at(i) -> getRent() * 2);
				return true;
			}
			darkBlue++;
		}
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

Properties* Player::mortgageProperty(Properties* ugh) {
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

    this -> moneyOwned += ugh -> getMortgage();
    ugh -> setRent(0);

    return ugh;
}

void Player::payMortgage(Properties* mortgagedP, int mortgageDue) {
	for (int i = 0; i < properties.size(); ++i)
	{
		if (mortgagedP -> getTitle() == properties.at(i) -> getTitle())
		{
			this -> properties.at(i) -> setMortgage(0);
		}
	}

	this -> moneyOwned = moneyOwned - mortgageDue;
	mortgagedP -> setMortgage(0);
}

Avenue* Player::buildOnLot(Avenue* p) {
	this -> moneyOwned = moneyOwned - p -> getHousePrice();
	p -> setHouses(p -> getHouses() + 1);
	p -> setRent(p -> getRent());
	
	return p;
}