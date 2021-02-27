#include "token.h"

TMPL_LEXER::Token::Token(TMPL_LEXER::TokenType token_type, char *value) {
    this->token_type = token_type;
    this->value = value;
}