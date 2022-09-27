#ifndef QMARKAUTOMATON_H
#define QMARKAUTOMATON_H

#include "Automaton.h"

class QMarkAutomaton : public Automaton
{
public:
    QMarkAutomaton() : Automaton(TokenType::QMARK) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == '?') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // QMARKAUTOMATON_H

