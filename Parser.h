#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "DatalogProgram.h"

class Parser
{
private:
    vector<Token*>tokens;
    Token* token;
    DatalogProgram program;
    int tokenIndex;

public:
    explicit Parser(vector<Token*>tokens);
    ~Parser();

    void parse();
    void match(TokenType t);
    void parseScheme();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQuery();
    void parseQueryList();
    void parseIdList(Predicate *pPredicate);
    void parseFact();
    void parseRule();
    Predicate* parsePredicate();
    void parseStringList(Predicate *pPredicate);
    Predicate * parseHeadPredicate();
    void parsePredicateList(Rule* pRule);
    void parseParameter();
    void parseParameterList(Predicate* pPredicate);

    void error();
};

#endif // PARSER_H
