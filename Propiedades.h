#pragma once
#include "Table.h"

class Propiedades : public Table
{
protected:
	int price;
	int rent;
	int sale;
	bool owned = false;
	int mortgage;

public:
	Propiedades();
	~Propiedades();
	int getPrice();
	void setPrice();
	int getRent();
	void setRent();
	bool getOwned();
	void setOwned();
	int getMortgage();
	void setMortgage();
};