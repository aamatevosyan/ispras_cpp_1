//
// Created by newap on 9/10/2020.
//

#ifndef ISPRAS_CPP_1_ANSI_H
#define ISPRAS_CPP_1_ANSI_H

#include <ostream>

/**
 * Helper functions for colored text output
 */
namespace ansi {
    template<class CharT, class Traits>
    constexpr
    std::basic_ostream<CharT, Traits> &reset(std::basic_ostream<CharT, Traits> &os) {
        return os << "\033[0m";
    }

    template<class CharT, class Traits>
    constexpr
    std::basic_ostream<CharT, Traits> &foreground_black(std::basic_ostream<CharT, Traits> &os) {
        return os << "\033[30m";
    }

    template<class CharT, class Traits>
    constexpr
    std::basic_ostream<CharT, Traits> &foreground_red(std::basic_ostream<CharT, Traits> &os) {
        return os << "\033[31m";
    }

    template<class CharT, class Traits>
    constexpr
    std::basic_ostream<CharT, Traits> &foreground_green(std::basic_ostream<CharT, Traits> &os) {
        return os << "\033[32m";
    }
}

#endif //ISPRAS_CPP_1_ANSI_H
