#include "common.h"
#include "jumproto.h"
#ifndef JUMPLTE_H
#define JUMPLTE_H

class jumplte : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplte();
	virtual ~jumplte();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
};

#endif;