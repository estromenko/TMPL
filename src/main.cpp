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

    char **data = (char**)malloc(sizeof(char));
    char token[255];

    fin >> token;

    std::cout << token;

    TMPL_PARSER::Lexer* lexer = new TMPL_PARSER::Lexer(data);

    lexer -> next_token();

    fin.close();

    return 0;
}