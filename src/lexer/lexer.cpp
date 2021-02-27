#include "lexer.h"

#include <iostream>
#include <ctype.h>
#include "token.h"
#include <cstring>


#define MAX_TOKEN_LENGTH 20


const char *special_identifiers[] = {
    "some random string that does not have any sence in this case but it is necessary to increase index by 1",
    
    "def",
    "if",
    "else",

    "=",
    "==",
    "+",
    "++",
    "+=",
    "-",
    "--",
    "-=",
    ";",
    "(",
    ")",
    "[",
    "]",
    "{",
    "}",
    ":",
    ",",
    ".",
};


// Lexer classes
void TMPL_LEXER::Lexer::next() {
    this->buffer = &this->data[this->index++];
}

// This function create token
void TMPL_LEXER::Lexer::next_token() {
    while (isspace(*this->buffer)) {
        this->next();
    }

    char *c_token = new char[MAX_TOKEN_LENGTH];
    size_t index = 0;
    c_token[index++] = *this->buffer;
    this->next();

    if (isalpha(c_token[0]) || c_token[0] == '_') {
        while (isalnum(*this->buffer) || *this->buffer == '_') {
            c_token[index++] = *this->buffer;
            this->next();
        } 
    
        for (size_t i = 0; i < TokenEmpty - TokenIdentifier; i++) {
            if (strcmp(special_identifiers[i], c_token) == 0) {
                this->token = new Token(static_cast<TokenType>(i), c_token);
                return;
            }
        }

        this->token = new Token(TokenIdentifier, c_token);
    } else if (isdigit(c_token[0])) {
        while (isdigit(*this->buffer)) {
            c_token[index++] = *this->buffer;
            this->next();
        }

        this->token = new Token(TokenNumber, c_token);
    } else {
        switch (c_token[0]) {
            case '=': {
                if (*this->buffer == '=') {
                    c_token[index++] = *this->buffer;
                    this->token = new Token(TokenEqualEqual, c_token);
                    return;
                }

                this->token = new Token(TokenEqual, c_token);
                return;
            }
            case '+': {
                if (*this->buffer == '+') {
                    c_token[index++] = *this->buffer;
                    this->token = new Token(TokenPlusPlus, c_token);
                    return;
                } else if (*this->buffer == '=') {
                    c_token[index++] = *this->buffer;
                    this->token = new Token(TokenPlusEqual, c_token);
                    return;
                }
                this->token = new Token(TokenPlus, c_token);
                return;
            }   
            case '-': {
                if (*this->buffer == '-') {
                    c_token[index++] = *this->buffer;
                    this->token = new Token(TokenMinusMinus, c_token);
                    return;
                } else if (*this->buffer == '=') {
                    c_token[index++] = *this->buffer;
                    this->token = new Token(TokenMinusEqual, c_token);
                    return;
                }
                this->token = new Token(TokenMinus, c_token);
                return;
            }
            default: {
                for (size_t i = 0; i < TokenEmpty - TokenIdentifier; i++) {
                    if (strcmp(special_identifiers[i], c_token) == 0) {
                        this->token = new Token(static_cast<TokenType>(i), c_token);
                        return;
                    }
                }
            }
        }

        this->token = new Token(TokenEmpty, nullptr);
        std::cerr << "[DEBUG] Syntax error: unknown identifier (" << c_token << ")" << std::endl; // Instead of logger command
    }

}

TMPL_LEXER::Lexer::Lexer(char *data) {
    this->data = data;
    this->index = 0;
    this->token = new Token(TokenEmpty, nullptr);
    this->next();
}