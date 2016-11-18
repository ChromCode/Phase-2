#include "Var.h"
#include "Var.cpp"
#include "common.h"
#ifndef REAL_H
#define REAL_H

// This is a derived class from VAR
// This is a template class because we wanted the value's type to vary
class REAL: public VAR<double> {
    private:
    public:

    	// default Constructor
        REAL();

        // parameterized constructor initializing objects based on the params
        REAL(const string& inName, const double& val);

        // initializes data members based off a stringstream
        virtual void constructVar(stringstream &ss);

        // sets the value to the given param, if the types match
        void setValue(double input);

        // Helpful debugging funciton, prints VAR object
        void print();

        // returns the value based off of its type, this code definitely could be more generic
        double getValue();

        // returns the name of the variable
        string getName();

        // returns the value of isLocked
        bool locked();

        // sets isLocked to True
        void setLock();

        // set is Locked to False
        void unLock();

        // Clones a VAR onject, used for multi threading
        REAL * clone(stringstream &ss);

        // Default constructor
        virtual ~REAL();
};

#endif