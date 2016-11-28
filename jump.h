#include "common.h"
#include "jumproto.h"
#ifndef JUMP_H
#define JUMP_H

class jump : public jumproto {
public:
	jump();
	int linenumber;
	string labelname;
	virtual ~jump();
	void initialize(stringstream &ss, int x);
	void clone(stringstream&ss, int x);
};

#endif