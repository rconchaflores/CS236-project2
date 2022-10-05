#include "Parser.h"

#include <utility>
#include <iostream>

Parser::Parser(vector<Token*>tokens){
    this->tokens = std::move(tokens);
}

Parser::~Parser() = default;

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

    //DATALOGPROGRAM Object to create set of domain strings
    // program.makeDomain();
    //DATALOGPOGRAM Object toString
    //cout << "Success!\n" << program.toString();
}

void Parser::match(TokenType t) {
    if(token->getType() == t)
    {
        token = tokens[0];
        tokens.erase(tokens.begin());
    }

    else {
        cout << "Failure!\n";
        cout << "(" << token->toString(token->getType()) << ",\"" << token->getDescription()
             << "\"," << token->getLine() << ")" << endl;
        exit(EXIT_SUCCESS);
    }
}

void Parser::parseScheme() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIdList();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parseSchemeList() {
    if(token->getType() != TokenType::FACTS){
        parseScheme();
        parseSchemeList();
    }
}

void Parser::parseFactList() {
    if(token->getType() != TokenType::RULES){
        parseFact();
        parseFactList();
    }
}

void Parser::parseRuleList() {
    if(token->getType() != TokenType::QUERIES){
        parseRule();
        parseRuleList();
    }
}

void Parser::parseQuery() {
    parsePredicate();
    match(TokenType::QMARK);
}

void Parser::parseQueryList() {
    if(token->getType() != TokenType::EOF_TOKEN){
        parseQuery();
        parseQueryList();
    }
}

void Parser::parseIdList() {
    if(token->getType() != TokenType::RIGHT_PAREN){
        match(TokenType::COMMA);
        match(TokenType::ID);
        parseSchemeList();
    }
}

void Parser::parseFact() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    parseStringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
}

void Parser::parseRule() {
    parseHeadPredicate();
    match(TokenType::COLON_DASH);
    parsePredicate();
    parsePredicateList();
    match(TokenType::PERIOD);
}

void Parser::parsePredicate() {

}

void Parser::parseStringList() {

}

void Parser::parseHeadPredicate() {

}

void Parser::parsePredicateList() {

}

//Return a DatalogProgram object from the parser and then traverse this structure and use `toString` as needed to print the required output.