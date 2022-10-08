#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "Token.h"
#include "Predicate.h"
#include "Rule.h"
#include <set>
#include <iostream>

class DatalogProgram
{
private:
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Rule*> rules;
    vector<Predicate*> queries;
    set<string> domain; //set of parameters in FACTS
public:
    DatalogProgram(){}
    ~DatalogProgram(){}
    void toString() {
        cout << "Schemes(" << schemes.size() << "):\n";
        for(unsigned int i = 0; i < schemes.size(); i++){
            cout << "  " << schemes[i]->schemeToString() << "\n";
        }
        cout << "Facts(" << facts.size() << "):\n";
        for(unsigned int i = 0; i < facts.size(); i++){
            cout << "  " << facts[i]->toString() << "\n";
        }
        cout << "Rules(" << rules.size() << "):\n";
        for(unsigned int i = 0; i < rules.size(); i++){
            cout << "  " << rules[i]->ruleToString() << "\n";
        }
        cout << "Queries(" << queries.size() << "):\n";
        for(unsigned int i = 0; i < queries.size(); i++){
            cout << "  " << queries[i]->queryToString() << "\n";
        }
        cout << "Domain(" << domain.size() << "):\n";
        for(string dom : domain){
            cout << "  " << dom << endl;
        }
    }

    void makeDomain(string dom) {
        domain.insert(dom);
    }

    void addScheme(Predicate* scheme){
        schemes.push_back(scheme);
    }

    void addFact(Predicate* fact){
        facts.push_back(fact);
    }

    void addRule(Rule* rule){
        rules.push_back(rule);
    }

    void addQuery(Predicate* query){
        queries.push_back(query);
    }
};

#endif // DATALOGPROGRAM_H
