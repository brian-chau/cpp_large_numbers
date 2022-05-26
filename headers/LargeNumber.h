#include <gmp.h>
#include <gmpxx.h>

class LargeNumber {
   public:
    LargeNumber();
    ~LargeNumber();

    char* LongToBin(unsigned long long n);

   private:
};