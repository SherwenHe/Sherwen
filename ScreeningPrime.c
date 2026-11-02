/*
To pre store the first 10000 prime numbers, it is not enough to directly use the 
"Sieve of Eratosthenes" (埃拉托斯特尼筛法) to filter a fixed range (such as 1-10000), 
because there are only 1229 prime numbers within 10000.
According to mathematical estimates, the 10000th prime number is approximately 104729. 
Therefore, we need to set the filtering upper limit to around 110000 to ensure coverage 
of the 10000th prime number.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 110000      // The maximum number to check for primes, set slightly above the 10000th prime
#define PRIME_COUNT 10000 // The number of primes to store

// Global array, used to store the precomputed primes
int stored_primes[PRIME_COUNT];

/**
 * Generate the first PRIME_COUNT primes using the Sieve of Eratosthenes and store them
 */
void generate_primes() {
    bool is_prime[MAX_N + 1];
    
    // 1. Initialization: Assume all numbers are prime
    for (int i = 0; i <= MAX_N; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    // 2. Core sieve logic: Mark composites
    // Only need to iterate up to sqrt(MAX_N)
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            // Mark all multiples of i as non-prime, starting from i * i, 
            // because i * 2, i * 3... have already been marked by smaller prime numbers
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 3. Extract primes and store them
    int count = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            if (count < PRIME_COUNT) {
                stored_primes[count] = i;
                count++;
            } else {
                break; // Already stored 10000 primes, exit early
            }
        }
    }
    
    printf("Successfully precomputed %d primes.\n", count);
    printf("The 1st prime is: %d\n", stored_primes[0]);
    printf("The 10000th prime is: %d\n", stored_primes[PRIME_COUNT - 1]);
}

int main() {
    // Example: Generate and store the first 10000 primes
    generate_primes();

    // Example: User inputs n, directly output the nth prime
    int n;
    printf("Please enter n (1-10000): ");
    if (scanf("%d", &n) == 1 && n >= 1 && n <= PRIME_COUNT) {
        printf("The %dth prime is: %d\n", n, stored_primes[n - 1]);
    } else {
        printf("Invalid input. Please enter an integer between 1 and 10000.\n");
    }

    return 0;
}
