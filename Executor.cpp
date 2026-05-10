#include "Executor.h"
#include <sstream>
using namespace std;

string Executor::execute(ASTNode *node) {
    return node->execute();
}