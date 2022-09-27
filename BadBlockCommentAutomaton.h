#ifndef BADBLOCKCOMMENTAUTOMATON_H
#define BADBLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"

class BadBlockCommentAutomaton : public Automaton
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
            return;

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
            return;
        }

        else if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        }

        else if (input[index] == '#')
            Serr();

        else{
            if(input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S2(input);
        }

    }

public:
    BadBlockCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

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

#endif // BADBLOCKCOMMENTAUTOMATON_H

