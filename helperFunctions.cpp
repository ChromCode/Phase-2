#include "common.h"
#include "VAR.h"
#include "String.h"
#include "NUMERIC.h"
#include "CHAR.h"
#include "REAL.h"
#include "helperFunctions.h"
#include "variableHelpers.h"
#include "Label.h"
// #include "jumproto.h"
// #include "jump.h"
// #include "jumpz.h"
// #include "jumpgt.h"
// #include "Function.h"
#include "Add.h"
#include "Sub.h"
#include "Div.h"
#include "Mult.h"
#include "Out.h"

typedef void(*ScriptFunction)(stringstream& ss);
map<string, ScriptFunction> varMap = {
	{ "NUMERIC", &numericHelper },
	{ "REAL", &realHelper },
	{ "CHAR", &charHelper },
	{ "STRING", &stringHelper },
};

map<string, label*> createdLabels;
std::vector<std::thread> threadVector;
map<int,int> threadPairs;
// map<string, ScriptFunction> functionPointers;

void varHelper(stringstream& ss) {
	string str = "";
    stringstream iss(str);
	getline(ss, str, ',');
    cout << str << endl;
	getline(ss >> ws, str, ',');
    cout << str << endl;
    if( varMap.find(str) == varMap.end() ) {
        cerr << "Input line is invalid: " << str << endl;
        cerr << "No valid variable" << endl;
        exit(1);
    } else {
        (*(varMap[str]))(ss);
    }
}

void addHelper(stringstream& ss){
    stringstream iss(ss.str());
    vector<string> input;
    string in;
    iss >> ws;
    getline(iss, in, ' ');
    iss >> ws;
    while(getline(iss, in, ',')) {iss>>ws; input.push_back(in);}
    Add* add = new Add(input);
    add->process();
    delete(add);
}
void multHelper(stringstream& ss_in){
    stringstream ss(ss_in.str());
    vector<string> input;
    string in;
    ss >> ws;
    getline(ss, in, ' ');
    ss >> ws;
    while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
    Mult* mult = new Mult(input);
    mult->process();
    delete(mult);
}

void subHelper(stringstream& ss_in){
    stringstream ss(ss_in.str());
    vector<string> input;
    string in;
    ss >> ws;
    getline(ss, in, ' ');
    ss >> ws;
    while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
    Sub* sub = new Sub(input);
    sub->process();
    delete(sub);
}

void divHelper(stringstream& ss_in){
    stringstream ss(ss_in.str());
    vector<string> input;
    string in;
    ss >> ws;
    getline(ss, in, ' ');
    ss >> ws;
    while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
    Div* div = new Div(input);
    div->process();
    delete(div);
}
void outHelper(stringstream& ss_in){
    stringstream ss(ss_in.str());
    vector<string> input;
    string in;
    ss >> ws;
    getline(ss, in, ' ');
    ss >> ws;
    while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
    Out* out = new Out(input);
    out->process();
    delete(out);
}

void assignHelper( stringstream &ss ) {
    string str = "";
    string value = "";
    getline(ss>>ws, str, ',');
    getline(ss>>ws, value, ',');
    if( str[0] != '$' ) {
        cerr << "Must be a valid variable" << endl;
    }

    // this process looks for the correct variable, and assigns the wanted value
    while(true) {

        if( createdNUMERICS.find(str) != createdNUMERICS.end() ) {
            NUMERIC * obj = createdNUMERICS[str];
            int x;
            // if the wanted value is a variable
            if( value[0] == '$' ) {
                if( createdNUMERICS.find(value) != createdNUMERICS.end() ) {
                    NUMERIC * toAssign = createdNUMERICS[value];
                    // assign the variables value to the original variable
                    x = toAssign -> getValue(); 
                }
            } else {
                x = stoi(value);
            }
            // This should throw an error if the types do not match
            obj -> setValue(x);
            cout << "Variable " << str << " is now equal to " << x << endl;
            break;

        // repeat the process for all other parts
        } else if( createdREALS.find(str) != createdREALS.end() ) {
            double x;
            REAL * obj = createdREALS[str];
            if( value[0] == '$' ) {
                if( createdREALS.find(value) != createdREALS.end() ) {
                    REAL * toAssign = createdREALS[value];
                    x = toAssign -> getValue();
                }
            } else {
                x = stod(value);
            }
            obj -> setValue(x);
            cout << "Variable " << str << " is now equal to " << x << endl;
            break;

        } else if( createdCHARS.find(str) != createdCHARS.end() ) {
            CHAR * obj = createdCHARS[str];
            char x;
            if( value[0] == '$' ) {
                if( createdCHARS.find(value) != createdCHARS.end() ) {
                    CHAR * toAssign = createdCHARS[value];
                    x = toAssign -> getValue();
                }
            } else {
                x = value[0];
            }
            obj -> setValue(x);
            cout << "Variable " << str << " is now equal to " << x << endl;
            break;

        } else if( createdSTRINGS.find(str) != createdSTRINGS.end() ) {
            STRING * obj = createdSTRINGS[str];
            if( value[0] == '$' ) {
                if( createdSTRINGS.find(value) != createdSTRINGS.end() ) {
                    STRING * toAssign = createdSTRINGS[value];
                    value = toAssign -> getValue();
                }
            } // else set it to the string
            obj -> setValue(value);
            cout << "Variable " << str << " is now equal to " << value << endl;
            break;

        } else {
            cerr << "Variable does not exist" << endl;
            break;
        }
    }
}

