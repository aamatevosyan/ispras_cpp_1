#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "mctester.h"
#include "qesolver.h"

constexpr double EPS = 1e-5;

/**
 * Checks if computed solutions of quadratic equation are correct
 * @param tag Tag
 * @param a The quadratic coefficient (coefficient a)
 * @param b The linear coefficient    (coefficient b)
 * @param c The constant              (coefficient c)
 * @param n Number of roots
 * @param x1 1st root
 * @param x2 2nd root
 */
void testEquation(string tag, double a, double b, double c, int n, double x1, double x2) {
    double _x1, _x2;
    int _n = getRoots(a, b, c, _x1, _x2);

    assertEquals(tag + ": Number of roots", n, _n);

    if (n == 2 && x1 < x2)
        std::swap(x1, x2);

    if (_n)
        assertEquals(tag + ": X1", x1, _x1, EPS);

    if (_n > 1)
        assertEquals(tag + ": X2", x2, _x2, EPS);
}

/**
 * Checks if string is "double"
 * @param str  string
 * @return True, if string is "double" and false otherwise
 */
bool ValidateDouble(const std::string &str) {
    const regex dbl(R"(^([+-]?(?:[[:d:]]+\.?|[[:d:]]*\.[[:d:]]+))(?:[Ee][+-]?[[:d:]]+)?$)");
    return regex_match(str, dbl);
}

/**
 * Reads double from console
 * @param prompt Promt to display
 * @return User-entered double
 */
double readDoubleFromConsole(const string &prompt) {
    string input;
    bool match = false;

    do {
        cout << prompt;
        getline(cin, input);
        match = ValidateDouble(input);
    } while (!match);

    return stod(input);
}

/**
 * Reads double from sringstrean
 * @param ss stringstream
 * @param res double
 * @return True, if double was read correctly and false, otherwise
 */
bool readDoubleFromStream(stringstream& ss, double& res) {
    string input;
    ss >> input;

    if (!ValidateDouble(input))
        return false;

    res = stod(input);
    return true;
}

/**
 * Gets data from line
 * @param line line
 * @param a The quadratic coefficient (coefficient a)
 * @param b The linear coefficient    (coefficient b)
 * @param c The constant              (coefficient c)
 * @param n Number of roots
 * @param x1 1st root
 * @param x2 2nd root
 * @return True, if data was read correctly and false, otherwise
 */
bool getDataFromLine(const string &line, double &a, double &b, double &c, int &n, double &x1, double &x2) {
    stringstream ss(line);
    if (readDoubleFromStream(ss, a) && readDoubleFromStream(ss, b) && readDoubleFromStream(ss, c)) {
        string tmp;
        ss >> tmp;

        if (tmp == "QES_INF_ROOTS")
            n = QES_INF_ROOTS;
        else if (tmp == "0")
            n = 0;
        else if (tmp == "1")
            n = 1;
        else if (tmp == "2")
            n = 2;
        else
            return false;

        if (readDoubleFromStream(ss, x1) && readDoubleFromStream(ss, x2))
            return true;
    }

    return false;
}

/**
 * Tests solver using provided test file
 * @param path Path to test file
 * @return True, if all tests were passed and false, otherwise
 */
bool testSolver(const string &path) {
    ifstream fin(path);
    string line;
    double a, b, c, x1, x2;
    int n, i = 0;

    while(getline(fin, line)) {
        if (!getDataFromLine(line, a, b, c, n, x1, x2))
            return false;

        testEquation("Test #" + to_string(++i), a, b, c, n, x1, x2);
    }
    return true;
}

int main() {
    cout << "Please wait, testing the solver..." << endl;

    if (!testSolver("..\\data.txt")) {
        cout << "Oops, there is an error. Please check your solution or provided test data." << endl;
    }
    cout << "Congratulations, all test were passed." << endl;

    double a, b, c, x1, x2;

    a = readDoubleFromConsole("Enter the quadratic coefficient (coefficient a):\n");
    b = readDoubleFromConsole("Enter the linear coefficient    (coefficient b):\n");
    c = readDoubleFromConsole("Enter the constant              (coefficient c):\n");

    int n = getRoots(a, b, c, x1, x2);
    switch (n) {
        case QES_INF_ROOTS:
            cout << "Equation has infinity roots." << endl;
            break;
        case 0:
            cout << "There is no roots :(((" << endl;
            break;
        case 1:
            cout << "There is only one root: [" << x1 << "]" << endl;
            break;
        case 2:
            cout << "There are two roots: [" << x1 << ", " << x2 << "]" << endl;
            break;
    }
    return 0;
}
