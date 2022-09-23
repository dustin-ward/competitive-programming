#include "logicfunctions.h"

// Compute xor
void exclusive(bool x, bool y, bool& ans){
    ans = x ^ y;
}

// Compute implication
void implies(bool x, bool y, bool& ans){
    ans = ((x && !y) ? 0 : 1);
}

// Compute equivalence
void equivalence(bool x, bool y, bool& ans){
    ans = ((x ^ y) ? 0 : 1);
}