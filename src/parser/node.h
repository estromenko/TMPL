#ifndef NODE_H
#define NODE_H

#include "../lexer/lexer.h"

namespace TMPL_PARSER{

enum NodeType {

};


class Node {
public:
    Node(TMPL_LEXER::Token *token);

    TMPL_LEXER::Token *token;
    Node *next;

    Node* get_tree();
};

}

#endif