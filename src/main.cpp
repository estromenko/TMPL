#include <iostream>
#include <fstream>

#include "lexer.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "no input files" << std::endl;
        return 1;
    }

    std::ifstream fin;
    fin.open(argv[1], std::ios::in);
    fin.seekg (0, std::ios::end);
    int64_t fin_size = fin.tellg() / sizeof(char);

    if (!fin.is_open()) {
        std::cerr << "file can't be open";
        return 2;
    }

    if (fin_size == 0) {
        std::cerr << "file is empety" << std::endl;
        return 3;
    }

    // TODO костыль, заменить на данные из входного файла
    std::string sdata("zxc zxc 123 asd");
    char *cdata = (char*)sdata.c_str();

    TMPL_PARSER::Lexer* lexer = new TMPL_PARSER::Lexer(cdata);
    lexer->next_token();
    while (lexer->token->token_type != TMPL_PARSER::TokenEmpty) {
        std::cout << lexer->token->value << "\t" << lexer->token->token_type << std::endl;
        lexer->next_token();
    }

    fin.close();
    return 0;
}