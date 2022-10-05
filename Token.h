#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cctype> //checks whitespace (isspace), isalpha(myChar), isalnum(myChar)

using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    QMARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    ADD,
    MULTIPLY,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    COMMENT,
    STRING,
    UNDEFINED,
    EOF_TOKEN,
    ERROR
};

class Token
{
private:
    TokenType myType;
    string myDescription;
    int myLine;

public:
    Token(TokenType type, string description, int line);

    TokenType getType();
    string getDescription();
    int getLine();
    void setDescription(string);
    string toString(TokenType);
};

#endif // TOKEN_H

