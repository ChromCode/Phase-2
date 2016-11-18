#include "common.h"
#include "VAR.h"
#include "Var.cpp"
#include "helperFunctions.h"
#include "String.h"
#include "NUMERIC.h"
#include "REAL.h"
#include "CHAR.h"

map< string, NUMERIC* > createdNUMERICS;
map< string, REAL* > createdREALS;
map< string, CHAR* > createdCHARS;
map< string, STRING* > createdSTRINGS;

void numericHelper( stringstream &ss ) {
    // VAR<int> * obj = new NUMERIC();
    // ss >> ws;
    // VAR<int> * objTemp = obj;
    // obj = objTemp -> clone(ss);
    // delete(objTemp);
    // createdNUMERICS[obj->getName()] = obj;
}

void realHelper( stringstream &ss ) {
	// VAR<double> * obj = new REAL();
 //    ss >> ws;
 //    VAR<double> * objTemp = obj;
 //    obj = objTemp -> clone(ss);
 //    delete(objTemp);
 //    createdREALS[obj->getName()] = obj;
}

void charHelper( stringstream &ss ) {
	CHAR * obj = new CHAR();
    ss >> ws;
    CHAR * objTemp = obj;
    obj = objTemp -> clone(ss);
    delete(objTemp);
    createdCHARS[obj->getName()] = obj;
}

void stringHelper( stringstream &ss ) {
	STRING * obj = new STRING();
    ss >> ws;
    STRING * objTemp = obj;
    obj = objTemp -> clone(ss);
    delete(objTemp);
    createdSTRINGS[obj->getName()] = obj;
}