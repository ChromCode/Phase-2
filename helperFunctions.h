#include "common.h"
#include "Var.h"
#include "Var.cpp"
#include "String.h"
#include "NUMERIC.h"
#include "REAL.h"
#include "CHAR.h"
#include "Label.h"
extern map< string, NUMERIC*> createdNUMERICS;
extern map< string, REAL*> createdREALS;
extern map< string, CHAR*> createdCHARS;
extern map< string, STRING*> createdSTRINGS;
extern map<string, label*> createdLabels;
extern std::vector<std::thread> threadVector; 
extern map<int, string> lines;

void varHelper( stringstream &ss );
void realHelper( stringstream &ss );
void addHelper( stringstream &ss );
void subHelper( stringstream &ss );
void multHelper( stringstream &ss );
void divHelper( stringstream &ss );
void assignHelper( stringstream &ss );
void outHelper( stringstream &ss );
void setStrHelper( stringstream &ss );
void getStrHelper( stringstream &ss );
void labelHelper( stringstream &ss );
// void JMPHelper( stringstream &ss );
// void JMPZHelper( stringstream &ss );
// void JMPNZHelper( stringstream &ss );
// void JMPGTHelper( stringstream &ss );
// void JMPGTEHelper( stringstream &ss );
// void JMPLTHelper( stringstream &ss );
// void JMPLTEHelper( stringstream &ss );
void sleepHelper( stringstream &ss );
void aquireLock(stringstream &ss);
void releaseLock(stringstream &ss);
void threadParseHelper( stringstream &ss );
void threadExecuteHelper(int start, int end);
void barrierHelper( stringstream &ss );
void doNothing( stringstream &ss );
void deleteVariables();
