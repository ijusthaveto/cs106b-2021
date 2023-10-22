#include "HumanPyramids.h"
#include "error.h"
#include "hashmap.h"
#include "gridlocation.h"

using namespace std;

bool inBounds(const GridLocation & location, int height) {
    return (location.row >= 0 && location.row < height) &&
           (location.col >= 0 && location.col <= location.row);
}

double weightOnBackRec(int row, int col, int pyramidHeight, HashMap<GridLocation, double> & table) {
    if (!inBounds({row, col}, pyramidHeight)) {
        error("Out out bounds!");
    }

    if (row == 0) {
        return 0;
    } else if (table.containsKey({row, col})) {
        return table.get({row, col});
    } else {
        if (col == 0) {
            table.put({row, col}, weightOnBackRec(row - 1, col, pyramidHeight, table) * 0.5 + 80);
        } else if (row == col) {
            table.put({row, col}, weightOnBackRec(row - 1, col - 1, pyramidHeight, table) * 0.5 + 80);
        } else {
            table.put({row, col}, weightOnBackRec(row - 1, col - 1, pyramidHeight, table) * 0.5 +
                                  weightOnBackRec(row - 1, col, pyramidHeight, table) * 0.5 + 160);
        }

        return table.get({row, col});
    }
}


double weightOnBackOf(int row, int col, int pyramidHeight) {
    HashMap<GridLocation, double> table;
    return weightOnBackRec(row, col, pyramidHeight, table);
}



/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

STUDENT_TEST("My own test.") {
    EXPECT_EQUAL(weightOnBackOf(3, 1, 4), 340);
}

/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

