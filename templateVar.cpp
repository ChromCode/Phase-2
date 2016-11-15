#include "templateVar.h"
#include "Var.h"
#include "common.h"
#ifndef TEMPLATEVAR_CPP
#define TEMPLATEVAR_CPP

template<typename T>
templateVar<T>::templateVar() {
    name = "";
    value = 0;
}

template<typename T>
templateVar<T>::templateVar(const string& inName, T val) {
    name = inName;
    value = val;
}

template<typename T>
T convert(const string& s){
    stringstream ss(s);
    T temp;
    ss >> temp;
    if( ss.fail() ) {
        cerr << "Unable to set template value to the speicified type" << endl;
        ss.clear();
        exit(1);
    }
    return temp;
}

template<typename T>
void templateVar<T>::setNumValue(float i) {
    try {
        value = static_cast<T>(i);
    } catch (std::bad_cast& bc) {
        cerr << "Variable type mismatch" << endl;
        exit(1);
    }
}

template<typename T>
void templateVar<T>::setCharValue(char a) {
    if( strcmp( typeid(value).name(), "c") == 0 ) {
        value = a;
    } else {
        cerr << "Types do not match" << endl;
        exit(1);
    }
}

template<typename T>
void templateVar<T>::constructVar(stringstream &ss) {
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
    value = convert<T>(str.c_str());
}

template<typename T>
VAR * templateVar<T>::clone(stringstream &ss) {
    templateVar<T> * cloneVar = new templateVar<T>;
    cloneVar->constructVar(ss);
    return cloneVar;
}

template<typename T>
void templateVar<T>::print() {
    cout << name << ", " << value << endl;
}

template<typename T>
void templateVar<T>::varInsert(map<string, VAR*> &varMap) {
    varMap[name] = this;
}

template<typename T>
int templateVar<T>::getNumericValue() {
    if ( strcmp( typeid(value).name(), "i") == 0 ) {
        return value;
    } else {
        cerr << "Attempted to grab an int from a non-int type" << endl;
        exit(1);
    }
}

template<typename T>
double templateVar<T>::getRealValue() {
    if ( strcmp( typeid(value).name(), "d") == 0 ) {
        return value;
    } else {
        cerr << "Attempted to grab a double from a non-double type" << endl;
        exit(1);
    }
}

template<typename T>
char templateVar<T>::getCharValue() {
    if ( strcmp( typeid(value).name(), "c") == 0 ) {
        return value;
    } else {
        cerr << "Attempted to grab a char from a non-char type" << endl;
        exit(1);
    }
}

template<typename T>
templateVar<T>::~templateVar(){}

#endif