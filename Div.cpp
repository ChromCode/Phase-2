#include "Div.h"

//constructor
Div::Div(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Div made" << endl;*/}
//destructor
Div::~Div(){/*cout << "Div destroyed" << endl;*/}

//check that parameter number and types are valid
bool Div::validator(){
        //cout << "running DIV validator..." << endl;
        //parameter counter
        int num_params=0;
        //check that result is a variable that exists in the var map
        //find result parameter in maps: 0-not found, 1-nums, 2-reals
    int var_found = findVar(result_string);
    //variable does not exist in maps
    if(var_found==0){return false;}
	
    //convert parameter list
    for(string s : params){
	    if(convert(s)!=0){
	        num_params++;
	        //if parameter is number, convert to float 
	        if(convert(s)==2) { converted_params.push_back(stod(s)); }
	        //if parameter is variable, pull value from variable map
	        else if(convert(s)==1){
			    int par_var_found = findVar(s);
	        	switch(par_var_found){
				    case 1: converted_params.push_back(createdNUMERICS[s]->getValue());
				    case 2: converted_params.push_back(createdREALS[s]->getValue());
				    default: return false;
			    }
            }
	    }
            else{cerr << "IN DIV: bad convert of " << s << endl; return false;}
    }
    if(converted_params[1]==0){cerr << "IN DIV: cannot divide by zero!" << endl; return false;}
    if(num_params!=2){cerr << "IN DIV: wrong number of parameters" << endl; return false;}
    return true;
}

//if validator is true, run add process
void Div::process(){
    if(validator()){
        //cout << "DIV processing..." << endl;
        //take the quotient
        float num = converted_params[0];
        float den = converted_params[1];
        float quot = num / den;
        int var_found = findVar(result_string);
        switch(var_found){
		    case 1: createdNUMERICS[result_string]->setValue(quot);
		    case 2: createdREALS[result_string]->setValue(quot);
        }
    }
    else{cout << "invalid parameter list" << endl;}
}