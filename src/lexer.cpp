#include "lexer.h"

#include <iostream>
#include <ctype.h>
#include "token.h"

#define MAX_TOKEN_LENGTH 20


// Lexer classes
void TMPL_PARSER::Lexer::next() {
    this->buffer = &this->data[this->index++];
}

// This function create token
void TMPL_PARSER::Lexer::next_token() {
    while (isspace(*this->buffer)) {
        this->next();
    }

    char *token = new char[MAX_TOKEN_LENGTH];
    size_t index = 0;
    token[index++] = *this->buffer;
    this->next();
    if (isalpha(token[0]) || token[0] == '_') {
        while (isalpha(*this->buffer) || *this->buffer == '_') {
            token[index++] = *this->buffer;
            this->next();
        } 
        if (token == "def") {
            this->token = new Token(TokenDef, token);
        } else {
            this->token = new Token(TokenIdentifier, token);
        }

    } else if (isdigit(token[0])) {
        while (isdigit(*this->buffer)) {
            token[index++] = *this->buffer;
            this->next();
        }

        this->token = new Token(TokenNumber, token);
    } else {
        this->token = new Token(TokenEmpty, nullptr);
    }

}

TMPL_PARSER::Lexer::Lexer(char *data) {
    this->data = data;
    this->index = 0;
    this->token = new Token(TokenEmpty, nullptr);
    this->next();
}