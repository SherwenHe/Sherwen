#include <stdio.h>

int main() {
    int sum = 0;

    // The following code calculates the sum of numbers from 1 to 100 using a do-while loop.
    sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 100);
    printf("do-while results: %d\n", sum);
    
    // The following code calculates the sum of numbers from 1 to 100 using a while loop.
    sum = 0;
    i = 1;
    while (i <= 100) {
        sum += i;
        i++;
    }
    printf("while results: %d\n", sum);

    // The following code calculates the sum of numbers from 1 to 100 using different loop constructs in C.
    for (i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("for results: %d\n", sum);
    

    
    return 0;
}
