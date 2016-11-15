#include "jumpgt.h"
#include "common.h"
#include "jumproto.h"

jumpgt::jumpgt() {}
jumpgt::~jumpgt() {}

void jumpgt::clone(stringstream&ss, int x) {
	jumpgt *ok = new jumpgt();
	ok->initialize(ss, x);
}

void jumpgt::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss >> ws, str, ' ');
	getline(ss >> ws, str , ',');
	labelname = str;
}