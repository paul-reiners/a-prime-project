#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"
#include "conway.h"

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    char* method = argv[2];
    bool is_prime;
    if (strcmp(method, "naive") == 0) {
        is_prime = is_prime_naive(n);
    } else if (strcmp(method, "sieve") == 0) {
        is_prime = is_prime_sieve(n);
    } else if (strcmp(method, "conway") == 0) {
        is_prime = is_prime_conway_simple(n);
    } else {
        printf("%s is not a valid computational method.\n", method);
        
        return 1;
    }
    
    printf("%d is %s\n", n, is_prime ? "prime" : "composite");
}

