#include "lexer.h"

#include <iostream>

// Lexer classes
void TMPL_PARSER::Lexer::next() {
    std::cout << "next\n";
}

void TMPL_PARSER::Lexer::next_token() {
    std::cout << "next_token\n";
}

TMPL_PARSER::Lexer::Lexer(char **data) {
    this -> data = data;
    this -> index = 0;
    this -> token = nullptr;
    this -> next();
}

// Token classes
TMPL_PARSER::Token::Token(TMPL_PARSER::TokenType token_type = TokenEmpty, char **value = nullptr) {
    this -> token_type = token_type;
    this -> value = value;
}
