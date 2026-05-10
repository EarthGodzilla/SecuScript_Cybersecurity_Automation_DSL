#include "Parser.h"
#include <stdexcept>
using namespace std;

Parser::Parser(const vector<Token> &tokens) : tokens(tokens), pos(0) {}

Token Parser::peek() const {
    if (pos >= tokens.size()){
        return {TokenType::END, ""};
    }
    return tokens[pos];
}

Token Parser::get() {
    if (pos >= tokens.size()){
        return {TokenType::END, ""};
    }
    return tokens[pos++];
}

bool Parser::match(const string &word) {
    if (peek().value == word) {
        get();
        return true;
    }
    return false;
}

void Parser::expect(const string &word) {
    if (!match(word)) {
        throw runtime_error("Expected: " + word);
    }
}

unique_ptr<ASTNode> Parser::parse() {
    if (match("scan")) {
        return parseScan();
    }
    if (match("block")) {
        return parseBlock();
    }
    if (match("monitor")) {
        return parseMonitor();
    }

    throw runtime_error("Unknown command");
}

// Scan
unique_ptr<ASTNode> Parser::parseScan() {
    auto cmd = make_unique<ScanCommand>();

    expect("subnet");
    cmd->subnet = get().value;

    expect("for");
    expect("open");
    expect("ports");

    if (match("and")) {
        expect("export");
        expect("as");
        cmd->format = get().value;
    }

    return cmd;
}

// Block
unique_ptr<ASTNode> Parser::parseBlock() {
    auto cmd = make_unique<BlockCommand>();

    expect("ip");
    cmd->ip = get().value;

    expect("using");
    cmd->firewall = get().value;

    return cmd;
}

// Monitor
unique_ptr<ASTNode> Parser::parseMonitor() {
    auto cmd = make_unique<MonitorCommand>();

    cmd->file = get().value;

    expect("for");

    // take words as event
    string event;
    while (peek().type != TokenType::END) {
        event += get().value + " ";
    }

    cmd->event = event;

    return cmd;
}