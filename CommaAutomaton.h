#ifndef COMMAAUTOMATON_H
#define COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == ',') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // COMMAAUTOMATON_H

