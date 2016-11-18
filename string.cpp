#include "String.h"
#include "Var.h"
#include "common.h"

STRING::STRING(){
    name = ""; 
    size = 0; 
    value = "";
}

STRING::STRING(const string& inName, int inSize, const string& inValue) {
    // if the string is too long, or the given size is too big, don't create this variable
    if( inSize > 256 || inSize < 0 ) {
        cerr << "Char array size must be between 0 and 256" << endl;
        exit(1);
    }
    if( inValue.size() > inSize ) {
        cerr << "Char array is too large for the given size" << endl;
    }
    // set data members
    name = inName;
    size = inSize;
    value = inValue;
}

// sets the value at the given index to the char value
void STRING::setChar(int x, char a) {
    // we can't change the value of an array if its too big
    if( x < size || x < value.size() ) {
        value[x] = a;
    } else { 
        // if it is too big, throw an error
        cerr << "The location is out of range of the variable" << endl;
    }
}

char STRING::getChar(int i) {
    // return the value of the String at index i, if it is in size
    if( i < size ) {
        return value[i];
    } else {
        // else throw an error
        cerr << "The location is out of range of the variable" << endl;
        exit(1);
    }
}

// returns the value of the var
string STRING::getValue() {
    return value;
}

// returns the name of the var
string STRING::getName() {
    return name;
}

// Prints out Var members for debugging
void STRING::print() {
    cout << name << ", "  << size << ", " << value << endl;
}

// assigns a new string to the Var
void STRING::setValue(string a) {
    if( a.size() > 256 || a.size() > size ) {
        cerr << "Char array size must not exceed the given size, or be larger than 256 chars long" << endl;
        exit(1);
    } else {
        value = a;
    }
}

// returns the value of the isLocked member
bool STRING::locked() {
    return isLocked;
}

// sets isLocked to True
void STRING::setLock() {
    isLocked = true;
}

// sets isLocekd to False
void STRING::unLock() {
    isLocked = false;
}

// constructs the Var based off of parameters from a stringstream
void STRING::constructVar(stringstream &ss) {
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
    size = stoi(str.c_str(), NULL);
    iss >> ws;
    getline(iss, str, ',');
    value = str; // Cast as a char pointer, so we can set to value
}

// clones VAR object for multi-thread use
STRING * STRING::clone(stringstream &ss) {
    STRING * cloneVar = new STRING(); // create new object
    cloneVar -> constructVar(ss); // initialize it
    return cloneVar; // return
}

//default constructor 
STRING::~STRING(){}