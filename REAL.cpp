#include "Var.h"
#include "REAL.h"
#include "common.h"

REAL::REAL() {
    name = "";
    value = 0;
}

REAL::REAL(const string& inName, const double& val) {
    name = inName;
    value = val;
}

void REAL::setValue(double i) {
    cout << "WE're gonna set this value" << endl;
}

double REAL::getValue() {
    return value;
}

string REAL::getName() {
    return name;
}

bool REAL::locked() {
    return isLocked;
}

void REAL::setLock() {
    isLocked = true;
}

void REAL::unLock() {
    isLocked = false;
}

void REAL::constructVar(stringstream &ss) {
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
    value = stod(str.c_str());
}

REAL * REAL::clone(stringstream &ss) {
    REAL * cloneVar = new REAL;
    cloneVar->constructVar(ss);
    return cloneVar;
}

void REAL::print() {
    cout << name << ", " << value << endl;
}

REAL::~REAL(){}