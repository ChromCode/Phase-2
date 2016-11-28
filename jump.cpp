#include "common.h"
#include "jump.h"

jump::jump() {}
jump::~jump() {}


void jump::initialize(stringstream &ss, int x) {
	string str = "";
	getline(ss, str, ' ');
	labelname = str;
	linenumber = x;
}

void jump::clone(stringstream&ss, int x) {
	jump *ok = new jump();
	ok->initialize(ss, x);
}