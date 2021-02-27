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

    if (!fin.is_open()) {
        std::cerr << "file can't be open";
        return 2;
    }

    fin.seekg (0, std::ios::end);
    int fin_size = fin.tellg() / sizeof(char);
    fin.seekg (0);
    if (fin_size == 0) {
        std::cerr << "file is empety" << std::endl;
        return 3;
    }

    std::string s_data;
    std::string word;

    while (!fin.eof())
    {
        fin >> word;
        s_data += " " + word;
    }

    std::cout << s_data << std::endl;
    s_data += "\0";

    char *c_data = (char*)s_data.c_str();

    TMPL_PARSER::Lexer* lexer = new TMPL_PARSER::Lexer(c_data);
    lexer->next_token();
    while (lexer->token->token_type != TMPL_PARSER::TokenEmpty) {
        std::cout << lexer->token->value << "\t" << lexer->token->token_type << std::endl;
        lexer->next_token();
    }

    fin.close();

    return 0;
}