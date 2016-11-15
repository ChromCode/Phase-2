#include "common.h"
#include "Var.h"
// #include "Label.h"
extern map<string, VAR<int>* > createdNUMERICS;
// extern map<string, VAR<double> createdREALS;
// extern map<string, VAR<char> createdCHARS;
// extern map<string, VAR<string> createdSTRINGS;
// extern map<string, label*> createLabels;

void varHelper( stringstream &ss );
void addHelper( stringstream &ss );
void subHelper( stringstream &ss );
void multHelper( stringstream &ss );
void divHelper( stringstream &ss );
void assignHelper( stringstream &ss );
void outHelper( stringstream &ss );
void setStrHelper( stringstream &ss );
void getStrHelper( stringstream &ss );
void labelHelper( stringstream &ss );
void JMPHelper( stringstream &ss );
void JMPZHelper( stringstream &ss );
void JMPNZHelper( stringstream &ss );
void JMPGTHelper( stringstream &ss );
void JMPGTEHelper( stringstream &ss );
void JMPLTHelper( stringstream &ss );
void JMPLTEHelper( stringstream &ss );
void sleepHelper( stringstream &ss );
void doNothing( stringstream &ss );
void deleteVariables();