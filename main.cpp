#include <iostream>
#include "mctester.h"
#include "qesolver.h"

constexpr double EPS = 1e-5;

void testEquation(double a, double b, double c, int n, double x1, double x2) {
    double _x1, _x2;
    int _n = getRoots(a, b, c, _x1, _x2);

    assertEquals("Number of roots", n, _n);

    if (n == 2 && x1 < x2)
        std::swap(x1, x2);

    if (_n)
        assertEquals("X1", x1, _x1, EPS);

    if (_n > 1)
        assertEquals("X2", x2, _x2, EPS);
}

int main() {

    // INF_ROOTS
    testEquation(0, 0, 0, QES_INF_ROOTS, 0, 0);
    testEquation(0, 0, 1, 0, 0, 0);

    // Linear
    testEquation(0, 1, 1, 1, -1, 0);
    testEquation(0, 2, 8, 1, -4, 0);

    // D < 0
    testEquation(1, 1, 1, 0, 0, 0);
    testEquation(2, 3, 4, 0, 0, 0);

    // D == 0
    testEquation(1, 2, 1, 1, -1, 0);
    testEquation(4, 12, 9, 1, -1.5, 0);

    // D > 0
    testEquation(5, 6, 1, 2, -0.2, -1);
    testEquation(1, -6, -16, 2, 8, -2);

    // Failures
    testEquation(5, 6, 1, 2, -0.3, -1);
    testEquation(1, -6, -16, 2, 8, -1);

    return 0;
}
