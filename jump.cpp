#include "common.h"
#include "jump.h"

jump::jump() {}
jump::~jump() {}


void jump::initialize(stringstream &ss, int x) {
	string str = "";
	getline(ss, str, ' ');
	labelname = str;
	linenumber = x;
	acjump(str);
}

void jump::clone(stringstream&ss, int x) {
	jump *ok = new jump();
	ok->initialize(ss, x);
}

void jump::acjump(string str) {
	map<string, label*>::iterator p;
	p = createdLabels.find(str);
	if (p != createdLabels.end()) {
		counter = p->second->linenumber;
		cout << "Jumping to label " << str << endl;
	}
	else {
		cerr << "label not found\n";
		exit(1);
	}
}