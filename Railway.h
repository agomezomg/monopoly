#pragma once
#include "Properties.h"
#include "Table.h"
#include <string>

using std::string;

class Railway : public Properties
{
private:
	string title;
	int railway;
	int railwayPrice;
public:
	Railway();
	~Railway();
	string getTitle();
	void setTitle();
	int getRailway();
	void setRailway();
	int getRailwayPrice();
	void setRailwayPrice();
	string toString();
	void drawItem(int space);
};