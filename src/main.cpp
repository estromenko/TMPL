#include <iostream>

#include "lexer.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "no input files" << std::endl;
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        std::cerr << "file empety";
        return 1;
    } 

    char** data = (char**)malloc(sizeof(char));
    size_t length = 0;
    char ch;
    while ((ch = getc(fp)) != EOF) {
        data[length++] = &ch;
    }

    TMPL_PARSER::Lexer* lexer = new TMPL_PARSER::Lexer(data);

    lexer->next_token();

    free(data);

    fclose(fp);

    return 0;
}
