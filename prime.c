#include <stdbool.h>

bool is_prime_naive(int n) {
    if (n == 1) {
        return false;
    }
    for (int d = n - 1; d >= 2; d--) {
        if (n % d == 0) {
            return false;
        }
    }
    
    return true;
}

bool is_prime_sieve(int n) {
    if (n == 1) {
        return false;
    }
    
    int len = n - 2 + 1;
    bool is_prime[len];
    for (int i = 0; i < len; i++) {
        is_prime[i] = true;
    }
    int pos = 0;
    while (pos < len) {
        if (is_prime[pos]) {
            int d = pos + 2;
            for (int multiplier = 2; multiplier * d - 2 < len; multiplier++) {
                is_prime[multiplier * d - 2] = false;
            }
        }
        pos++;
    }
    
    return is_prime[len - 1];
}

