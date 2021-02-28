#include "node.h"

#include "../lexer/token.h"


TMPL_PARSER::Node *TMPL_PARSER::Node::get_tree() {
    return nullptr;
}

TMPL_PARSER::Node::Node(TMPL_LEXER::Token *token) {
    this->token = token;
}

