#include "lexer.h"

#include <iostream>
#include <ctype.h>
#include "token.h"
#include <cstring>


#define MAX_TOKEN_LENGTH 20


const char *special_identifiers[] = {
    "",
    
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
    "/",
    "/=",
    "//",
    "*",
    "*=",
    "**",
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
    "%",
    "<", 
    "<=",
    ">",
    ">=",
    "!",
    "!=",
    "&",
    "&&",
    "|",
    "||",
    "'",
    "\"",
};


void TMPL_LEXER::Lexer::next() {
    this->buffer = &this->data[this->index++];
}


void TMPL_LEXER::Lexer::next_token() {
    if (*this->buffer == '\0') {
        this->token = new Token(TokenEmpty, nullptr);
        return;
    }
    while (isspace(*this->buffer)) {
        this->next();
    }

    char *c_token = new char[MAX_TOKEN_LENGTH];
    size_t c_index = 0;
    c_token[c_index++] = *this->buffer;
    this->next();

    if (isalpha(c_token[0]) || c_token[0] == '_') {
        while (isalnum(*this->buffer) || *this->buffer == '_') {
            c_token[c_index++] = *this->buffer;
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
            c_token[c_index++] = *this->buffer;
            this->next();
        }

        if (isalpha(*this->buffer)) {
            while (isalpha(*this->buffer)) {
                c_token[c_index++] = *this->buffer;
                this->next();
            }
            
            std::cerr << "\033[31m" << "Syntax error: unknown identifier (" << c_token << ")" << std::endl;
            exit(1);
        }

        this->token = new Token(TokenNumber, c_token);
    } else {
        switch (c_token[0]) {
            case '=': {
                if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenEqualEqual, c_token);
                    this->next();
                    return;
                }

                this->token = new Token(TokenEqual, c_token);
                this->next();
                return;
            }
            case '+': {
                if (*this->buffer == '+') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenPlusPlus, c_token);
                    this->next();
                    return;
                } else if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenPlusEqual, c_token);
                    this->next();
                    return;
                }
                this->token = new Token(TokenPlus, c_token);
                this->next();
                return;
            }   
            case '-': {
                if (*this->buffer == '-') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenMinusMinus, c_token);
                    this->next();
                    return;
                } else if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenMinusEqual, c_token);
                    this->next();
                    return;
                }
                this->token = new Token(TokenMinus, c_token);
                this->next();
                return;
            }
            case '/': {
                if (*this->buffer == '/') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenDivisionDivision, c_token);
                    this->next();
                    return;
                } else if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenDivisionEqual, c_token);
                    this->next();
                    return;
                }
                this->token = new Token(TokenDivision, c_token);
                this->next();
                return;
            }
            case '*': {
                if (*this->buffer == '*') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenMultiplicationMultiplication, c_token);
                    this->next();
                    return;
                } else if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenMultiplicationEqual, c_token);
                    this->next();
                    return;
                }
                this->token = new Token(TokenMultiplication, c_token);
                this->next();
                return;
            }
            case '<': {
                if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenLessEqual, c_token);
                    this->next();
                    return;
                } 

                this->token = new Token(TokenLess, c_token);
                this->next();
                return;
            }
            case '>': {
                if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenGreaterEqual, c_token);
                    this->next();
                    return;
                } 

                this->token = new Token(TokenGreater, c_token);
                this->next();
                return;
            }
            case '!': {
                if (*this->buffer == '=') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenNotEqual, c_token);
                    this->next();
                    return;
                } 

                this->token = new Token(TokenNot, c_token);
                this->next();
                return;
            }
            case '&': {
                if (*this->buffer == '&') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenAndAnd, c_token);
                    this->next();
                    return;
                } 

                this->token = new Token(TokenAnd, c_token);
                this->next();
                return;
            }
            case '|': {
                if (*this->buffer == '|') {
                    c_token[c_index++] = *this->buffer;
                    this->token = new Token(TokenOrOr, c_token);
                    this->next();
                    return;
                } 

                this->token = new Token(TokenOr, c_token);
                this->next();
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
        std::cerr << "\033[31mSyntax error: unknown identifier (" << c_token << ")" << std::endl; // Instead of logger command
        exit(1);
    }
}


TMPL_LEXER::Lexer::Lexer(char *data) {
    this->data = data;
    this->index = 0;
    this->token = new Token(TokenEmpty, nullptr);
    this->next();
}
