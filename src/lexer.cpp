#include "lexer.h"

#include <iostream>

namespace TMPL_PARSER {

void Lexer::next() {
    std::cout << "next\n";
}

void Lexer::next_token() {
    std::cout << "next_token\n";
}

}
