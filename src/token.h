#ifndef TOKEN_H
#define TOKEN_H

namespace TMPL_PARSER {

enum TokenType {
    TokenIdentifier,
    TokenNumber,
    TokenSeparator,
    TokenEmpty,
    TokenDef
};

class Token {
public:
    Token(TokenType token_type, char *value);

    TokenType token_type;
    char *value;
};

}
#endif