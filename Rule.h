#ifndef RULE_H
#define RULE_H

#include
#include "Predicate.h"
#include <set>

class Rule
{
private:
    Predicate* head;
    vector<Predicate*> body;

public:
    Rule();
    ~Rule();
    void toString();

};

#endif // RULE_H
