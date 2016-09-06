#include "Table.h"
#include <string>
#include <sstream>

using std::string;
using std::sstream;

Table::Table() {

}

Table::~Table() {
	
}

string Table::toString() {
	stringstream ss;
	ss << "Tablero";
	return ss.str();
}