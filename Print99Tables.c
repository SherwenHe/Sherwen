#include <stdio.h>

int main() // Suggest using symbol standard regular of int main()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++) // 
        {
            // The newline was removed; tabs or spaces keep the output on the same line.
            printf("%d*%d=%-2d\t", i, j, i * j);
        }
        printf("\n"); // Print a newline after each row.
    }   
    
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            // Remove the newline and separate each item with a tab.
            printf("%d*%d=%-2d\t", i, j, i * j);
        }
        // Print a newline after each row (when the inner loop ends).
        printf("\n");
    }
    getchar(); // Wait for input so the window does not close immediately when the program ends.
    
    return 0;  // Return successfully.
}
