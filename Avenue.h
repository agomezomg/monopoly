#pragma once
#include "Properties.h"
#include "Table.h"
#include <string>

using std::string;

class Avenue : public Properties
{
private:
	string title;
	int houses;
	int housePrice;
	int hotels;
	int hotelPrice;
public:
	Avenue(int, int, int, int, string, bool);
	Avenue();
	~Avenue();
	string getTitle();
	void setTitle();
	int getHouses();
	void setHouses(int);
	int getHousePrice();
	void setHousePrice(int);
	void printCard(int space);
	string toString();
	int getHotels();
	void setHotels(int);
	void drawItem(int space);
	int getRent();
};