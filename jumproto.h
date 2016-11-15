#include "common.h"
#ifndef JUMPROTO_H
#define JUMPROTO_H

class jumproto { //declaration
protected:
private:
public:
	jumproto();
	virtual ~jumproto();
	virtual void initialize(stringstream &ss);
	virtual void clone(stringstream&ss, int x);
};

#endif