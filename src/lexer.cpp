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

    char *c_token = new char[MAX_TOKEN_LENGTH];
    size_t index = 0;
    c_token[index++] = *this->buffer;
    this->next();
    if (isalpha(c_token[0]) || c_token[0] == '_') {
        while (isalpha(*this->buffer) || *this->buffer == '_') {
            c_token[index++] = *this->buffer;
            this->next();
        } 
        if (c_token == "def") {
            this->token = new Token(TokenDef, c_token);
        } else if (c_token == "if") {
            this->token = new Token(TokenIf, c_token);
        } else {
            this->token = new Token(TokenIdentifier, c_token);
        } 

    } else if (isdigit(c_token[0])) {
        while (isdigit(*this->buffer)) {
            c_token[index++] = *this->buffer;
            this->next();
        }

        this->token = new Token(TokenNumber, c_token);
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