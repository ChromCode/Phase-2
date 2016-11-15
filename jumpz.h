#include "common.h"
#include "jumproto.h"
#ifndef JUMPZ_H
#define JUMPZ_H

class jumpz : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpz();
	string labelname;
	virtual ~jumpz();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
};

#endif