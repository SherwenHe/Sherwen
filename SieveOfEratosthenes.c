/*
 * Sieve of Eratosthenes implementation in C
 * This program finds all prime numbers up to a given limit n using the Sieve of Eratosthenes algorithm.
 * It is written in C17 standard.
 */
/*
 * The Eratosthenes sieve is an algorithm that efficiently calculates all prime numbers within a range 
 * by "marking composite numbers". The core idea is to start from 2, cross out all multiples of each prime 
 * number, and the remaining ones are prime numbers.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void sieveOfEratosthenes(int n) {
    if (n < 2) {
        printf("There are no primes.\n");
        return;
    }

    bool isPrime[n + 1];

    // 1. Initialization: Assume all numbers are prime
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    // 2. 0 and 1 are not primes
    isPrime[0] = false;
    isPrime[1] = false;

    // 3. Sieve from 2 to sqrt(n)
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (isPrime[i]) {
            // 4. Mark multiples of i as non-prime, starting from i * i
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 5. Output all primes
    printf("Within the range: %d\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Please enter the upper limit n: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);
    return 0;
}
