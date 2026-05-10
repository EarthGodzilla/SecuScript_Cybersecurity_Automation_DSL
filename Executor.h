#pragma once
#include "AST.h"
#include <string>
using namespace std;

class Executor {
public:
    static string execute(ASTNode *node);
};