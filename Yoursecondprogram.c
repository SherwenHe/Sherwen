#include <stdio.h>
#define PI 3.14159265358979323846

int main()
{
    // Printing Hello World
    printf("Hello World\n");

    // Declaring and initializing an integer variable
    int n=2;
    printf("%d\n",n);

   
    int a,b;
    printf("Enter two integer numbers, such as 2,3: \n");
    scanf("%d,%d",&a,&b);
    printf("%d\n",a*b);

    // Performing arithmetic operations
    int p,s,q;
    p=a*b;
    s=a+b;
    q=s/p;
    printf("The product is: %d\n",p);
    printf("The sum is: %d\n",s);
    printf("The quotient is: %d\n",q); 
    
    /* Performing arithmetic operations with float numbers*/
    float x,y;  // Declaring two float variables
    printf("Enter two float numbers: \n");
    scanf("%f %f",&x,&y);
    printf("The product is: %f\n",x*y);
    printf("The sum is: %f\n",x+y);
    printf("The quotient is: %f\n",x/y);


    // Calculating area and circumference of a circle
    int r;
    printf("Enter the radius of the circle: \n");
    scanf("%d",&r);
    printf("The area of the circle is: %f\n",PI*r*r);
    printf("The circumference of the circle is: %f\n",2*PI*r);

    return 0;
}
