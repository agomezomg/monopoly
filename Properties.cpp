#include "Table.h"
#include <sstream>
#include <string>
#include "Properties.h"

Properties::Properties() {

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
	return color;
}

void Properties::setColor() {
	this -> color = color;
}