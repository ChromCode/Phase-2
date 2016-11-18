#include "Var.h"
#include "Var.cpp"
#include "common.h"
#ifndef STRING_H
#define STRING_H

// This class is derived from var, and its value is a char array, and has int size
class STRING : public VAR<string> {
    private:
        int size;
    public:

        // default constructor
        STRING();

        // Paramaterized constructor initializing data members from param list
        STRING(const string& inName, int inSize, const string& inValue);

        // Initializes data members with values from stringstream
        virtual void constructVar(stringstream &ss);

        // sets the value to the given param, if the types match
        void setValue(string input);

        // Helpful debugging funciton, prints VAR object
        void print();

        // returns the value based off of its type, this code definitely could be more generic
        string getValue();

       // returns the name of the variable
        string getName();

        // returns the value of isLocked
        bool locked();

        // sets isLocked to True
        void setLock();

        // set is Locked to False
        void unLock();

        // returns a char value at index i
        char getChar(int x);

        // sets a char value at index x
        void setChar(int x, char a);

        // Clones a VAR onject, used for multi threading
        STRING * clone(stringstream &ss);

        // Default constructor
        virtual ~STRING();
};

#endif