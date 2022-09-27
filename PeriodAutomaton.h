#ifndef PERIODAUTOMATON_H
#define PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const string& input){
        if (input[index] == '.') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // PERIODAUTOMATON_H

