#include "token.h"

TMPL_PARSER::Token::Token(TMPL_PARSER::TokenType token_type, char *value) {
    this->token_type = token_type;
    this->value = value;
}