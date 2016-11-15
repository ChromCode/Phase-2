#include "common.h"
#include "jumpz.h"
#include "jumproto.h"
#include "helperFunctions.h"

jumpz::jumpz() {}
jumpz::~jumpz() {}

void jumpz::clone(stringstream&ss, int x) {
	jumpz *ok = new jumpz();
	ok->initialize(ss, x);
}

void jumpz::initialize(stringstream &ss, int x) {
	cout << ss.str() << endl;
	linenumber = x;
	string str = ss.str();
	stringstream iss(str);
	getline(iss, str, ' ');
	getline(iss, str, ',');
	cout << "label name = " << str << endl;
	labelname = str;
}