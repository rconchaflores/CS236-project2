#include "Lexer.h"
#include "Parser.h"
#include <fstream>

int main(int argc, char** argv) {
    ifstream inputFile(argv[1]);
    string file;
    file.assign((istreambuf_iterator<char>(inputFile)),(istreambuf_iterator<char>()));

    Lexer* lexer = new Lexer();
    lexer->Run(file);
    //lexer->printTokens();
    vector<Token*> myTokens = lexer->getTokens();
    Parser* myParser = new Parser(myTokens);
    myParser->parse();

    delete lexer;
    delete myParser;
    return 0;
}