#pragma once
#include "Token.h"
#include <vector>
#include <string>
using namespace std;

class Lexer {
public:
    explicit Lexer(const string &input);
    vector<Token> tokenize();

private:
    string input;
    size_t pos;

    const char peek() const;
    char get();
    void skipWhitespace();
};