void setStrHelper( stringstream &ss ) {
	string str = "";
	getline(ss, str, ',');
	STRING * obj = createdSTRINGS[str];
	if( obj == NULL ) {
		cerr << "Variable " << str << " does not exit" << endl;
	} else {
		int i;
		char a;
        getline(ss >> ws, str, ',');
	    i = stoi(str.c_str());
	    getline(ss >> ws, str, ',');
	    stringstream iss(str);
	    iss >> a;
	    obj -> setChar(i, a);
        obj -> print();
	}
}

void getStrHelper( stringstream &ss ) {
    string str = "";
    getline(ss, str, ',');
    STRING * obj = createdSTRINGS[str];
    if( obj == NULL ) {
    	cerr << "Variable " << str << " does not exist" << endl;
    	throw;
    }
    getline(ss, str, ',');
	int x;
    char a;
    if( str.c_str()[0] == '$' ) {
    	NUMERIC * myINT = createdNUMERICS[str];
        x = myINT -> getValue();
    } else {
        x = stoi(str);
    }
    getline(ss, str, ',');
    CHAR * newObj = createdCHARS[str];
    if( newObj == NULL ) {
        cerr << "Variable " << str << " does not exist" << endl;
    } else {
        a = obj -> getChar(x);
        newObj -> setValue(a);
        newObj -> print();
    }
}

void labelHelper(stringstream&ss) {
    string str = "";
    getline(ss, str, ' ');
    label * A = new label();
    if (A != NULL) {
        A->initialize(ss, counter);
        createdLabels.insert(pair<string,label*> (str, A));
    }
}

// void JMPHelper(stringstream&ss) {
//     string str = "";
//     getline(ss, str, ' ');
//     jump* A = new jump();
//     if (A != NULL) {
//         A -> initialize(ss, counter);
//         map<string, label*>::iterator p;
//         p = createdLabels.find(str);
//         if (p != createdLabels.end()) {
//             counter = p->second->linenumber;
//             cout << "Jumping to label " << A->labelname << endl;
//         } else {
//             cerr << "label not found\n";
//             delete(A);
//             exit(1);
//         }
//         delete(A);
//     }
// }

// void  JMPZHelper(stringstream&ss) {
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpz* A = new jumpz();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A->labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             int i = obj -> getNumericValue();
//             if( i == 0 ) {
//                 counter = foundLabel -> linenumber;
//             }
//         }
//     } else {
//         cout << str << endl;
//         int i = stoi(str);
//         if( i == 0 ) {
//             counter = foundLabel -> linenumber;
//         }
//     } 
//     delete(A);
// }

// void  JMPNZHelper(stringstream&ss) {
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpz* A = new jumpz();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A->labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             int i = obj -> getNumericValue();
//             if( i != 0 ) {
//                 counter = foundLabel -> linenumber;
//             }
//         }
//     } else {
//         cout << str << endl;
//         int i = stoi(str);
//         if( i != 0 ) {
//             counter = foundLabel -> linenumber;
//         }
//     } 
//     delete(A);
// }

