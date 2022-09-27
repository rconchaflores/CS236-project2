#ifndef LEFTPARENAUTOMATON_H
#define LEFTPARENAUTOMATON_H

#include "Automaton.h"

class LeftParenAutomaton : public Automaton
{
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == '(') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // LEFTPARENAUTOMATON_H

