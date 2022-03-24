/***************************************************************************
 *            cudd_or.cpp
 *
 *  Copyright  2022  Luigi Capogrosso
 *
 ***************************************************************************/



#include <iostream>
#include <fstream>
#include <cstring>

#include "cudd.h"


int main(int argc, char** argv)
{
    // Initialize a new BDD manager.  
    DdManager *manager = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS,
            CUDD_CACHE_SLOTS, 0);

    if (manager == nullptr)
    {
        std::cerr << "Error when initializing CUDD." << std::endl;
        return 1;
    }

    // Create a new BDD variable x1 and x2.
    DdNode *x1 = Cudd_bddIthVar(manager, 0);
    DdNode *x2 = Cudd_bddIthVar(manager, 1);

    // Create the two AND with the negations.
    DdNode *and1 = Cudd_bddAnd(manager, x1, Cudd_Not(x2));
    Cudd_Ref(and1);
    DdNode *and2 = Cudd_bddAnd(manager, Cudd_Not(x1), x2);
    Cudd_Ref(and2);

    // sum is the OR of the two ANDs.
    DdNode *sum = Cudd_bddOr(manager, and1, and2);
    Cudd_Ref(sum);

    // carry.
    DdNode *carry = Cudd_bddAnd(manager, x1, x2);
    Cudd_Ref(carry);

    // Create a restriction.
    DdNode *restrictBy = Cudd_bddAnd(manager, x1, Cudd_Not(x2));
    Cudd_Ref(restrictBy);

    // Test the restriction.
    DdNode *testSum = Cudd_bddRestrict(manager, sum, restrictBy);
    Cudd_Ref(testSum);
    DdNode *testCarry = Cudd_bddRestrict(manager, carry, restrictBy);
    Cudd_Ref(testCarry);

    std::cout << "x1 = 1, x2 = 0:" <<
                 "\n  sum = " << ( 1 - Cudd_IsComplement(testSum) )   << 
                 "\ncarry = " << ( 1 - Cudd_IsComplement(testCarry) ) << 
                 std::endl;

    // Create a dot file.
    char *inputNames[2];
    strcpy(inputNames[0] = new char[3], "x1");
    strcpy(inputNames[1] = new char[3], "x2");
    char * outputNames[2];
    strcpy(outputNames[0] = new char[4], "sum");
    strcpy(outputNames[1] = new char[6], "carry");

    DdNode *outputs[2];
    outputs[0] = sum;
    Cudd_Ref(outputs[0]);
    outputs[1] = carry;
    Cudd_Ref(outputs[1]);

    FILE *f = fopen("half_adder.dot", "w");

    Cudd_DumpDot(manager, 2, outputs, inputNames, outputNames, f);

    Cudd_RecursiveDeref(manager, outputs[0]);
    Cudd_RecursiveDeref(manager, outputs[1]);
    fclose(f);

    // Deallocate restriction.
    Cudd_RecursiveDeref(manager, restrictBy);
    Cudd_RecursiveDeref(manager, testSum);
    Cudd_RecursiveDeref(manager, testCarry);

    // Deallocate.
    Cudd_RecursiveDeref(manager, and1);
    Cudd_RecursiveDeref(manager, and2);

    return 0;
}
