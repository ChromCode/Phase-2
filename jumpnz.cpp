#include "common.h"
#include "jumpz.h"
#include "jumproto.h"
#include "helperFunctions.h"

jumpz::jumpnz() {}
jumpz::~jumpnz() {}

void jumpnz::clone(stringstream&ss, int x) {
	jumpnz *ok = new jumpnz();
	ok->initialize(ss, x);
}

void jumpnz::initialize(stringstream &ss, int x) {
	cout << ss.str() << endl;
	linenumber = x;
	string str = ss.str();
	stringstream iss(str);
	getline(iss, str, ' ');
	getline(iss, str, ',');
	cout << "label name = " << str << endl;
	labelname = str;
	acjump(str);
}

void jumpnz::acjump(string str) {
	getline(iss, str, ',');
	getline(iss, str, ',');
	label * foundLabel = createdLabels[labelname];
	if (foundLabel == NULL) {
		cerr << "No label Found" << endl;
		exit(1);
	}
	if (str[0] == '$') {
		cout << str << endl;
		NUMERIC * obj = createdNUMERICS[str];
		if (obj == NULL) {
			cerr << "Variable does not exist" << endl;
			exit(1);
		}
		else {
			int i = obj->VALUE;
			if (i != 0) {
				counter = foundLabel->linenumber;
			}
		}
	}
	else {
		cout << str << endl;
		int i = stoi(str);
		if (i != 0) {
			counter = foundLabel->linenumber;
		}
	}
}