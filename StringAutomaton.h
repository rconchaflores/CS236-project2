#ifndef STRINGAUTOMATON_H
#define STRINGAUTOMATON_H

#include "Automaton.h"

class StringAutomaton : public Automaton
{
private:
    void S1(const std::string& input){
        if(input[index] == '\0')
            Serr();

        else if(input[index] != '\''){
            if(input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S1(input);
        }

        else {
            inputRead++;
            index++;
            S2(input);
        }
    }

    void S2(const string& input){
        if(input[index] == '\''){
            inputRead++;
            index++;
            S1(input);
        }

        else {
            return;
        }
    }

public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

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

#endif // STRINGAUTOMATON_H

