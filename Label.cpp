#include "Label.h"
#include "common.h"

label::label() {} //default constructor
label::label(string x, int y) {
	linenumber = y;
	name = x;
}//copy constructor

void label::initialize(stringstream &ss, int x) {
	string str = ss.str();
	stringstream iss(str);
	getline(iss, str, ' ');
	getline(iss, str, ' ');
	name = str;
	linenumber = x;
}

label::~label() {} //destructor 
label* label::clone(stringstream&ss, int x) {
	label* nlabel = new label();
	nlabel->initialize(ss, x);
	return nlabel;
}