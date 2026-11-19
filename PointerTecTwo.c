#include <stdio.h> 

// Attempt to exchange data by passing values
void swap(int a, int b)
{
    int temp;  // Temporary variable
    temp = a;
    a = b;
    b = temp;
}
 
// Exchange data through pointers
void pswap1(int* b1, int* c1) 
{
 
    // Declare a temporary pointer and swap the pointer values
    int *a;
	a = c1;
    c1 = b1;
    b1 = a;
}

// Declare pswap; dereference the parameters to access the values passed by the arguments
void pswap(int* b1, int* c1) 
{
 
    // Save the value pointed to by c1 in temporary variable a
    int a = *c1; 
    // Assign the value pointed to by b1 to the location pointed to by c1
    *c1 = *b1; 
    // Assign the temporary value to the location pointed to by b1
    *b1 = a;
}

// Find the maximum value in an array
int max(int *intArr, int len)
{
    int i, maxValue = intArr[0];  // Assume the element at index 0 is the maximum
    for(i=1; i<len; i++)
	{
        if(maxValue < intArr[i])
		{
            maxValue = intArr[i];
        }
    }   
    return maxValue;
}


int main() 
{ 
    // Declare two variables
    int a,b; 
   // Assign values to the two variables
    a = 1;
    b = 2;
    printf("\nOrdinary variables are passed to a function to exchange their values:\n\n");    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("After swapping: a = %d, b = %d\n", a, b);    
    
    printf("Press any key to continue...\n");
    getchar();

    printf("\nPointer variables are passed to a function to exchange their values:\n\n");     
    int *p=&a, *q=&b; 
    printf("Before swapping: a=%d, b=%d\n", a, b);
    pswap1(p, q);
    // Output to the console
    printf("After calling pswap1: a=%d, b=%d\n", a, b); 
    // Call pswap and pass the corresponding pointer arguments
    pswap(p, q); 
    // Output to the console
    printf("After calling pswap: a=%d, b=%d\n", a, b);
        
    printf("Press any key to continue...\n");
    getchar();

    printf("\nReview passing an array as a function argument to find the maximum value:\n\n");
    int nums[2], i;
    int len = sizeof(nums)/sizeof(int);
    nums[0]=1;
    nums[1]=2;
    printf("Max value is %d!\n", max(nums, len));
    return 0;
}
