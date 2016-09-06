#include "Table.h"
#include <sstream>
#include <string>
#include "Properties.h"

Properties::Properties() {
	this -> owned = false;
}

Properties::~Properties() {

}

void Properties::setPrice(int price) {
	this -> price = price;
}

int Properties::getPrice() {
	return this -> price;
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
	return color;
}

void Properties::setColor(string color) {
	this -> color = color;
}

int Properties::getPosition() {
	return this -> position;
}

void Properties::setPosition(int position) {
	this -> position = position;
}