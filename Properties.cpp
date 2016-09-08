#include "Table.h"
#include <sstream>
#include <string>
#include <ncurses.h>
#include "Properties.h"

using std::string;
using std::stringstream;

Properties::Properties() {
	this -> owned = false;
	this -> mortgage = 0;
	this -> color = "any";
}

Properties::~Properties() {

}

int Properties::getPrice() {
	return this -> price;
}

void Properties::setPrice(int price) {
	this -> price = price;
}

int Properties::getRent() {
	return this -> rent;
}

void Properties::setRent(int rent) {
	this -> rent = rent;
}

int Properties::getSalePrice() {
	return this -> sale;
}

void Properties::setSalePrice(int sale) {
	this -> sale = sale;
}

bool Properties::getOwned() {
	return this -> owned;
}

void Properties::setOwned(bool owned) {
	this -> owned = owned;
}

int Properties::getMortgage() {
	return this -> mortgage;
}

void Properties::setMortgage(int mortgage) {
	this -> mortgage = mortgage;
}

string Properties::getColor() {
	return this -> color;
}

void Properties::setColor(string color) {
	this -> color = color;
}

void Properties::setAll(int space) {
	if (space == 0) {
		this -> title = "GO";
		this -> price = -200;
		this -> color = "GO";
	} else if (space == 1) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
		this -> color = "brown";
	} else if (space == 2) {
		this -> title = "Community Chest";
		this -> price = 0;
		this -> color = "Community Chest";
	} else if (space == 3) {
		this -> title = "Baltic Avenue";
		this -> price = 60;
		this -> color = "brown";
	} else if (space == 4) {
		this -> title = "Income Tax";
		this -> price = -200;
		this -> color = "Tax";
	} else if (space == 5) {
		this -> title = "Reading Railroad";
		this -> price = 200;
		this -> color = "Railroad";
	} else if (space == 6) {
		this -> title = "Oriental Avenue";
		this -> price = 100;
		this -> color= "Light Blue";
	} else if (space == 7) {
		this -> title = "CHANCE";
		this -> price = 0;
		this -> color = "CHANCE";
	} else if (space == 8) {
		this -> title = "Vermont Avenue";
		this -> price = 100;
		this -> color = "Light Blue";
	} else if (space == 9) {
		this -> title = "Conneticut Avenue";
		this -> price = 120;
		this -> color = "Light Blue";
	} else if (space == 10) {
		this -> title = "In Jail/Just Visiting";
		this -> price = 0;
		this -> color = "Jail";
	} else if (space == 11) {
		this -> title = "St. Charle's Place";
		this -> price = 140;
		this -> color = "Deep Purple";
	} else if (space == 12) {
		this -> title = "Electric Company";
		this -> price = 150;
		this -> color = "Lightbulb";
	} else if (space == 13) {
		this -> title = "States Avenue";
		this -> price = 140;
		this -> color = "Deep Purple";
	} else if (space == 14) {
		this -> title = "Virgina Avenue";
		this -> price = 160;
	} else if (space == 15) {
		this -> title = "Pennsylvania Railroad";
		this -> price = 200;
		this -> color = "Railroad";
	} else if (space == 16) {
		this -> title = "St. James Places";
		this -> price = 180;
		this -> color = "Orange";
	} else if (space == 17) {
		this -> title = "Community Chest";
		this -> price = 0;
		this -> color = "Community Chest";
	} else if (space == 18) {
		this -> title = "Tennessee Avenue";
		this -> price = 180;
		this -> color = "Orange";
	} else if (space == 19) {
		this -> title = "New York Avenue";
		this -> price = 200;
		this -> color = "Orange";
	} else if (space == 20) {
		this -> title = "Free Parking";
		this -> price = 0;
		this -> color = "Free Parking";
	} else if (space == 21) {
		this -> title = "Kentucky Avenue";
		this -> price = 220;
		this -> color = "Red";
	} else if (space == 22) {
		this -> title = "CHANCE";
		this -> price = 0;
		this -> color = "CHANCE";
	} else if (space == 23) {
		this -> title = "Indiana Avenue";
		this -> price = 220;
		this -> color = "Red";
	} else if (space == 24) {
		this -> title = "Illinois Avenue";
		this -> price = 240;
		this -> color = "Red";
	} else if (space == 25) {
		this -> title = "B. & O. Railroad";
		this -> price = 200;
		this -> color = "Railroad";
	} else if (space == 26) {
		this -> title = "Atlantic Avenue";
		this -> price = 260;
		this -> color = "Yellow";
	} else if (space == 27) {
		this -> title = "Ventor Avenue";
		this -> price = 260;
		this -> color = "Yellow";
	} else if (space == 28) {
		this -> title = "Water Works";
		this -> price = 150;
		this -> color = "Water Works";
	} else if (space == 29) {
		this -> title = "Marvin Gardens";
		this -> price = 280;
		this -> color = "Yellow";
	} else if (space == 30) {
		this -> title = "Go To Jail";
		this -> price = -30;
		this -> color = "Go To Jail";
	} else if (space == 31) {
		this -> title = "Pacific Avenue";
		this -> price = 300;
		this -> color = "Green";
	} else if (space == 32) {
		this -> title = "North Carolina Avenue";
		this -> price = 300;
		this -> color = "Green";
	} else if (space == 33) {
		this -> title = "Community Chest";
		this -> price = 0;
		this -> color = "Community Chest";
	} else if (space == 34) {
		this -> title = "Pennsylvania Avenue";
		this -> price = 320;
		this -> color = "Green";
	} else if (space == 35) {
		this -> title = "Short Line";
		this -> price = 200;
		this -> color = "Railroad";
	} else if (space == 36) {
		this -> title = "CHANCE";
		this -> price = 0;
		this -> color = "CHANCE";
	} else if (space == 37) {
		this -> title = "Park Place";
		this -> price = 350;
		this -> color = "Blue";
	} else if (space == 38) {
		this -> title = "Luxury Tax";
		this -> price = 100;
		this -> color = "Tax";
	} else if (space == 39) {
		this -> title = "Boardwalk";
		this -> price = 400;
		this -> color = "Blue";
	}else {
		this -> title = "GO";
		this -> price = -200;
		this -> color = "GO";
	}
}

string Properties::toString() { //pending
	stringstream ss;
	ss << title << ", $" << price;
	return ss.str();
}

void Properties::setDeduction(int deduction) {
	this -> deduction = deduction;
}

int Properties::getDeduction() {
	return this -> deduction;
}

void Properties::drawItem(int space) {
	//do nothing
}