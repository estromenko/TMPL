#ifndef NODE_H
#define NODE_H

#include "../lexer/lexer.h"


namespace TMPL_PARSER{

enum NodeType {
    NodeRoot,

    NodeIdentifire,

    NodeDef,
    NodeLBracket,
    NodeRBracket 
};


class Node {
public:
    Node(NodeType node_type, TMPL_LEXER::Token *token, Node *next);

    TMPL_LEXER::Token *token;
    NodeType node_type;
    Node *next;

    void set_next_node(Node *next);
};

}

#endif