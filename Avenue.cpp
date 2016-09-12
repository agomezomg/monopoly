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

Avenue::Avenue(int rent, int sale, int mortgage, int price, string title, bool owned) : Properties(rent, sale, mortgage, price, title, owned) {
    this -> mortgage = 0;
    if (title == "Mediterranean Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 1;
        this -> color = "Brown";
        this -> houses = 0;
        this -> housePrice = 25;
    } else if (title == "Baltic Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 3;
        this -> color = "Brown";
        this -> houses = 0;
        this -> housePrice = 25;
    } else if (title == "Oriental Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 6;
        this -> color = "Light Blue";
        this -> houses = 0;
        this -> housePrice = 25;
    } else if (title == "Vermont Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 8;
        this -> color = "Light Blue";
        this -> houses = 0;
        this -> housePrice = 25;
    } else if (title == "Connecticut Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 9;
        this -> color = "Light Blue";
        this -> houses = 0;
        this -> housePrice = 25;
    } else if (title == "St. Charles Place")
    {
        this -> mortgage = 0;
        this -> ID = 11;
        this -> color = "Pink";
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "States Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 13;
        this -> color = "Pink";
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "Virginia Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 14;
        this -> color = "Pink";
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "St. James Place")
    {
        this -> mortgage = 0;
        this -> ID = 16;
        this -> color = "Orange";
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "Tennessee Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 18;
        this -> color = "Orange";
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "New York Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 19;
        this -> color = "Orange"; 
        this -> houses = 0;
        this -> housePrice = 50;
    } else if (title == "Kentucky Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 21;
        this -> color = "Red";
        this -> houses = 0;
        this -> housePrice = 75;
    } else if (title == "Indiana Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 23;
        this -> color = "Red";
        this -> houses = 0;
        this -> housePrice = 75;
    }  else if (title == "Illinois Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 24;
        this -> color = "Red";
        this -> houses = 0;
        this -> housePrice = 75;
    }  else if (title == "Atlantic Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 26;
        this -> color = "Yellow";
        this -> houses = 0;
        this -> housePrice = 75;
    }  else if (title == "Ventnor Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 28;
        this -> color = "Yellow";
        this -> houses = 0;
        this -> housePrice = 75;
    }  else if (title == "Marvin Gardens")
    {
        this -> mortgage = 0;
        this -> ID = 29;
        this -> color = "Yellow";
        this -> houses = 0;
        this -> housePrice = 75;
    }  else if (title == "Pacific Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 31;
        this -> color = "Green";
        this -> houses = 0;
        this -> housePrice = 100;
    }  else if (title == "North Carolina Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 32;
        this -> color = "Green";
        this -> houses = 0;
        this -> housePrice = 100;
    } else if (title == "Pennsylvania Avenue")
    {
        this -> mortgage = 0;
        this -> ID = 34;
        this -> color = "Green";
        this -> houses = 0;
        this -> housePrice = 100;
    } else if (title == "Park PLace")
    {
        this -> mortgage = 0;
        this -> ID = 37;
        this -> color = "Dark Blue";
        this -> houses = 0;
        this -> housePrice = 100;
    } else if (title == "Boardwalk")
    {
        this -> mortgage = 0;
        this -> ID = 39;
        this -> color = "Dark Blue";
        this -> houses = 0;
        this -> housePrice = 100;
    } else {
        this -> color = title;
    }
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

void Avenue::setHouses(int houses) {
    if (houses == 5)
    {
        this -> hotels = 1;
    } else if (houses <= 4)
    {
        this -> houses = houses;
    }
}

int Avenue::getHousePrice() {
    return this -> housePrice;
}

void Avenue::setHousePrice(int housePrice) {
    this -> housePrice = housePrice;
}

string Avenue::toString() {
	stringstream ss;
	ss << this->title;
    return ss.str();
}

void Avenue::drawItem(int space) {
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

int Avenue::getHotels() {
    return this -> hotels;
}

void Avenue::setHotels(int hotels) {
    this -> hotels = hotels;
}

int Avenue::getRent() {
    if (this -> houses == 1)
    {
        if (title == "Pennsylvania Avenue")
        {
            return this -> rent * 5 - 10;
        } else if (title == "Boardwalk")
        {
            return this -> rent * 5 - 50;
        }
        return this -> rent * 5;
    } else if (this -> houses == 2)
    {
        if (title == "Conneticut Avenue" || title == "New York Avenue" || title == "Kentucky Avenue" || title == "Indiana Avenue")
        {
            return this -> rent * 15 - 20;
        } else if (title == "St. James Place" || title == "Tennessee Avenue")
        {
            return this -> rent * 15 - 10;
        } else if (title == "Pennsylvania Avenue")
        {
            return this -> rent * 15 + 30;
        } else if (title == "Boardwalk")
        {
            return this -> rent * 15 - 150;
        }
        return this -> rent * 15;
    } else if (this -> houses == 3)
    {
        if (title == "Connecticut Avenue")
        {
            return this -> rent * 45 - 60;
        } else if (title == "Virginia Avenue")
        {
            return this -> rent * 15 - 40;
        } else if (title == "St. James Place" || title == "Tennessee Avenue")
        {
            return this -> rent * 15 - 80;
        } else if (title == "New York Avenue")
        {
            return this -> rent * 15 - 75;
        } else if (title == "Kentucky Avenue" || title == "Indiana Avenue")
        {
            return this -> rent* 15 - 110;
        } else if (title == "Illinois Avenue")
        {
            return this -> rent * 15 - 150;
        } else if (title == "Atlantic Avenue" || title == "Ventnor Avenue")
        {
            return this -> rent * 40;
        } else if (title == "Marvin Gardens")
        {
            return this -> rent * 40 - 110;
        } else if (title == "Pacific Avenue" || title == "North Carolina Avenue")
        {
            return rent * 35 - 10;
        } else if (title == "Pennsylvania Avenue")
        {
            return this -> rent * 40 - 120;
        } else if (title == "Park Place")
        {
            return this -> rent * 30 + 50;
        } else if (title == "Boardwalk")
        {
            return this -> rent * 28;
        }
        return this -> rent * 45;
    } else if (this -> houses == 4)
    {
        if (title == "Oriental Avenue" || title == "Vermont Avenue")
        {
            return this -> rent * 75 - 50;
        } else if (title == "Connecticut Avenue")
        {
            return this -> rent * 55 + 10;
        } else if (title == "St. Charles Place" || title == "States Avenue")
        {
            return 625;
        } else if (title == "Virginia Avenue")
        {
            return 700;
        } else if (title == "St. James Place" || title == "Tennessee Avenue")
        {
            return 750; 
        } else if (title == "New York Avenue")
        {
            return 800;
        } else if (title == "Kentucky Avenue" || title == "Indiana Avenue")
        {
            return 875;
        } else if (title == "Illinois Avenue")
        {
            return 925;
        } else if (title == "Atlantic Avenue" || title == "Ventnor Avenue")
        {
            return 975;
        } else if (title == "Marvin Gardens")
        {
            return 1025;
        } else if (title == "Pacific Avenue" || title == "North Carolina Avenue")
        {
            return 1100;
        } else if (title == "Pennsylvania Avenue")
        {
            return 1200;
        } else if (title == "Park Place")
        {
            return 1300;
        } else if (title == "Boardwalk")
        {
            return 1700;
        }
        return this -> rent * 80;
    } else if (this -> houses == 5)
    {
        if (title == "Mediterranean Avenue")
        {
            return 250;
        } else if (title == "Baltic Avenue")
        {
            return 450;
        } else if (title == "Oriental Avenue")
        {
            return 550;
        } else if (title == "Vermont Avenue")
        {
            return 550;
        } else if (title == "Connecticut Avenue")
        {
            return 600;
        } else if (title == "St. Charles Place")
        {
            return 750;
        } else if (title == "States Avenue")
        {
            return 750;
        } else if (title == "Virginia Avenue")
        {
            return 900;
        } else if (title == "St. James Place")
        {
            return 950;
        } else if (title == "Tennessee Avenue")
        {
            return 950;
        } else if (title == "New York Avenue")
        {
            return 1000;
        } else if (title == "Kentucky Avenue")
        {
            return 1050;
        } else if (title == "Indiana Avenue")
        {
            return 1050;
        }  else if (title == "Illinois Avenue")
        {
            return 1100;
        }  else if (title == "Atlantic Avenue")
        {
            return 1150;
        }  else if (title == "Ventnor Avenue")
        {
            return 1150;
        }  else if (title == "Marvin Gardens")
        {
            return 1200;
        }  else if (title == "Pacific Avenue")
        {
           return 1275;
        }  else if (title == "North Carolina Avenue")
        {
            return 1275;
        } else if (title == "Pennsylvania Avenue")
        {
            return 1400;
        } else if (title == "Park PLace")
        {
            return 1500;
        } else if (title == "Boardwalk")
        {
            return 2000;
        }
    }
    return this -> rent;

}