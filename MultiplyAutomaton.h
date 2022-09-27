#ifndef MULTIPLYAUTOMATON_H
#define MULTIPLYAUTOMATON_H

#include "Automaton.h"

class MultiplyAutomaton : public Automaton
{
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == '*') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // MULTIPLYAUTOMATON_H

