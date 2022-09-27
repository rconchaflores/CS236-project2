#ifndef IDAUTOMATON_H
#define IDAUTOMATON_H

#include "Automaton.h"
#include <cctype>

class IDAutomaton : public Automaton
{
private:
    void S1(const std::string& input){
        if(isalnum(input[index])){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            return;
        }
    }

public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input){
        if (isalpha(input[index])) {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }
};

#endif // IDAUTOMATON_H

