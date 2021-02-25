#include <iostream>
#include <fstream>

#include "lexer.h"


int main(int argc, char** argv) {

    Lexer *lexer = new Lexer(std::string("asdasdasdasd"));
    lexer->next_token();
    while (lexer->token->token_type != TokenEOF) {
        std::cout << lexer->token->value;
        lexer->next_token();
    }

    return 0;
}
