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
    Token(TokenType token_type, char *value);

    TokenType token_type;
    char *value;
};

class Lexer {
public:
    Lexer(char *data);
    Lexer();

    Token *token;

    void next_token();
private:
    uint64_t index;
    char *data;
    char *buffer;
    void next();
};

}

#endif //TMPL_LEXER_H
