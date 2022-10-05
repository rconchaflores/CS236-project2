#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "DatalogProgram.h"

class Parser
{
private:
    vector<Token*>tokens;
    Token* token = tokens[0];

public:
    explicit Parser(vector<Token*>tokens);
    ~Parser();

    void parse(); //Once you find a Token whose type does not fit the grammar, you must stop
    //Easiest solution: throw the token, and use a try-catch block in the parse() function


    /*Returning a DatalogProgram object will be helpful because you are essentially constructing
     * your program as you parse your tokens. Once you are done parsing, you will have a finished
     * Datalog program that has the lists of schemes, facts, rules and queries that will be needed
     * in the next project*/
    //DatalogProgram parse(); CHOOSE void parse() or CHOOSE this option
    void match(TokenType t);

    void parseScheme();

    void parseSchemeList();

    void parseFactList();

    void parseRuleList();

    void parseQuery();

    void parseQueryList();

    void parseIdList();

    void parseFact();

    void parseRule();

    void parsePredicate();

    void parseStringList();

    void parseHeadPredicate();

    void parsePredicateList();
};

#endif // PARSER_H
