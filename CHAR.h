#include "Var.h"
#include "Var.cpp"
#include "common.h"
#ifndef CHAR_H
#define CHAR_H

// This is a derived class from VAR
// This is a template class because we wanted the value's type to vary
class CHAR: public VAR<char> {
    private:
    public:

    	// default Constructor
        CHAR();

        // parameterized constructor initializing objects based on the params
        CHAR(const string& inName, const char& val);

        // initializes data members based off a stringstream
        virtual void constructVar(stringstream &ss);

        // sets the value to the given param, if the types match
        void setValue(char input);

        // Helpful debugging funciton, prints VAR object
        void print();

        // returns the value based off of its type, this code definitely could be more generic
        char getValue();

        // returns the name of the variable
        string getName();

        // returns the value of isLocked
        bool locked();

        // sets isLocked to True
        void setLock();

        // set is Locked to False
        void unLock();

        // Clones a VAR onject, used for multi threading
        CHAR * clone(stringstream &ss);

        // Default constructor
        virtual ~CHAR();
};

#endif