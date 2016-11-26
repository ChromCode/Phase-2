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
	acjump(str);
}

void jumpgt::acjump(string str) {
	int first;
	int second;
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
			first = obj->value;
		}
	}
	else {
		first = stoi(str);
	}

	getline(iss >> ws, str, ',');

	if (str[0] == '$') {
		cout << str << endl;
		NUMERIC * obj = createdNUMERICS[str];
		if (obj == NULL) {
			cerr << "Variable does not exist" << endl;
			exit(1);
		}
		else {
			second = obj->value;
		}
	}
	else {
		second = stoi(str);
	}
	if (first > second) {
		counter = foundLabel->linenumber;
	}
}
