#include "Lexer.h"
#include <cctype>
using namespace std;

Lexer::Lexer(const string &input) : input(input), pos(0) {}

char Lexer::peek() const {
    return pos < input.size() ? input[pos] : '\0';
}

char Lexer::get() {
    return pos < input.size() ? input[pos++] : '\0';
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) get();
}

vector<Token> Lexer::tokenize() {
    vector<Token> tokens;

    while (pos < input.size()) {
        skipWhitespace();

        /* (isdigit(peek())) {
            string num;
            while (isdigit(peek())) num += get();
            tokens.push_back({TokenType::NUMBER, num});
        }*/
        if (isdigit(peek())) {
            string value;

            // Capture full,  10.0.0.0/24
            while (std::isdigit(peek()) || peek() == '.' || peek() == '/') {
                value += tolower(get());//breaks without std::
            }

            tokens.push_back({TokenType::WORD, value});
        }
        else if (isalpha(peek()) || peek() == '/') {
            string word;
            while (isalnum(peek()) || peek() == '/' || peek() == '.' || peek() == '_' || peek() == '-'){
                word += tolower(get());
            }
            tokens.push_back({TokenType::WORD, word});
        }
        else {
            get(); // skip unknown
        }
    }

    tokens.push_back({TokenType::END, ""});
    return tokens;
}