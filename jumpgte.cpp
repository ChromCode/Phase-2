#include "jumpgte.h"
#include "common.h"

jumpgte::jumpgte() {}
jumpgte::~jumpgte() {}

void jumpgte::clone(stringstream&ss, int x) {
	jumpgte *ok = new jumpgte();
	ok->initialize(ss, x);
}

void jumpgte::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss >> ws, str, ' ');
	getline(ss >> ws, str, ',');
	labelname = str;
}