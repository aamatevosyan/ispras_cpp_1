//
// Created by newap on 9/10/2020.
//

#include "qesolver.h"
#include "cassert"
#include "cmath"

int getRoots(double a, double b, double c, double &x1, double &x2) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    if (!_isnan(b / a) && !_isnan(c / a)) {
        int n = solveQuadraticEquation(1, b / a, c / a, x1, x2);
        if (!_isnan(x1) && !_isnan(x2))
            return n;
    }

    return solveQuadraticEquation(a, b, c, x1, x2);
}

bool isZero(double a) {
    return fabs(a) < QES_EPS;
}

int solveQuadraticEquation(double a, double b, double c, double &x1, double &x2) {
    if (!isZero(a)) { // a != 0
        double d = b * b - 4 * a * c;

        if (d < 0) // d < 0
            return 0;

        if (isZero(d)) { // d == 0
            x1 = -b / (2 * a);
            return 1;
        }

        // d > 0
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        return 2;
    }

    if (!isZero(b)) { // b != 0
        x1 = -c / b;
        return 1;
    }

    return isZero(c) ? QES_INF_ROOTS : 0;
}

