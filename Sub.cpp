#include "Sub.h"

//constructor
Sub::Sub(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Sub made" << endl;*/}
//destructor
Sub::~Sub(){/*cout << "Sub destroyed" << endl;*/}

//check that parameter number and types are valid
bool Sub::validator(){
        //cout << "running SUB validator..." << endl;
        //parameter counter
        int num_params=0;
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
            else{cerr << "IN SUB: bad convert of " << s << endl; return false;}
        }
        if(num_params!=2){cerr << "IN SUB: wrong number of parameters" << endl; return false;}
        return true;
}

//if validator is true, run add process
void Sub::process(){
    if(validator()){
        //cout << "SUB processing..." << endl;
        //take the difference
        float diff = converted_params[0] - converted_params[1];
        int var_found = findVar(result_string);
        switch(var_found){
            case 1: createdNUMERICS[result_string]->setValue(diff);
            case 2: createdREALS[result_string]->setValue(diff);
        }
    }
    else{cerr << "IN SUB: invalid parameter list" << endl;}
}