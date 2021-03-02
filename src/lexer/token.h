#ifndef TOKEN_H
#define TOKEN_H

namespace TMPL_LEXER {

enum TokenType {
    TokenIdentifier, // Must be the first

    TokenDef,
    TokenIf,
    TokenElse,

    TokenEqual,
    TokenEqualEqual,
    TokenPlus,
    TokenPlusPlus,
    TokenPlusEqual,
    TokenMinus,
    TokenMinusMinus,
    TokenMinusEqual,
    TokenDivision,
    TokenDivisionEqual,
    TokenDivisionDivision,
    TokenMultiplication,
    TokenMultiplicationEqual,
    TokenMultiplicationMultiplication,
    TokenSemicolumn,
    TokenLBracket,
    TokenRBracket,
    TokenLSquareBracket,
    TokenRSquareBracket,
    TokenLCurlyBracket,
    TokenRCurlyBracket,
    TokenColumn,
    TokenComma,
    TokenPoint,
    TokenMod,
    TokenLess,
    TokenLessEqual,
    TokenGreater,
    TokenGreaterEqual,
    TokenNot,
    TokenNotEqual,
    TokenAnd,
    TokenAndAnd,
    TokenOr,
    TokenOrOr,
    TokenQuote,
    TokenDoubleQuote,

    TokenNumber,    

    TokenEmpty, // Must be the last
};

class Token {
public:
    Token(TokenType token_type, char *value);

    TokenType token_type;
    char *value;
};

}

#endif