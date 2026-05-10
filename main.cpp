#include "Lexer.h"
#include "Parser.h"
#include "Executor.h"
#include <limits>
#include <iostream>
using namespace std;
//OOPL
//Cybersecurity automation DSL

int main(int argc, char* argv[]) {
char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter your command: ";
        string input;

        if (argc > 1) {
            input = argv[1];
        } else {
            getline(cin, input);
        }

        try {
            Lexer lexer(input);
            auto tokens = lexer.tokenize();

            Parser parser(tokens);
            auto ast = parser.parse();

            string result = Executor::execute(ast.get());

            cout<<"Executing: ";
            for (const auto &t : tokens) {
                cout << "[" << t.value << "] ";
            }

            cout << "\nGenerated Command:\n" << result << endl;

        }
        catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }

            cout << "\nDo you want to run another command? (Y/N): ";
            cin >> choice;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
    }
    cout << "Exiting program.\n";

    return 0;
}


/*
run on cmd terminal with:g++ -std=c++17 main.cpp Lexer.cpp Parser.cpp Executor.cpp -o Final
Final.exe
*/

