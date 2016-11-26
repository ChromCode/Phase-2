#include "common.h"
#include "jumproto.h"
#ifndef JUMPLT_H
#define JUMPLT_H

class jumplt : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplt();
	virtual ~jumplt();
	virtual void initialize(stringstream &ss, int x);
	string labelname;
	int linenumber;
	void acjump(string str);
};

#endif;