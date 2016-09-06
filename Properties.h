#pragma once
#include "Table.h"
#include <string>

using std::string;

class Properties : public Table
{
protected:
	int position;
	int price;
	int rent;
	int sale;
	bool owned;
	int mortgage;
	string color;
public:
	Properties();
	~Properties();
	int getPosition();
	void setPosition(int);
	int getPrice();
	void setPrice(int);
	int getRent();
	void setRent(int);
	int getSalePrice();
	void setSalePrice(int);
	bool getOwned();
	void setOwned(bool);
	int getMortgage();
	void setMortgage(int);
	string getColor();
	void setColor(string);
};