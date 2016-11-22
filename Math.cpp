#include "Math.h"

//constructor
Math::Math(){}
//destructor
Math::~Math(){}

//convert string parameter to workable type: used by all derived arithmetic classes
int Math::convert(string s){
        //if parameter is variable
        if(s[0]=='$'){ return 1;}
        //if parameter is number
        else if(isdigit(s[0])){return 2; }
        //all other parameter types are invalid
        else {return 0;}
}

int Math::findVar(string var){
        //string indicating which map var was found in
        int found_in=1;
        //check that result variable exists in variable map
        if(createdNUMERICS.find(var)==createdNUMERICS.end()){
                found_in=2;
                if(createdREALS.find(var)==createdREALS.end()){found_in=0;}
        }
        return found_in;
}

//checks parameter list, validates type: implemented in derived classes
bool Math::validator(){}
//process implemented in derived classes
void Math::process(){}