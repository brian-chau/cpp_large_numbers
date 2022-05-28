#include "Fibonacci.h"

#include <iostream>

Fibonacci::Fibonacci() {
    // Intentionally left blank
}

Fibonacci::~Fibonacci() {
    // Intentionally left blank
}

mpz_class Fibonacci::FibAlgorithm(unsigned long long n) {
    mpz_class left(1), right(1), helper1(0), helper2(0);

    if (0 == n) {
        left = 0;
        return left;
    } else if (1 == n) {
        return left;
    } else if (2 == n) {
        return left;
    }

    char* binary = LongToBin(n);
    unsigned long long digits = strlen(binary);
    for (unsigned long long i = 1; i < digits; i++) {
        helper1 = left * ((2 * right) - left);
        helper2 = right * right + left * left;
        if (binary[i] == '0') {
            left = helper1, right = helper2;
        } else {
            left = helper2, right = helper1 + helper2;
        }
    }

    return left;
}

void Fibonacci::FibBuiltIn(unsigned long long n) {
    mpz_t result;
    mpz_init(result);
    mpz_fib_ui(result, n);
    mpz_out_str(stdout, 10, result);
    mpz_clear(result);

    std::cout << "\n";
    return;
}