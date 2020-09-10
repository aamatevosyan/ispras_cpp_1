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

bool isZero(double a) {
    return fabs(a) < QES_EPS;
}

