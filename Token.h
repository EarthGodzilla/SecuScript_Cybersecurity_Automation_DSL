#pragma once
#include <string>
using namespace std;

enum class TokenType {
    WORD,
    NUMBER,
    IP,
    SLASH,
    DOT,
    END
};

struct Token {
    TokenType type;
    string value;
};