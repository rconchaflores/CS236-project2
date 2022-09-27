#ifndef COMMENTAUTOMATON_H
#define COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton
{
private:

    void S1(const std::string& input){
        if(input[index] == '|')
            Serr();
        else
            S2(input);
    }
    void S2(const std::string& input){
        if (input[index] == '\0' || input[index] == '\n'){
            return;
        }
        else {
            inputRead++;
            index++;
            S2(input);
        }
    }

public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '#') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }
};

#endif // COMMENTAUTOMATON_H

