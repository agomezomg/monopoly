#include "Table.h"
#include <sstream>
#include <string>
#include "Properties.h"

using std::string;
using std::stringstream;

Properties::Properties() {
	this -> owned = false;
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
	if (space == 1) {
	
	} else if (space == 2) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
		this -> color = "brown";
	} else if (space == 3) {
		this -> title = "Community Chest";
		this -> price = 0;
		this -> color = "white";
	} else if (space == 4) {
		this -> title = "Baltic Avenue";
		this -> price = 60;
	} else if (space == 5) {
		this -> title = "Income tax";
		this -> price = -200;
	} else if (space == 6) {
		this -> title = "Reading Railroad";
		this -> price = 200;
	} else if (space == 7) {
		this -> title = "Oriental Avenue";
		this -> price = 100;
	} else if (space == 8) {
		this -> title = "CHANCE";
		this -> price = 0;
		this -> color = "CHANCE";
	} else if (space == 9) {
		this -> title = "Vermont Avenue";
		this -> price = 100;
		this -> color = "Light Blue";
	} else if (space == 10) {
		this -> title = "";
		this -> price = 60;
	} else if (space == 11) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 12) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 13) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 14) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 15) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 16) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 17) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 18) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 19) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 20) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 21) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 22) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 23) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 24) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 25) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 26) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 27) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 28) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 29) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 30) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 31) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 32) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 33) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 34) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 35) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 36) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 37) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 38) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else if (space == 39) {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	} else {
		this -> title = "Mediterranean Avenue";
		this -> price = 60;
	}
}

string Properties::toString() { //pending
	stringstream ss;
	ss << title << ", $" << price;
	return ss.str();
}

void Properties::drawItem(int space) {

}