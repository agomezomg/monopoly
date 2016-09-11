#pragma once
#include "Table.h"
#include <string>

using std::string;

class Properties : public Table
{
protected:
	int ID;
	string title;
	int price;
	int rent;
	int sale;
	bool owned;
	int mortgage;
	string color;
	int deduction;
public:
	Properties(int,int,int,int,string,bool);
	~Properties();
	Properties();
	int getID();
	void setID();
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
	void setAll(int);
	string toString();
	string toString(int);
	int getDeduction();
	void setDeduction(int);
	virtual void drawItem(int space);
	void buyPropety(int);
	string getTitle();
};