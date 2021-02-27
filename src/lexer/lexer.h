#ifndef TMPL_LEXER_H
#define TMPL_LEXER_H

#include <list>
#include <string>
#include "token.h"

namespace TMPL_LEXER {

class Lexer {
public:
    Lexer(char *data);
    Lexer();

    Token *token;

    void next_token();
private:
    uint64_t index;
    char *data;
    char *buffer;
    void next();
};

}

#endif //TMPL_LEXER_H
