#include <stdbool.h>
#include <stdio.h>

#include "hackers_delight.h"

#define VERBOSE 0

int get_exponent(unsigned n);

struct instruction {
    int num;
    int denom;
    char name;
};

bool is_prime_conway_simple(int nn) {
    struct instruction a = { 17, 91, 'A' };
    struct instruction b = { 78, 85, 'B' };
    struct instruction d = { 19, 51, 'D' };
    struct instruction h = { 23, 38, 'H' };
    struct instruction e = { 29, 33, 'E' };
    struct instruction f = { 77, 29, 'F' };
    struct instruction i = { 95, 23, 'I' };
    struct instruction r = { 77, 19, 'R' };
    struct instruction p = {  1, 17, 'P' };
    struct instruction s = { 11, 13, 'S' };
    struct instruction t = { 13, 11, 'T' };
    struct instruction l = { 15, 14, 'L' };
    struct instruction m = { 15,  2, 'M' };
    struct instruction n = { 55,  1, 'N' };
    struct instruction instructions[] = { a, b, d, h, e, f, i, r, p, s, t, l, m, n };
    unsigned long long val = 2;
    if (VERBOSE) {
        printf("%llu\n", val);
    }
    while (true) {
        do {
            for (int j = 0; j < sizeof(instructions)/sizeof(instructions[0]); j++) {
                struct instruction next_instruction = instructions[j];
                if (next_instruction.num * val % next_instruction.denom == 0) {
                    val = next_instruction.num * val / next_instruction.denom;
                    if (VERBOSE) {
                        printf("%c %llu\n", next_instruction.name, val);
                    }
                    
                    break;
                }
            } 
        } while (pop(val) != 1);
        int exponent = get_exponent(val);
        if (exponent == nn) {
            return true;
        } else if (exponent > nn) {
            return false;
        }
    }
    
    printf("%c\n", a.name);

    return false;
}

int get_exponent(unsigned n) {
    int exponent = 0;
    while (n != 1) {
        n >>= 1;
        exponent++;
    }
    
    return exponent;
}

