#ifndef TMPL_PARSER_H
#define TMPL_PARSER_H

#include "../lexer/lexer.h"
#include "node.h"


namespace TMPL_PARSER {

class Parser {
public:
    Parser(TMPL_LEXER::Lexer *lexer);

    Node* get_tree();
private:
    TMPL_LEXER::Lexer *lexer;
};

}

#endif // TMPL_PARSER_H