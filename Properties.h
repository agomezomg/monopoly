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
	bool owned = false;
	int mortgage;
	string color;
public:
	Properties();
	~Properties();
	int getPrice();
	void setPrice();
	int getRent();
	void setRent();
	bool getOwned();
	void setOwned();
	int getMortgage();
	void setMortgage();
	string getColor();
	void setColor();
};