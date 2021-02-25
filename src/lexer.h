#ifndef TMPL_LEXER_H
#define TMPL_LEXER_H

class Lexer {
public:
    Lexer() {}
    void next_token();
private:
    void next();
};

#endif //TMPL_LEXER_H
