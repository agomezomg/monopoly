#pragma once
#include "Table.h"
#include "Propiedades.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::stringstream;
using std::string;

class Jugador
{
protected:
	vector<Propiedades*> properties;
public:
	Jugador();
	~Jugador();
	
};