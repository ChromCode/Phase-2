#include "common.h"
#ifndef LABEL_H
#define LABEL_H

class label { //declaration
protected:
private:
public:
	label();
	label(string x, int y);
	~label();
	void initialize(stringstream &ss, int x);
	label* clone(stringstream&ss, int x);
	int linenumber;
	string name;
}; 

#endif;