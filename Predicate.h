#ifndef PREDICATE_H
#define PREDICATE_H

#include "Parameter.h"
#include <vector>

class Predicate
{
private:
    string id;
    vector<Parameter*> parameters;

public:
    Predicate()= default;
    ~Predicate()= default;
    void toString(){

    }

};

#endif // PREDICATE_H
