//
// Created by newap on 9/10/2020.
//

#ifndef ISPRAS_CPP_1_MCTESTER_H
#define ISPRAS_CPP_1_MCTESTER_H

#include <cassert>
#include "cmath"
#include "string"
#include "ansi.h"

using namespace std;

constexpr double MCT_EPS = 1e-12;

/**
 * Asserts equality of expected and actual value
 * @param name Assertion's name
 * @param expected Expected value
 * @param actual Actual value
 */
void assertEquals(std::string name, int expected, int actual) {
    if (expected == actual) {
        cout << ansi::foreground_green << "[" << name << "]" << " - " << "[PASSED]" << ansi::reset << endl;
    } else {
        cout << ansi::foreground_red << "[" << name << "]" << " - " << "[Failed]" << endl;
        cout << "Expected: " << expected << endl;
        cout << "Actual: " << actual << ansi::reset << endl;
    }
}

/**
 * Asserts equality of expected and actual value
 * @param name Assertion's name
 * @param expected Expected value
 * @param actual Actual value
 * @param eps Epsilon used for checking equality
 */
void assertEquals(string name, double expected, double actual, double eps) {

    if (fabs(expected - actual) < eps) {
        cout << ansi::foreground_green << "[" << name << "]" << " - " << "[PASSED]" << ansi::reset << endl;
    } else {
        cout << ansi::foreground_red << "[" << name << "]" << " - " << "[Failed]" << endl;
        cout << "Expected: " << expected << endl;
        cout << "Actual: " << actual << ansi::reset << endl;
    }
}

/**
 * Asserts equality of expected and actual value
 * @param name Assertion's name
 * @param expected Expected value
 * @param actual Actual value
 */
void assertEquals(string name, double expected, double actual) {
    return assertEquals(name, expected, actual, MCT_EPS);
}

#endif //ISPRAS_CPP_1_MCTESTER_H
