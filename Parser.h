#pragma once
#include "Token.h"
#include "AST.h"
#include <vector>
#include <memory>
using namespace std;

class Parser {
public:
    explicit Parser(const vector<Token> &tokens);
    unique_ptr<ASTNode> parse();

private:
    vector<Token> tokens;
    size_t pos;

    Token peek() const;
    Token get();
    bool match(const string &word);
    void expect(const string &word);


    unique_ptr<ASTNode> parseScan();
    unique_ptr<ASTNode> parseBlock();
    unique_ptr<ASTNode> parseMonitor();
};