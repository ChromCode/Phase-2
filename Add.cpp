/*
There are several comments throughout the code that print the action of that piece of code. These are left in here for debugging purposes for Phase 2.
*/

#include "Add.h"

//constructor with initialized data members
Add::Add(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Add made" << endl;*/}
//destructor
Add::~Add(){/*cout << "Add destroyed" << endl;*/}

//check that parameter number and types are valid
bool Add::validator(){
    //cout << "running ADD validator..." << endl;
    //parameter counter
   int num_params=0;
    
    //find result parameter in maps
	
    //convert parameter list
    for(string s : params){
        try{
	        if(convert(s)!=0){
	        num_params++;
	        //if parameter is number, convert to float 
	            if(convert(s)==2) { converted_params.push_back(stod(s)); }
	            //if parameter is variable, pull value from variable map
	            else if(convert(s)==1){converted_params.push_back(createdVariables[s]->getValue());}
	        }
            	else{cerr << "IN ADD: bad convert of " << s << endl; return false;}
        } catch(...){return false;}
            //check number of parameters doesn't exceed 12
    }
    if(num_params<2 || num_params>12){cerr << "IN ADD: wrong number of parameters" << endl; return false;}
    return true;
}
//if validator is true, run Add::process
void Add::process(){
    if(validator()){
        //cout << "ADD processing..." << endl;
        //sum values
        float sum = 0;
        //add converted params to sum
        for(float f : converted_params){sum+=f;}
            cout << "Variable before ADD: ";
            createdVariables[result_string]->print();

        //set value of first variable to sum of all the rest
            createdVariables[result_string]->setValue(sum);
            cout << "Variable after ADD: ";
            createdVariables[result_string]->print();
    } else {cerr << "IN ADD: invalid parameter list" << endl;}
}