// void JMPGTHelper(stringstream&ss) {
//     int first;
//     int second;
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpgt* A = new jumpgt();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A-> labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             first = obj -> getNumericValue();
//         }
//     } else {
//         first = stoi(str);
//     }

//     getline(iss >> ws, str, ',');

//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             second = obj -> getNumericValue();
//         }
//     } else {
//         second = stoi(str);
//     }
//     if ( first > second ) {
//         counter = foundLabel -> linenumber;
//     }

//     delete(A);
// }

// void JMPGTEHelper(stringstream&ss) {
//     int first;
//     int second;
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpgt* A = new jumpgt();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A-> labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             first = obj -> getNumericValue();
//         }
//     } else {
//         first = stoi(str);
//     }

//     getline(iss >> ws, str, ',');

//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             second = obj -> getNumericValue();
//         }
//     } else {
//         second = stoi(str);
//     }
//     if ( first >= second ) {
//         counter = foundLabel -> linenumber;
//     }

//     delete(A);
// }

// void JMPLTHelper(stringstream&ss) {
//     int first;
//     int second;
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpgt* A = new jumpgt();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A-> labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             first = obj -> getNumericValue();
//         }
//     } else {
//         first = stoi(str);
//     }

//     getline(iss >> ws, str, ',');

//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             second = obj -> getNumericValue();
//         }
//     } else {
//         second = stoi(str);
//     }
//     if ( first < second ) {
//         counter = foundLabel -> linenumber;
//     }

//     delete(A);
// }

// void JMPLTEHelper(stringstream&ss) {
//     int first;
//     int second;
//     string str = "";
//     stringstream iss(ss.str());
//     getline(ss, str, ' ');
//     jumpgt* A = new jumpgt();
//     // A -> canJump();
//     A->initialize(iss, counter);
//     getline(iss, str, ',');
//     label * foundLabel = createdLabels[A-> labelname];
//     if( foundLabel == NULL ) {
//         cerr << "No label Found" << endl;
//         exit(1);
//     }
//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             first = obj -> getNumericValue();
//         }
//     } else {
//         first = stoi(str);
//     }

//     getline(iss >> ws, str, ',');

//     if (str[0] == '$') {
//         cout << str << endl;
//         VAR * obj = createdVariables[str];
//         if (obj == NULL) {
//             cerr << "Variable does not exist" << endl;
//             exit(1);
//         } else {
//             second = obj -> getNumericValue();
//         }
//     } else {
//         second = stoi(str);
//     }
//     if ( first <= second ) {
//         counter = foundLabel -> linenumber;
//     }

//     delete(A);
// }

void sleepHelper(stringstream &ss) {
	string str = "";
	getline(ss, str, ' ');
	getline(ss, str, ',');
	long long x;
	if( str.c_str()[0] == '$' ) {
		NUMERIC * obj = createdNUMERICS[str.c_str()];
		if( obj == NULL ) {
			cout << "The variable: " << str.c_str() << " does not exist" << endl;
			throw;
		} else {
			x = obj -> getValue();
    	    cout << "Waiting " << x << " seconds" << endl;
			std::chrono::seconds dura( x);
    	    std::this_thread::sleep_for( dura );
    	    cout << "Done!" << endl;
		}
	} else {
		stringstream iss(str.c_str());
		iss >> x;
	    if( iss.fail() ) {
            cout << "Parameter does not match required type REAL or NUMERIC" << endl;
            iss.clear();
            throw;
        } else {
    	    cout << "Waiting " << x << " seconds" << endl;
    	    std::chrono::seconds dura(x);
    	    std::this_thread::sleep_for( dura );
    	    cout << "Done!" << endl;
        }
	}
}

void threadParseHelper( stringstream &ss ){
    cout << "We're parsing for a thread begin and end" << endl;
    bool foundEnd = false;
    int subCount = counter;
    for(subCount; subCount <= lines.size()-1; subCount++ ){
        string fileLine = lines[subCount];
        string name = "";
        stringstream iss(fileLine);// Load line to the string stream
        getline(iss >> ws, name);
        if( name == "THREAD_END") {
            threadPairs.emplace(std::make_pair(int(counter), int(subCount)));
            foundEnd = true;
            break;
        }
    }
    if ( !foundEnd ) {
        cerr << "No thread end to match" << endl;
        exit(1);
    }
}

