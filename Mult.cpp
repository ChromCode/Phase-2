#include "Mult.h"

//MULT CLASS MEMBER IMPLEMENTATION 
//constructor 
Mult::Mult(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Mult made" << endl;*/}
//destructor
Mult::~Mult(){/*cout << "Mult destroyed" << endl;*/}

//check parameter list is valid
bool Mult::validator(){
        //cout << "running MULT validator..." << endl; 
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
                else{cerr << "IN ADD: bad convert of " << s << endl; return false;}
        }
        if(num_params<2 || num_params>12){cerr << "IN MUL: wrong number of parameters" << endl; return false;}
        return true;
}
//if validator is true, run add process 
void Mult::process(){
        if(validator()){
                //cout << "MUL processing..." << endl; 
                //sum values 
                float prod  = 1;
                //multiply converted parameters together 
                for(float f : converted_params){prod*=f;}
                int var_found = findVar(result_string);
	        switch(var_found){
			case 1: createdNUMERICS[result_string]->setValue(sum);
			case 2: createdREALS[result_string]->setValue(sum);
			default: return false;
	        }
        }
        else{cout << "IN MUL: invalid parameter list" << endl;}

}
