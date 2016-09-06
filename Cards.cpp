#include "Table.h"
#include "Cards.h"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

Cards::Cards() {

}

Cards::~Cards() {

}

Cards::Cards(string cardType, string cardTitle, string cardDescription) : cardType(cardType), cardTitle(cardTitle), cardDescription(cardDescription) {

}

void Cards::setCardType(string cardType) {
	this -> cardType = cardType;
}

string Cards::getCardType() {
	return this -> cardType;
}

void Cards::setCardTitle(string cardTitle) {
	this -> cardTitle = cardType;
}

string Cards::toString() {
	stringstream ss;
	ss << "Card";
	return ss.str();
}