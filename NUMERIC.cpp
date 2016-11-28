#include "Var.h"
#include "NUMERIC.h"
#include "common.h"

NUMERIC::NUMERIC() {
    name = "";
    value = 0;
}

NUMERIC::NUMERIC(const string& inName, const int& val) {
    name = inName;
    value = val;
}

void NUMERIC::setValue(int i) {
    value = i;
}

int NUMERIC::getValue() {
    return value;
}

string NUMERIC::getName() {
    return name;
}

bool NUMERIC::locked() {
    return isLocked;
}

void NUMERIC::setLock() {
    isLocked = true;
}

void NUMERIC::unLock() {
    isLocked = false;
}

void NUMERIC::constructVar(stringstream &ss) {
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
    value = stoi(str.c_str());
}

NUMERIC * NUMERIC::clone(stringstream &ss) {
    NUMERIC * cloneVar = new NUMERIC;
    cloneVar->constructVar(ss);
    return cloneVar;
}

void NUMERIC::print() {
    cout << name << ", " << value << endl;
}

NUMERIC::~NUMERIC(){}