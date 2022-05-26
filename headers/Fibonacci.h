#include "LargeNumber.h"

class Fibonacci : public LargeNumber {
   public:
    Fibonacci();
    ~Fibonacci();

    mpz_class FibAlgorithm(unsigned long long n);

    void FibBuiltIn(unsigned long long n);
};