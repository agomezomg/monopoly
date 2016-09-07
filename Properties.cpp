#include "Table.h"
#include <sstream>
#include <string>
#include <ncurses.h>
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
    string linea[15];
    linea[0] = "***********************\n";
    linea[2] = "***********************\n";
    linea[3] = "*                     *\n";
    linea[5] = "*                     *\n"; 
    linea[11] = "*                     *\n";
    linea[13] = "*                     *\n";  
    linea[14] = "***********************\n";
   
    if (space == 2){
    	init_color(COLOR_RED, 141, 73, 37);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*  Mediterranean Ave. *\n";
    	linea[4] = "*        Rent $2      *\n";
    	linea[6] = "*  1 house --->   $10 *\n";
    	linea[7] = "*  2 houses--->   $30 *\n";
    	linea[8] = "*  3 houses--->   $90 *\n";
    	linea[9] = "*  4 houses--->  $160 *\n";
    	linea[10] = "*  hotel------>  $250 *\n";
    	linea[12] = "*  Mortgage Value $30 *\n";
    }else if (space == 4){
    	init_color(COLOR_RED, 141, 73, 37);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*    Baltic Avenue    *\n";
    	linea[4] = "*        Rent $4      *\n";
    	linea[6] = "*  1 house --->   $20 *\n";
    	linea[7] = "*  2 houses--->   $60 *\n";
    	linea[8] = "*  3 houses--->  $180 *\n";
    	linea[9] = "*  4 houses--->  $320 *\n";
    	linea[10] = "*  hotel------>  $450 *\n";
    	linea[12] = "*  Mortgage Value $30 *\n";
    }else if (space == 7){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Oriental Avenue   *\n";
    	linea[4] = "*        Rent $6      *\n";
    	linea[6] = "*  1 house --->   $30 *\n";
    	linea[7] = "*  2 houses--->   $90 *\n";
    	linea[8] = "*  3 houses--->  $270 *\n";
    	linea[9] = "*  4 houses--->  $400 *\n";
    	linea[10] = "*  hotel------>  $550 *\n";
    	linea[12] = "*  Mortgage Value $50 *\n";
    }else if (space == 9){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Vermont Avenue    *\n";
    	linea[4] = "*        Rent $6      *\n";
    	linea[6] = "*  1 house --->   $30 *\n";
    	linea[7] = "*  2 houses--->   $90 *\n";
    	linea[8] = "*  3 houses--->  $270 *\n";
    	linea[9] = "*  4 houses--->  $400 *\n";
    	linea[10] = "*  hotel------>  $550 *\n";
    	linea[12] = "*  Mortgage Value $50 *\n";
    }else if (space == 10){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "* Connecticut Avenue  *\n";
    	linea[4] = "*        Rent $8      *\n";
    	linea[6] = "*  1 house --->   $40 *\n";
    	linea[7] = "*  2 houses--->  $100 *\n";
    	linea[8] = "*  3 houses--->  $300 *\n";
    	linea[9] = "*  4 houses--->  $450 *\n";
    	linea[10] = "*  hotel------>  $600 *\n";
    	linea[12] = "*  Mortgage Value $60 *\n";
    }else if (space == 12 || space == 14){
    	init_color(COLOR_RED, 400, 50, 150);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 12)linea[1] = "*  St. Charles Palce  *\n";
    	if (space == 14)linea[1] = "*    States Avenue    *\n";
    	linea[4] = "*       Rent $10      *\n";
    	linea[6] = "*  1 house --->   $50 *\n";
    	linea[7] = "*  2 houses--->  $150 *\n";
    	linea[8] = "*  3 houses--->  $450 *\n";
    	linea[9] = "*  4 houses--->  $650 *\n";
    	linea[10] = "*  hotel------>  $750 *\n";
    	linea[12] = "*  Mortgage Value $70 *\n";
    }else if (space == 15){
    	init_color(COLOR_RED, 400, 50, 150);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Virginia Avenue   *\n";
    	linea[4] = "*       Rent $12      *\n";
    	linea[6] = "*  1 house --->   $60 *\n";
    	linea[7] = "*  2 houses--->  $180 *\n";
    	linea[8] = "*  3 houses--->  $500 *\n";
    	linea[9] = "*  4 houses--->  $700 *\n";
    	linea[10] = "*  hotel------>  $900 *\n";
    	linea[12] = "*  Mortgage Value $80 *\n";
    }else if (space == 17 || space == 19){
    	init_color(COLOR_RED, 280, 220, 80);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 17)linea[1] = "*   ST. James Place   *\n";
    	if (space == 19)linea[1] = "*  Tennessee Avenue   *\n";	
    	linea[4] = "*       Rent $14      *\n";
    	linea[6] = "*  1 house --->   $70 *\n";
    	linea[7] = "*  2 houses--->  $200 *\n";
    	linea[8] = "*  3 houses--->  $550 *\n";
    	linea[9] = "*  4 houses--->  $750 *\n";
    	linea[10] = "*  hotel------>  $950 *\n";
    	linea[12] = "*  Mortgage Value $90 *\n";
    }else if (space == 20){
    	init_color(COLOR_RED, 280, 220, 80);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   New York Avenue   *\n";
    	linea[4] = "*       Rent $16      *\n";
    	linea[6] = "*  1 house --->   $80 *\n";
    	linea[7] = "*  2 houses--->  $220 *\n";
    	linea[8] = "*  3 houses--->  $600 *\n";
    	linea[9] = "*  4 houses--->  $800 *\n";
    	linea[10] = "* hotel------>  $1000 *\n";
    	linea[12] = "* Mortgage Value $100 *\n";
    }else if (space == 22 || space ==24){
    	init_color(COLOR_RED, 700,0,0);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 22)linea[1] = "*   Kentucky Avenue   *\n";
        if (space == 24)linea[1] = "*    Indiana Avenue   *\n";
    	linea[4] = "*       Rent $18      *\n";
    	linea[6] = "*  1 house --->   $90 *\n";
    	linea[7] = "*  2 houses--->  $250 *\n";
    	linea[8] = "*  3 houses--->  $700 *\n";
    	linea[9] = "*  4 houses--->  $875 *\n";
    	linea[10] = "*  hotel------> $1050 *\n";
    	linea[12] = "* Mortgage Value $110 *\n";
    }else if (space == 25){
    	init_color(COLOR_RED, 700,0,0);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Illinois Avenue   *\n";
    	linea[4] = "*       Rent $20      *\n";
    	linea[6] = "*  1 house --->   $1000 *\n";
    	linea[7] = "*  2 houses--->  $300 *\n";
    	linea[8] = "*  3 houses--->  $750 *\n";
    	linea[9] = "*  4 houses--->  $925 *\n";
    	linea[10] = "*  hotel------> $1100 *\n";
    	linea[12] = "* Mortgage Value $120 *\n";
    }else if (space == 27 || space == 28){
    	init_pair(1,COLOR_WHITE,COLOR_YELLOW);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 27)linea[1] = "*   Atlantic Avenue   *\n";
        if (space == 28)linea[1] = "*   Ventnor Avenue    *\n";
    	linea[4] = "*       Rent $22      *\n";
    	linea[6] = "*  1 house --->  $110 *\n";
    	linea[7] = "*  2 houses--->  $330 *\n";
    	linea[8] = "*  3 houses--->  $800 *\n";
    	linea[9] = "*  4 houses--->  $975 *\n";
    	linea[10] = "*  hotel------> $1150 *\n";
    	linea[12] = "* Mortgage Value $130 *\n";
    }else if (space == 30){
    	init_pair(1,COLOR_WHITE,COLOR_YELLOW);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Marvin Gardens    *\n";
    	linea[4] = "*       Rent $24      *\n";
    	linea[6] = "*  1 house --->  $120 *\n";
    	linea[7] = "*  2 houses--->  $360 *\n";
    	linea[8] = "*  3 houses--->  $850 *\n";
    	linea[9] = "*  4 houses---> $1025 *\n";
    	linea[10] = "*  hotel------> $1200 *\n";
    	linea[12] = "* Mortgage Value $140 *\n";
    }else if (space == 32 || space == 33){
    	init_pair(1,COLOR_WHITE,COLOR_GREEN);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 32)linea[1] = "*   Pacific Avenue    *\n";
        if (space == 33)linea[1] = "* North Carolina Av.  *\n";
    	linea[4] = "*       Rent $26      *\n";
    	linea[6] = "*  1 house --->  $130 *\n";
    	linea[7] = "*  2 houses--->  $390 *\n";
    	linea[8] = "*  3 houses--->  $900 *\n";
    	linea[9] = "*  4 houses---> $1100 *\n";
    	linea[10] = "*  hotel------> $1275 *\n";
    	linea[12] = "* Mortgage Value $150 *\n";
    }else if (space == 35){
    	init_pair(1,COLOR_WHITE,COLOR_GREEN);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*  Pensylvania Avenue *\n";
    	linea[4] = "*       Rent $28      *\n";
    	linea[6] = "*  1 house --->  $150 *\n";
    	linea[7] = "*  2 houses--->  $450 *\n";
    	linea[8] = "*  3 houses---> $1000 *\n";
    	linea[9] = "*  4 houses---> $1200 *\n";
    	linea[10] = "*  hotel------> $1400 *\n";
    	linea[12] = "* Mortgage Value $160 *\n";
    }else if (space == 38){
    	init_color(COLOR_BLUE,0,0,700);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*      Park Place     *\n";
    	linea[4] = "*       Rent $35      *\n";
    	linea[6] = "*  1 house --->  $175 *\n";
    	linea[7] = "*  2 houses--->  $500 *\n";
    	linea[8] = "*  3 houses---> $1100 *\n";
    	linea[9] = "*  4 houses---> $1300 *\n";
    	linea[10] = "*  hotel------> $1500 *\n";
    	linea[12] = "* Mortgage Value $175 *\n";
    }else if (space == 40){
    	init_color(COLOR_BLUE,0,0,700);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*       Boardwalk     *\n";
    	linea[4] = "*       Rent $35      *\n";
    	linea[6] = "*  1 house --->  $200 *\n";
    	linea[7] = "*  2 houses--->  $600 *\n";
    	linea[8] = "*  3 houses---> $1400 *\n";
    	linea[9] = "*  4 houses---> $1700 *\n";
    	linea[10] = "*  hotel------> $2000 *\n";
    	linea[12] = "* Mortgage Value $200 *\n";
    }
    attron(COLOR_PAIR(1));
    for (int i = 0; i <= 15; i++)
    {
        if (i >=3){
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
    }
        mvprintw(i+10,20,linea[i].c_str());

    }
        
    attroff(COLOR_PAIR(2));  
}