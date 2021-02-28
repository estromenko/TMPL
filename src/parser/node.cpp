#include "node.h"

#include "../lexer/token.h"


TMPL_PARSER::Node::Node(NodeType node_type, TMPL_LEXER::Token *token, Node *next = nullptr) {
    this->node_type = node_type;
    this->token = token;
    this->next = next;
}

