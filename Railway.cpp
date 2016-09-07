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
void Railway::drawItem(int space){
	string linea;
	if(space == 5){
		linea = "*   B. & O. Railroad       *";
	}else if(space == 15)
		linea = "*   Short Line R. R.       *";
	else if(space == 25)
		linea = "*   Reading Railroad       *";
	else if(space == 35)
		linea = "*   Pennsylvania R. R.     *";
	
	init_pair(1,COLOR_BLACK,COLOR_WHITE);
	attron(COLOR_PAIR(1));
	mvprintw(10,20,"****************************\n");
	mvprintw(11,20,"*        ***    ***        *\n");
	mvprintw(12,20,"*        *      **         *\n");
	mvprintw(13,20,"*        **********        *\n");
	mvprintw(14,20,"*       ************       *\n");
	mvprintw(15,20,"*        **********        *\n");
	mvprintw(16,20,"*         **    **         *\n");
	mvprintw(17,20,linea.c_str());
	mvprintw(18,20,"*    Rent ------>   $25    *\n");
	mvprintw(19,20,"* If 2 are owned--> $50    *\n");
	mvprintw(20,20,"* If 3 are owned-->$100    *\n");
	mvprintw(21,20,"* If 4 are owned-->$150    *\n");
	mvprintw(22,20,"*                          *\n");
	mvprintw(23,20,"* Mortgage Value ---> $100 *\n");
	mvprintw(24,20,"****************************\n");
	
	attroff(COLOR_PAIR(1));
}