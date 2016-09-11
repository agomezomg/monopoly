#pragma once
#include "Table.h"
#include <string>
using std::string;

class Cards : public Table
{
private:
	string cardType;
	string cardTitle;
	string cardDescription;
	
public:
	Cards();
	~Cards();
	Cards(string, string, string);
	void setCardType(string);
	string getCardType();
	void setCardTitle(string);
	string getCardTitle();
	void setCardDescription(string);
	string getCardDescription();
	string toString();
};