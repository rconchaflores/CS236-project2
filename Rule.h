#ifndef RULE_H
#define RULE_H

#include "Predicate.h"
#include <set>

class Rule
{
private:
    Predicate* headPredicate;
    vector<Predicate*> bodyPredicates;

public:
    Rule(){}
    ~Rule(){}
    string ruleToString(){
        string output;
        output = headPredicate->schemeToString() + " :- ";
        for(unsigned int i = 0; i < bodyPredicates.size()-1; i++){
            output += bodyPredicates[i]->schemeToString() + ",";
        }
        output += bodyPredicates[bodyPredicates.size()-1]->toString();

        return output;
    }
    void addPredicate(Predicate* p){
        bodyPredicates.push_back(p);
    }

    void setHeadPredicate(Predicate *headP) {
        Rule::headPredicate = headP;
    }
};

#endif // RULE_H
