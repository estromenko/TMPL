#ifndef TMPL_LEXER_H
#define TMPL_LEXER_H

#include <iostream>
#include <string>

enum TokenType {
    TokenIdentifier,

    TokenEOF,
};

class Token {
public:
    TokenType token_type;
    std::string value;

    Token(TokenType token_type, std::string value) {
        this->token_type = token_type;
        this->value = value;
    }
};

class Lexer {
public:
    Lexer(std::string data) {
        this->data = data;
        this->index = 0;
        this->token = (Token*)malloc(sizeof(Token));
        this->next();
    }

    Token *token;

    void next_token();

private:
    std::string data;
    unsigned long index;
    char* buffer;

    void next();
};

#endif //TMPL_LEXER_H
