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

/*!
 * @brief Print a DD summary.
 * @param parameter pr = 0 : Prints nothing
 *                  pr = 1 : Prints counts of nodes and minterms
 *                  pr = 2 : Prints counts + disjoint sum of product
 *                  pr = 3 : Prints counts + list of nodes
 *                  pr > 3 : Prints counts + disjoint sum of product
 *                                         + list of nodes
 */
void print_dd(DdManager *gbm, DdNode *dd, int n, int pr)
{
    // Reports the number of live nodes in BDDs and ADDs.
    printf("DdManager nodes: %ld | ", Cudd_ReadNodeCount(gbm));

    // Returns the number of BDD variables in existence.
    printf("DdManager vars: %d | ", Cudd_ReadSize(gbm));

    // Returns the number of times reordering has occurred.
    printf("DdManager reorderings: %d | ", Cudd_ReadReorderings(gbm));

    // Returns the memory in use by the manager measured in bytes.
    printf("DdManager memory: %ld \n", Cudd_ReadMemoryInUse(gbm));

    /* Prints the DD and the following statistics:
     * - Number of nodes
     * - Number of leaves
     * - Number of minterms
     */
    Cudd_PrintDebug(gbm, dd, n, pr);
}


int main(int argc, char *argv[])
{
    // Initialize a new BDD manager.
    DdManager *gbm;
    gbm = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);

    // Create a new BDD variable x1 and x2.
    DdNode *bdd, *x1, *x2;
    x1 = Cudd_bddNewVar(gbm);
    x2 = Cudd_bddNewVar(gbm);

    // Perform XNOR Boolean operation.
    bdd = Cudd_bddXnor(gbm, x1, x2);

    // Convert BDD to ADD for display purpose.
    bdd = Cudd_BddToAdd(gbm, bdd);

    // Print the DD.
    print_dd(gbm, bdd, 2, 4);

    Cudd_Quit(gbm);

    return 0;
}
