#include "lexer.h"

#include <iostream>

namespace TMPL_PARSER {

// Lexer classes
void Lexer::next() {
    std::cout << "next\n";
}

void Lexer::next_token() {
    std::cout << "next_token\n";
}

Lexer::Lexer(std::string data) {
    this -> data = data;
    this -> index = 0;
    this -> token = new Token();
    this -> next();
}

// Token classes
Token::Token(TokenType token_type = TokenEmpty, std::string value = "") {
    this -> token_type = token_type;
    this -> value = value;
}

}