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
public:
	Avenue();
	~Avenue();
	string getTitle();
	void setTitle();
	int getHouses();
	void setHouses();
	int getHousePrice();
	void setHousePrice();
	void printCard(int space);
	string toString();
	void drawItem(int space);
};