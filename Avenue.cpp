#include "Avenue.h"
#include "Table.h"
#include "Properties.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>

using std::string;
using std::stringstream;

Avenue::Avenue() {

}

Avenue::~Avenue() {

}

string Avenue::getTitle() {
	return this -> title;
}

void Avenue::setTitle() {
	this -> title = title;
}

int Avenue::getHouses() {
	return this -> houses;
}

void Avenue::setHouses() {
	this -> houses = houses;
}

string Avenue::toString() {
	stringstream ss;
	ss << title;
	return ss.str();
}

void Avenue::drawItem(int space) {
  
}