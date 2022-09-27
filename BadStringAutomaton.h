#ifndef BADSTRINGAUTOMATON_H
#define BADSTRINGAUTOMATON_H

#include "Automaton.h"

class BadStringAutomaton : public Automaton
{
private:
    void S1(const std::string& input){
        if(input[index] == '\''){
            inputRead++;
            index++;
            S2(input);
        }

        else if (input[index] == '\0')
            return;

        else {
            if(input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S1(input);
        }
    }

    void S2(const string& input){
        if(input[index] == '\0'){
            return;
        }

        else if(input[index] == '\''){
            inputRead++;
            index++;
            S1(input);
        }
    }

public:
    BadStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '\'') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }
};

#endif // BADSTRINGAUTOMATON_H

