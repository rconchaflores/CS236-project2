#include "Lexer.h"
#include "Token.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "AddAutomaton.h"
#include "MultiplyAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "BadStringAutomaton.h"
#include "CommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "BadBlockCommentAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(size_t i = 0; i < automata.size(); i++){
        delete automata[i];
    }
    automata.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new BadStringAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new BadBlockCommentAutomaton());
    automata.push_back(new CommentAutomaton());
}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;

    while(!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        if (isspace(input.front())) {
            if (input.front()== '\n')
                ++lineNumber;
            input = input.substr(1);
            continue;

        }

        for (Automaton* automaton : automata) {
            inputRead = automaton->Start(input);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }

        if (maxRead > 0){
            Token* newToken = maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            string newDescription = input.substr(0, maxRead);
            newToken->setDescription(newDescription);
            if (newToken->getType() != TokenType::COMMENT){
                tokens.push_back(newToken);
            }
        }

        else {
            maxRead = 1;
            string newDescription = input.substr(0, maxRead);
            auto* newToken = new Token(TokenType::UNDEFINED, newDescription, lineNumber);
            newToken->setDescription(newDescription);
            tokens.push_back(newToken);
        }

        input = input.substr(maxRead);
    }

    Token* eofToken = new Token(TokenType::EOF_TOKEN, "", lineNumber);
    tokens.push_back(eofToken);
}

void Lexer::printTokens(){
    for (size_t i = 0; i < tokens.size(); i++){
        cout << "(" << tokens[i]->toString(tokens[i]->getType()) << ",\"" << tokens[i]->getDescription() << "\"," << tokens[i]->getLine() << ")" << endl;
    }
    cout << "Total Tokens = " << tokens.size() << endl; //don't put a new line after Total Tokens
}

vector<Token*> Lexer::getTokens(){
    return tokens;
}