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
#include "cuddInt.h"

using std::cout; using std::cerr; using std::endl;

int main(int argc, char** argv)
{
    // Initialize a new BDD manager.
    DdManager *manager = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS,
            CUDD_CACHE_SLOTS, 0);

    if (manager == nullptr) {
        std::cerr << "Error when initializeing CUDD." << std::endl;
        return 1;
    }

    // Variables.
    DdNode *x1 = Cudd_bddIthVar(manager,0);
    DdNode *x2 = Cudd_bddIthVar(manager,1);
    DdNode *x3 = Cudd_bddIthVar(manager,2);
    DdNode *x4 = Cudd_bddIthVar(manager,3);
    DdNode *x5 = Cudd_bddIthVar(manager,4);
    DdNode *x6 = Cudd_bddIthVar(manager,5);

    // ORs.
    DdNode *and1 = Cudd_bddAnd(manager, x1, x2);
    Cudd_Ref(and1);
    DdNode *and2 = Cudd_bddAnd(manager, x3, x4);
    Cudd_Ref(and2);
    DdNode *and3 = Cudd_bddAnd(manager, x5, x6);
    Cudd_Ref(and3);

    // AND.
    DdNode *or1 = Cudd_bddOr(manager, and1, and2);
    Cudd_Ref(or1);
    DdNode *out = Cudd_bddOr(manager, or1, and3);
    Cudd_Ref(out);

    // Create a dot file.
    char *inputNames[6];
    strcpy(inputNames[0] = new char[3], "x1");
    strcpy(inputNames[1] = new char[3], "x2");
    strcpy(inputNames[2] = new char[3], "x3");
    strcpy(inputNames[3] = new char[3], "x4");
    strcpy(inputNames[4] = new char[3], "x5");
    strcpy(inputNames[5] = new char[3], "x6");

    char * outputNames[1];
    strcpy(outputNames[0] = new char[4], "out");

    DdNode *output_increasing[1];
    output_increasing[0] = out;
    Cudd_Ref(output_increasing[0]);

    FILE *f1 = fopen("increasing.dot", "w");

    Cudd_DumpDot(manager, 1, output_increasing, inputNames, outputNames, f1);
    fclose(f1);

    std::cout << "\n=== ORDERED ===" << std::endl
        << "x1 pos: " << Cudd_ReadPerm(manager,x1->index) << "\n"
        << "x2 pos: " << Cudd_ReadPerm(manager,x2->index) << "\n"
        << "x3 pos: " << Cudd_ReadPerm(manager,x3->index) << "\n"
        << "x4 pos: " << Cudd_ReadPerm(manager,x4->index) << "\n"
        << "x5 pos: " << Cudd_ReadPerm(manager,x5->index) << "\n"
        << "x6 pos: " << Cudd_ReadPerm(manager,x6->index) << endl;
    std::cout << "nodes in BDD: " << Cudd_ReadNodeCount(manager) << std::endl;

    int permutation[] = {0,2,4,1,3,5};
    Cudd_ShuffleHeap(manager,permutation);

    DdNode *output_permutated[1];
    output_permutated[0] = out;
    Cudd_Ref(output_permutated[0]);

    FILE *f2 = fopen("permutated.dot", "w");

    Cudd_DumpDot(manager, 1, output_permutated, inputNames, outputNames, f2);
    fclose(f2);

    std::cout << "\n=== PERMUTATED ===" << std::endl
        << "x1 pos: " << Cudd_ReadPerm(manager,x1->index) << "\n"
        << "x2 pos: " << Cudd_ReadPerm(manager,x2->index) << "\n"
        << "x3 pos: " << Cudd_ReadPerm(manager,x3->index) << "\n"
        << "x4 pos: " << Cudd_ReadPerm(manager,x4->index) << "\n"
        << "x5 pos: " << Cudd_ReadPerm(manager,x5->index) << "\n"
        << "x6 pos: " << Cudd_ReadPerm(manager,x6->index) << endl;
    std::cout << "nodes in BDD: " << Cudd_ReadNodeCount(manager) << std::endl;
    
    return 0;
}
