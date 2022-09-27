#include "Token.h"

Token::Token(TokenType type, string description, int line) {
    myType = type;
    myDescription = description;
    myLine = line;
}

TokenType Token::getType(){
    return myType;
}

string Token::getDescription(){
    return myDescription;
}

int Token::getLine(){
    return myLine;
}

void Token::setDescription(string d) {
    myDescription = d;
}
string Token::toString(TokenType myType){
    string returnType;

    switch(myType){
        case TokenType::COLON:
            returnType = "COLON";
            break;
        case TokenType::COLON_DASH:
            returnType = "COLON_DASH";
            break;
        case TokenType::COMMA:
            returnType = "COMMA";
            break;
        case TokenType::PERIOD:
            returnType = "PERIOD";
            break;
        case TokenType::QMARK:
            returnType = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            returnType = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            returnType = "RIGHT_PAREN";
            break;
        case TokenType::ADD:
            returnType = "ADD";
            break;
        case TokenType::MULTIPLY:
            returnType = "MULTIPLY";
            break;
        case TokenType::SCHEMES:
            returnType = "SCHEMES";
            break;
        case TokenType::FACTS:
            returnType = "FACTS";
            break;
        case TokenType::RULES:
            returnType = "RULES";
            break;
        case TokenType::QUERIES:
            returnType = "QUERIES";
            break;
        case TokenType::ID:
            returnType = "ID";
            break;
        case TokenType::STRING:
            returnType = "STRING";
            break;
        case TokenType::COMMENT:
            returnType = "COMMENT";
            break;
        case TokenType::EOF_TOKEN:
            returnType = "EOF";
            break;
        case TokenType::UNDEFINED:
            returnType = "UNDEFINED";
            break;
    }

    return returnType;
}