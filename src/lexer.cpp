#include "lexer.h"

#include <regex>
#include <string>


void Lexer::next() {
    this->buffer = &this->data.at(this->index++);
}

void Lexer::next_token() {
    if (data.length() <= this->index + 1) {
        this->token = new Token(TokenEOF, "EOF");
    } else {
        while (*this->buffer == ' ' || *this->buffer == '\t' || *this->buffer == '\n') {
            this->next();
        }
        std::string identifier;
        identifier.push_back(*this->buffer);
        this->next();

        if (std::regex_match(identifier, std::regex("[a-zA-Z]+"))) {
            while (std::regex_match(this->buffer, std::regex("[a-zA-Z0-9]+"))) {
                identifier.append(std::string(this->buffer));
                this->next();
            }

            this->token = new Token(TokenIdentifier, identifier);
        } else {
            std::cerr << "Lexer error: unknown identifier(" << identifier << ")" << std::endl;
            exit(1);
        }
    }
}
