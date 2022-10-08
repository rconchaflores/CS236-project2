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
    string toString(){
        string output;
        output = getID() + "(";
        for(unsigned int i = 0; i < parameters.size()-1; i++){
            output += parameters[i]->getParameter() + ",";
        }
        output += parameters[parameters.size()-1]->getParameter() + ").";
        return output;
    }
    string schemeToString(){
        string output;
        output = getID() + "(";
        for(unsigned int i = 0; i < parameters.size()-1; i++){
            output += parameters[i]->getParameter() + ",";
        }
        output += parameters[parameters.size()-1]->getParameter() + ")";

        return output;
    }

    string queryToString(){
        string output;
        output = getID() + "(";
        for(unsigned int i = 0; i < parameters.size()-1; i++){
            output += parameters[i]->getParameter() + ",";
        }
        output += parameters[parameters.size()-1]->getParameter() + ")?";

        return output;
    }

    void setID(string thisID){
        id = thisID;
    }

    string getID(){
        return id;
    }

    void setParameter(Parameter* parameter){
        parameters.push_back(parameter);
    }

};

#endif // PREDICATE_H
