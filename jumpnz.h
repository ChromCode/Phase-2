#include "common.h"
#include "jumproto.h"
#ifndef JUMPNZ_H
#define JUMPNZ_H

class jumpnz : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpnz();
	string labelname;
	virtual ~jumpnz();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	void acjump(string str);
};

#endif