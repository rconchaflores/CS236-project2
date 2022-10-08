#include "Parser.h"

#include <iostream>

Parser::Parser(vector<Token*>tokens){
    this->tokens = tokens;
    token = tokens[0];
    tokenIndex = 0;
}

Parser::~Parser(){
    for(auto each : tokens){
        delete each;
    }
};

void Parser::parse() {
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    parseScheme();
    parseSchemeList();

    match(TokenType::FACTS);
    match(TokenType::COLON);
    parseFactList();

    match(TokenType::RULES);
    match(TokenType::COLON);
    parseRuleList();

    match(TokenType::QUERIES);
    match(TokenType::COLON);
    parseQuery();
    parseQueryList();

    cout << "Success!\n";
    program.toString();
}

void Parser::match(TokenType t) {
    if(token->getType() == t){
        tokenIndex++;
        token = tokens[tokenIndex];
    }

    else {
        error();
    }
}

void Parser::parseScheme() {
    Predicate* newScheme = new Predicate();
    newScheme->setID(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    Parameter* newSchemeParameter = new Parameter(token->getDescription());
    newScheme->setParameter(newSchemeParameter);
    match(TokenType::ID);
    parseIdList(newScheme);
    match(TokenType::RIGHT_PAREN);

    program.addScheme(newScheme);
}

void Parser::parseSchemeList() {
    if(token->getType() == TokenType::ID){
        parseScheme();
        parseSchemeList();
    }
    else if(token->getType() == TokenType::FACTS){

    }
    else
        error();
}

void Parser::parseFactList() {
    if(token->getType() == TokenType::ID){
        parseFact();
        parseFactList();
    }
    else if(token->getType() == TokenType::RULES){

    }
    else
        error();
}

void Parser::parseRuleList() {
    if(token->getType() == TokenType::ID){
        parseRule();
        parseRuleList();
    }
    else if(token->getType() == TokenType::QUERIES){

    }
    else
        error();
}

void Parser::parseQuery() {
    Predicate* newQuery = parsePredicate();
    match(TokenType::QMARK);

    program.addQuery(newQuery);
}

void Parser::parseQueryList() {
    if(token->getType() == TokenType::ID){
        parseQuery();
        parseQueryList();
    }
    else if(token->getType() == TokenType::EOF_TOKEN){

    }
    else
        error();
}

void Parser::parseIdList(Predicate *pPredicate) {
    if(pPredicate == nullptr){
        cout << "null pointer" << endl;
        error();
    }
    if(token->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        Parameter* newParameter = new Parameter(token->getDescription());
        pPredicate->setParameter(newParameter);
        match(TokenType::ID);
        parseIdList(pPredicate);
    }
    else if(token->getType() == TokenType::RIGHT_PAREN){

    }
    else
        error();
}

void Parser::parseFact() {
    Predicate* newFact = new Predicate();
    newFact->setID(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    Parameter* newFactParameter = new Parameter(token->getDescription());
    newFact->setParameter(newFactParameter);
    program.makeDomain(token->getDescription());
    match(TokenType::STRING);
    parseStringList(newFact);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);

    program.addFact(newFact);
}

void Parser::parseRule() {
    Rule* newRule = new Rule();
    Predicate* head = parseHeadPredicate();
    newRule->setHeadPredicate(head);
    match(TokenType::COLON_DASH);
    Predicate* p = parsePredicate();
    newRule->addPredicate(p);
    parsePredicateList(newRule);
    match(TokenType::PERIOD);

    program.addRule(newRule);
}

Predicate* Parser::parsePredicate() {
    Predicate* newPredicate = new Predicate();
    newPredicate->setID(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    Parameter* newPredicateParameter = new Parameter(token->getDescription());
    newPredicate->setParameter(newPredicateParameter);
    parseParameter();
    parseParameterList(newPredicate);
    match(TokenType::RIGHT_PAREN);

    return newPredicate;
}

void Parser::parseStringList(Predicate *pPredicate) {
    if(token->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        Parameter* newParameter = new Parameter(token->getDescription());
        pPredicate->setParameter(newParameter);
        program.makeDomain(token->getDescription());
        match(TokenType::STRING);
        parseStringList(pPredicate);
    }
    else if (token->getType() == TokenType::RIGHT_PAREN){

    }
    else
        error();
}

Predicate * Parser::parseHeadPredicate() {
    Predicate* newPredicate = new Predicate();
    newPredicate->setID(token->getDescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    Parameter* newPredicateParameter = new Parameter(token->getDescription());
    newPredicate->setParameter(newPredicateParameter);
    match(TokenType::ID);
    parseIdList(newPredicate);
    match(TokenType::RIGHT_PAREN);

    return newPredicate;
}

void Parser::parsePredicateList(Rule* pRule) {
    if(token->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        Predicate* p = parsePredicate();
        pRule->addPredicate(p);
        parsePredicateList(pRule);
    }
    else if(token->getType() == TokenType::PERIOD){

    }
    else
        error();
}

void Parser::parseParameter() {
    if (token->getType() == TokenType::STRING) {
        match(TokenType::STRING);
    }

    else if (token->getType() == TokenType::ID) {
        match(TokenType::ID);
    }
}
void Parser::parseParameterList(Predicate* pPredicate) {
    if(token->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        Parameter* newParameter = new Parameter(token->getDescription());
        pPredicate->setParameter(newParameter);
        parseParameter();
        parseParameterList(pPredicate);
    }
    else if(token->getType() == TokenType::RIGHT_PAREN){

    }

    else
        error();
}

void Parser::error() {
    cout << "Failure!\n  ";
    cout << "(" << token->toString(token->getType()) << ",\"" << token->getDescription()
         << "\"," << token->getLine() << ")" << endl;
    exit(EXIT_SUCCESS);
}