#ifndef TOKEN_H
#define TOKEN_H

namespace TMPL_PARSER {

enum TokenType {
    TokenIdentifier,
    TokenNumber,
    TokenSeparator,
    TokenEmpty,
    TokenDef,
    TokenIf
};

class Token {
public:
    Token(TokenType token_type, char *value);

    TokenType token_type;
    char *value;
};

}
#endif