//
// Created by newap on 9/10/2020.
//

#ifndef ISPRAS_CPP_1_QESOLVER_H
#define ISPRAS_CPP_1_QESOLVER_H

/**
 * Defined epsilon for checking equality of numbers
 */
constexpr double QES_EPS = 1e-12;

/**
 * Expression for storing Infinity roots case
 */
constexpr int QES_INF_ROOTS = -1;

/**
 * Solves the quadratic equation \f$ a x^2 + b x + c = 0 \f$
 * @param a The quadratic coefficient (coefficient a)
 * @param b The linear coefficient    (coefficient b)
 * @param c The constant              (coefficient c)
 * @param x1 Reference to the 1st root
 * @param x2 Reference to the 2nd root
 * @return Number of roots
 * @note In case of infinite number of roots, returns QES_INF_ROOTS.
 */
int getRoots(double a, double b, double c, double &x1, double &x2);

/**
 * Check if number is zero
 * @param a number
 * @return True, if number is zero and false, otherwise
 * @note Uses QES_EPS as precision while comparing to zero.
 */
bool isZero(double a);

#endif //ISPRAS_CPP_1_QESOLVER_H
