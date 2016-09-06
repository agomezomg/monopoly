#pragma once
#include <string>

using std::string;

class table
{
public:
	table();
	virtual ~table();
	virtual string toString()const = 0;
	virtual void printTable() = 0;
};