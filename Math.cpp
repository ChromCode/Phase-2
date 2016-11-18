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

string Math::findVar(string var){
        //true if variable is found in maps, false otherwise
        bool found = true;
        //string indicating which map var was found in
        string found_in="nums";
        //check that result variable exists in variable map
        if(createdNUMERICS.find(result_string)==createdNUMERICS.end()){found==false; found_in="real";}
        else if(createdREALS.find(result_string)==createdREALS.end()){found==false; found_in="none"}
        //otherwise variable not found
        if(found==false){cerr << "IN ADD: the variable " << result_string << " does not exist" << endl; found==true;}
        return found_in;
}

//checks parameter list, validates type: implemented in derived classes
bool Math::validator(){}
//process implemented in derived classes
void Math::process(){}
