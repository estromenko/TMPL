#include "parser.h"

#include "../lexer/lexer.h"


TMPL_PARSER::Parser::Parser(TMPL_LEXER::Lexer *lexer) {
    this->lexer = lexer;
}