#include "Var.h"
#include "CHAR.h"
#include "common.h"

CHAR::CHAR() {
    name = "";
    value = 0;
}

CHAR::CHAR(const string& inName, const char& val) {
    name = inName;
    value = val;
}

void CHAR::setValue(char i) {
    value = i;
}

char CHAR::getValue() {
    return value;
}

string CHAR::getName() {
    return name;
}

bool CHAR::locked() {
    return isLocked;
}

void CHAR::setLock() {
    isLocked = true;
}

void CHAR::unLock() {
    isLocked = false;
}

void CHAR::constructVar(stringstream &ss) {
    string str = "";
    stringstream iss(ss.str()); // gets the first token before a comma
    iss >> ws;
    getline(iss, str, ' ');
    iss >> ws;
    getline(iss, str, ',');
    name = str.c_str();
    iss >> ws; // ignore any whitespace before the comma
    getline(iss, str, ',');
    iss >> ws; // ignore any whitespace
    getline(iss, str, ',');
    iss >> ws;
    stringstream pss(str);
    pss >> value;
    if( ss.fail() ) {
        cerr << "Unable to set char value to the speicified type" << endl;
        ss.clear();
        exit(1);
    }
}

CHAR * CHAR::clone(stringstream &ss) {
    CHAR * cloneVar = new CHAR;
    cloneVar->constructVar(ss);
    return cloneVar;
}

void CHAR::print() {
    cout << name << ", " << value << endl;
}

CHAR::~CHAR(){}