#include "common.h"
#include "jumproto.h"
#ifndef JUMPGT_H
#define JUMPGT_H

class jumpgt : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpgt();
	virtual ~jumpgt();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
};

#endif;