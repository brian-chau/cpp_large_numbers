#include "LargeNumber.h"

#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

LargeNumber::LargeNumber() {
}

LargeNumber::~LargeNumber() {
}

char* LargeNumber::LongToBin(unsigned long long n) {
    static char c[8196];
    memset(c, 0, 8196);

    while (n) {
        if (n & 1) {
            strcat(c, "1");
        } else {
            strcat(c, "0");
        }
        n >>= 1;
    }

    std::reverse(c, c + strlen(c));
    return c;
}
