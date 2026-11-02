#include <stdio.h>
#include <stdbool.h>

#define N 1000005

bool is_composite[N];   // true denotes composite numbers, false denotes prime numbers, default is false
int primes[N];          // Store the sieved primes
int cnt = 0;            // Count of primes

void Euler_Sieve(int n) {
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes[cnt++] = i;          // i is a prime
        }

        for (int j = 0; j < cnt && (long long)i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;   // Mark as composite

            if (i % primes[j] == 0) {             // Key: Ensure the smallest prime factor is removed
                break;
            }
        }
    }
}

int main(void) {
    int n = 100;
    Euler_Sieve(n);

    printf("Within the range: %d\n", n);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    return 0;
}
