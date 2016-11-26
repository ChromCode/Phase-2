#include "common.h"
#include "jumproto.h"
#ifndef JMPGTE_H
#define JMPGTE_H

class jumpgte : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpgte();
	virtual ~jumpgte();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
	void acjump(string str);
};

#endif;