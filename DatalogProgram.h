#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "Token.h"
#include "Predicate.h"
#include "Rule.h"
#include <set>

class DatalogProgram
{
private:
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Rule*> rules;
    vector<Predicate*> queries;
    set<string> domain;
public:
    DatalogProgram();
    ~DatalogProgram();
    void toString(); //Return a DatalogProgram object from the parser and then traverse this structure and use
    // `toString` as needed to print the required output.
    //To integrate this project with later projects, be sure to have a way to get the lists of schemes,
    // facts, rules and queries out of the DatalogProgram.
    //You must create classes for DatalogProgram, Rule, Predicate, and Parameter to hold the internal representation
    // of a datalog program. Each class must have a toString method and the output of the program must be formed by these toString methods (not by the parse methods).

};

#endif // DATALOGPROGRAM_H
