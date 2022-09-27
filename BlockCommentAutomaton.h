#ifndef BLOCKCOMMENTAUTOMATON_H
#define BLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"

class BlockCommentAutomaton : public Automaton
{
private:

    void S1(const std::string& input){
        if (input[index] == '|'){
            inputRead++;
            index++;
            S2(input);
        }
        else
            Serr();
    }

    void S2(const std::string& input){
        if (input[index] == '\0')
            Serr();

        else if (input[index] != '|'){
            if(input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S2(input);
        }

        else {
            inputRead++;
            index++;
            S3(input);
        }
    }

    void S3(const std::string& input) {
        if (input[index] == '\0'){
            Serr();
        }

        else if (input[index] == '#') {
            inputRead++;
        }

        else if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        }

        else{
            if(input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S2(input);
        }

    }

public:
    BlockCommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

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

#endif // BLOCKCOMMENTAUTOMATON_H