void aquireLock(stringstream &ss){
    string str = "";
        getline(ss>>ws, str, ',');
        if( str[0] != '$' ) {
            cerr << "Must be a valid variable" << endl;
        }

    if( createdNUMERICS.find(str) != createdNUMERICS.end() ) {
            NUMERIC * var = createdNUMERICS[str];
            while(var->locked()){
                //wait
            }
            var->setLock();
        } else if( createdREALS.find(str) != createdREALS.end() ) {
            REAL * var = createdREALS[str];
            while(var->locked()){
                //wait
            }
            var->setLock();
        } else if( createdCHARS.find(str) != createdCHARS.end() ) {
            CHAR * var = createdCHARS[str];
            while(var->locked()){
                //wait
            }
            var->setLock();
        } else if( createdSTRINGS.find(str) != createdSTRINGS.end() ) {
            STRING * var = createdSTRINGS[str];
            while(var->locked()){
                //wait
            }
            var->setLock();
        } else {
            cerr << "Variable does not exist" << endl;
        }
}

void releaseLock(stringstream &ss){
    string str = "";
        getline(ss>>ws, str, ',');
        if( str[0] != '$' ) {
            cerr << "Must be a valid variable" << endl;
        }

    if( createdNUMERICS.find(str) != createdNUMERICS.end() ) {
            NUMERIC * var = createdNUMERICS[str];
            var->unLock();

        // repeat the process for all other cases
        } else if( createdREALS.find(str) != createdREALS.end() ) {
            REAL * var = createdREALS[str];
            var->unLock();

        } else if( createdCHARS.find(str) != createdCHARS.end() ) {
            CHAR * var = createdCHARS[str];
            var->unLock();

        } else if( createdSTRINGS.find(str) != createdSTRINGS.end() ) {
            STRING * var = createdSTRINGS[str];
            var->unLock();
            
        } else {
            cerr << "Variable does not exist" << endl;
        }
}

void threadExecuteHelper( int start ){
    cout << "We are now executing a thread" << endl;
    int thread_end = threadPairs[start];
    int intern_counter = start;
    while(intern_counter < thread_end){
        string name = "";
        string fileLine = lines[intern_counter];
        stringstream iss(fileLine);// Load line to the string stream
        getline(iss >> ws, name, ' ');
        if( functionPointers.find(name) == functionPointers.end() ) {
            cerr << "Input line is invalid: " << name << endl;
            cerr << "No valid OPCODE" << endl;
            exit(1);
        } else {
            cout << name << endl;
            cout << iss.str() << endl;
            (*(functionPointers[name]))(iss);
        }
        intern_counter++;
    }
}

void barrierHelper( stringstream &ss ) {
    for (std::thread &t : threadVector ) {
        t.join();
    }
}

void doNothing( stringstream &ss ){}

void deleteVariables() {
	for(map<string, NUMERIC*>::iterator itr = createdNUMERICS.begin(); itr != createdNUMERICS.end(); itr++) {
        cout << "Deleting NUMERIC Var: " << itr -> first << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    for(map<string, REAL*>::iterator itr = createdREALS.begin(); itr != createdREALS.end(); itr++) {
        cout << "Deleting REAL Var: " << itr -> first << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    for(map<string, CHAR*>::iterator itr = createdCHARS.begin(); itr != createdCHARS.end(); itr++) {
        cout << "Deleting CHAR Var: " << itr -> first << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    for(map<string, STRING*>::iterator itr = createdSTRINGS.begin(); itr != createdSTRINGS.end(); itr++) {
        cout << "Deleting STRING Var: " << itr -> first << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    for(map<string, ScriptFunction>::iterator itr = varMap.begin(); itr != varMap.end(); itr++) {
        itr -> second = NULL;
    }
    for(map<string, label*>::iterator itr = createdLabels.begin(); itr != createdLabels.end(); itr++) {
        cout << itr -> first << " " << itr -> second -> name << " : " << itr -> second -> linenumber << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    // createdVariables.clear();
    createdLabels.clear();
    varMap.clear();
}