#include "Var.h"
#include "Var.cpp"
#include "common.h"
#ifndef NUMERIC_H
#define NUMERIC_H

// This is a derived class from VAR
// This is a template class because we wanted the value's type to vary
class NUMERIC: public VAR<int> {
    private:
    public:

    	// default Constructor
        NUMERIC();

        // parameterized constructor initializing objects based on the params
        NUMERIC(const string& inName, const int& val);

        // initializes data members based off a stringstream
        virtual void constructVar(stringstream &ss);

        // sets the value to the given param, if the types match
        void setValue(int input);

        // Helpful debugging funciton, prints VAR object
        void print();

        // returns the value based off of its type, this code definitely could be more generic
        int getValue();

        string getName();

        // Clones a VAR onject, used for multi threading
        VAR<int> * clone(stringstream &ss);

        // Default constructor
        virtual ~NUMERIC();
};

#endif