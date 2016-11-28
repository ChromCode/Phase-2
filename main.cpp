#include "common.h"
#include "helperFunctions.h"
#include "Label.h"

typedef void(*ScriptFunction)(stringstream& ss);
map<string, ScriptFunction> functionPointers;
map<int, string> lines;
int counter;

int main() {
    functionPointers["VAR"] = &varHelper;
    functionPointers["ADD"] = &addHelper;
    functionPointers["SUB"] = &subHelper;
    functionPointers["MUL"] = &multHelper;
    functionPointers["DIV"] = &divHelper;
    functionPointers["ASSIGN"] = &assignHelper;
    functionPointers["OUT"] = &outHelper;
    functionPointers["SET_STR_CHAR"] = &setStrHelper;
    functionPointers["GET_STR_CHAR"] = &getStrHelper;
    functionPointers["LABEL"] = &labelHelper;
    // functionPointers["JMP"] = &JMPHelper;
    // functionPointers["JMPZ"] = &JMPZHelper;
    // functionPointers["JMPNZ"] = &JMPNZHelper;
    // functionPointers["JMPGT"] = &JMPGTHelper;
    // functionPointers["JMPGTE"] = &JMPGTEHelper;
    // functionPointers["JMPLT"] &JMPLTHelper
    // functionPointers["JMPLTE"] &JMPLTEHelper
    functionPointers["SLEEP"] = &sleepHelper;
    functionPointers["THREAD_BEGIN"] = &threadParseHelper;

    string line ="";
    ifstream readFile("Program.mis");
    string name ="";
    int lineNumber = 0;
    // Loop through file filling a map of line numbers to lines
    while(getline(readFile, line)) {
        if ( lineNumber >= 255) {
            cerr << "Program is too large to continue ... exiting at line " << lineNumber << endl;
        }
        if( line.size() > 1024 ) {
            cerr << "This can't be this long" << endl;
            exit(1);
        }
        lines[lineNumber] = line;
        lineNumber++;
    }

    // We now create labels
    counter = 0;
    while( counter <= lines.size()-1 ) {
        string fileLine = lines[counter];
        stringstream iss(fileLine);
        getline(iss, name, ' ');
        if ( name == "LABEL" ) {
            (*(functionPointers["LABEL"]))(iss);
        } else if (name == "THREAD_BEGIN") {
            (*(functionPointers["THREAD_BEGIN"]))(iss);
        }
        counter++;
    }
    counter = 0;
    functionPointers["LABEL"] = &doNothing;
    functionPointers["THREAD_BEGIN"] = &threadExecuteHelper;

    // Loop throught the line map and parse our OP code
    // Then we send it off to a helper function
    for(counter; counter <= lines.size()-1; counter++ ){
        string fileLine = lines[counter];
        stringstream iss(fileLine);// Load line to the string stream
        getline(iss, name, ' ');
        if( functionPointers.find(name) == functionPointers.end() ) {
            cerr << "Input line is invalid: " << name << endl;
            cerr << "No valid OPCODE" << endl;
            exit(1);
        } else if (name=="THREAD_BEGIN"){
            int thread_end = threadPairs[counter];
            threadExecuteHelper(counter, thread_end);
            counter = thread_end+1;
        } else {
            (*(functionPointers[name]))(iss);
        }
    }
    deleteVariables();
    functionPointers.clear();
    lines.clear();
    readFile.close();
    return 0;
}
