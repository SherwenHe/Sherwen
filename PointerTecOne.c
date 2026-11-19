#include <stdio.h>

int main()
{
  printf("Introduction to defining ordinary variables and pointer variables:\n\n");
  // Define ordinary variables
  float a = 99.5, b = 10.6;
  char c = '@', d = '#';
  char str[20] = "c.biancheng.net";
  printf("Address of variable a: %p, address of array str: %p\n", (void*)&a, str);

  printf("Press any key to continue...\n");
  getchar();
  
  printf("/----Referencing values with variables and pointer variables:---/\n\n");
  // Define pointer variables
  float* p = &a;
  float* pp = p;
  printf("Address pointed to by p: %p, address pointed to by pp: %p\n", (void*)p, (void*)pp);
  printf("a=%f, *p=%f\n", a, *p);  // Both methods can output the value of a

  printf("\nPress any key to continue...\n");
  getchar();
  
  printf("\nValues of the corresponding variables after modification through pointers:\n");
  char* q = &d;  
  *p = b;  // Modify data in memory through a pointer variable
  c = *q;  // Get data from memory through a pointer variable    
  printf("\nModified values at the locations pointed to: a=%f, b=%f, c=%c, *p=%f\n", a, b, c, *p);
  // Modify the values of the pointer variables
  p = &b;
  q = &d;
  printf("\nValues at the locations pointed to after reassignment: *p=%f, *q=%c\n", *p, *q);

  printf("\nPress any key to continue...\n");
  getchar();

  printf("\nPointer variables can appear in any expression where ordinary variables can appear.\n\n");
  int x = 5, y = 6, * px = &x, * py = &y;
  // Add 5 to the value of x and assign it to y; *px+5 is equivalent to (*px)+5
  y = *px + 5;  
  printf("A value pointed to by a pointer participates in the operation: y=%d\n", y);
  
  // Increment the value pointed to by px by 1 and assign it to y; ++*px is equivalent to ++(*px)
  y = ++ * px;  //Equivalent to ++(*px)
  printf("A value pointed to by a pointer participates in the operation: y=%d\n", y);
  
  y = *px++;  // Equivalent to y=*(px++),the priority of ++ is higher than the dereference operator *
  printf("A value pointed to by a pointer participates in the operation: y=%d\n", y);

  py = px;  // Assign one pointer's value to another pointer
  printf("Values pointed to by pointers participate in the operation: y=%d, *q=%d\n", y, *py);
    
  printf("Press any key to continue...\n");
  getchar();

  printf("\nUsing pointer variables to exchange values:\n\n");
  float temp, * pa = &a, * pb = &b;
  a=10.5; b=20.5;
  printf("Before swapping: a=%f, b=%f\n", a, b);
  /***** Start swapping *****/
  temp = *pa;  // Save the value of a first
  *pa = *pb;  // Assign the value of b to a
  *pb = temp;  // Assign the saved value of a to b
  /***** Finish swapping *****/
  printf("After swapping: a=%f, b=%f\n", a, b);

  return 0;
}
