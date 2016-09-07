#include "Railway.h"
#include "Table.h"
#include "Properties.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>

using std::string;
using std::stringstream;

Railway::Railway() {

}

Railway::~Railway() {

}

string Railway::getTitle() {
	return this -> title;
}

void Railway::setTitle() {
	this -> title = title;
}

int Railway::getRailway() {
	return this -> railway;
}

void Railway::setRailway() {
	this -> railway = railway;
}

string Railway::toString() {
	stringstream ss;
	ss << title;
	return ss.str();
}