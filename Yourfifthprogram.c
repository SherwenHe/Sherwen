#include<stdio.h>
int main() 
{
    // This program finds the largest of three numbers entered by the user
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    // Compare the numbers and find the largest
    if (a >= b && a >= c)
    {
        printf("%d is the largest number.\n", a);
    }
    else if (b >= a && b >= c)
    {
        printf("%d is the largest number.\n", b);
    }
    else
    {
        printf("%d is the largest number.\n", c);
    }

    // Alternatively, using the ternary operator
    int max=(a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("%d is the largest number.\n", max);

    // Ask the user if they want to continue
    char choice;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);

    // Use a switch statement to handle the user's choice
    switch(choice) 
    {
        case 'y':
        case 'Y':
            main(); // Call main() again to continue
            break;
        case 'n':
        case 'N':
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Exiting the program.\n");
            break;
    }

    return 0;
}
