#pragma once
#include <string>

using std::string;

class Table
{
public:
	Table();
	virtual ~Table();
	virtual string toString()const = 0;
	virtual void printTable() = 0;
};