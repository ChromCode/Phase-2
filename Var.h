#include "common.h"
#ifndef VAR_H
#define VAR_H

// This is a base class that follows the structure of the example from class 14
template<typename T>
class VAR {
    protected:
        string name;
        T value;
        bool isLocked;
    public:
    	// default constructor
    	VAR<T>();

    	// Reads the data from the stringstream and assigns values
        virtual void constructVar(stringstream &ss) = 0;

        // Helpful debugging method, prints out variable
        virtual void print() = 0;

        // Clones the object just created, used for mult-threading
        virtual VAR<T>* clone(stringstream &ss) = 0;

        // assigns a value to an already existing variable
        virtual void setValue(T input) = 0;

        // returns the name of the variable
        virtual string getName();

        // returns the value of Var object
        virtual T getValue();

        // Returns the isLocked variable
        virtual bool locked();

        virtual void setLock();

        virtual void unLock();

        // virtual bool canSet() = 0;

        // default constructor
    	virtual ~VAR<T>();
};

#endif