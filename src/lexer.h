#ifndef TMPL_LEXER_H
#define TMPL_LEXER_H

#include<list>
#include<string>

namespace TMPL_PARSER {

enum TokenType {
    TokenIdentifier,
    TokenNumber,
    TokenSeparator,
    TokenEmpty
};

class Token {
public:
    Token(TokenType token_type, char **data);
private:
    TokenType token_type;
    char **data;
};

class Lexer {
public:
    Lexer(char **data);

    void next_token();
private:
    uint64_t index;
    char **data;
    Token *token;
    char *buffer;

    void next();
};

}

#endif //TMPL_LEXER_H
