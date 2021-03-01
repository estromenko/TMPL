#include "parser.h"

#include "../lexer/lexer.h"
#include <iostream>


TMPL_PARSER::Parser::Parser(TMPL_LEXER::Lexer *lexer) {
    this->lexer = lexer;
}

TMPL_PARSER::Node *TMPL_PARSER::Parser::get_tree() {
    if (lexer->token->token_type == TMPL_LEXER::TokenDef) {
        Node *def_head = new Node(NodeRoot, lexer->token, nullptr);
        lexer->next_token();
        if (lexer->token->token_type != TMPL_LEXER::TokenIdentifier) {
            std::cerr << "invalid syntax >>" << lexer->token->token_type 
                      << "<< function\nhasn't name" << std::endl;
            return nullptr;
        }
        Node *def_name = new Node(NodeIdentifire, lexer->token, nullptr);
        def_head->set_next_node(def_name);

        lexer->next_token();
        if (lexer->token->token_type == TMPL_LEXER::TokenLBracket) {
            Node *def_args_start = new Node(NodeLBracket, lexer->token, nullptr);
            def_name->set_next_node(def_args_start);

            lexer->next_token();

            if (lexer->token->token_type != TMPL_LEXER::TokenRBracket) {
                Node *first_arg = new Node(NodeIdentifire, lexer->token, nullptr);
                def_args_start->set_next_node(first_arg);

                while (lexer->token->token_type != TMPL_LEXER::TokenRBracket) {
                    lexer->next_token();
                    if (lexer->token->token_type == TMPL_LEXER::TokenComma) {
                        lexer->next_token();
                        first_arg->set_next_node(new Node(NodeIdentifire, lexer->token, nullptr));
                    }
                }
            }
            
        }

        while (true) {
            
        }
    }
    
    
}