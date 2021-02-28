#include "parser.h"

#include "../lexer/lexer.h"


TMPL_PARSER::Parser::Parser(TMPL_LEXER::Lexer *lexer) {
    this->lexer = lexer;
}

TMPL_PARSER::Node *TMPL_PARSER::Parser::get_tree() {
    Node *node = new Node(NodeRoot, nullptr, nullptr);
    return node;
}