#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <iostream>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;
    int inputRead{};

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(string& input);
    void printTokens();
    vector<Token*> getTokens();

    // TODO: add other public methods here

};

#endif // LEXER_H

