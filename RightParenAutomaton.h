#ifndef RIGHTPARENAUTOMATON_H
#define RIGHTPARENAUTOMATON_H

#include "Automaton.h"

class RightParenAutomaton : public Automaton
{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == ')') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // RIGHTPARENAUTOMATON_H

