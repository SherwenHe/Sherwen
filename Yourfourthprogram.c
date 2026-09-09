#include <stdio.h>
int main()
{
    // Printing Hello World
    printf("Hello World\n");

    // Declaring and initializing an integer variable
    int n=2;
    printf("%d\n",n);

   
    int a,b;
    printf("Enter two integer numbers: \n");
    scanf("%d %d",&a,&b);
    printf("%d\n",a*b);

    // Performing arithmetic operations
    int p,s,q;
    p=a*b;
    s=a+b;
    q=s/p;
    printf("The product is: %d\n",p);
    printf("The sum is: %d\n",s);
    printf("The quotient is: %d\n",q); 
    
    // Performing arithmetic operations with float numbers
    float x,y;  // Declaring two float variables
    printf("Enter two float numbers: \n");
    scanf("%f %f",&x,&y);
    printf("The product is: %f\n",x*y);
    printf("The sum is: %f\n",x+y);
    printf("The quotient is: %f\n",x/y);
    printf("The product is: %f\n",(int)(x*y));
    printf("The sum is: %f\n",(int)(x)+ (int)(y));
    printf("The quotient is: %f\n",x/y);

    // Performing logical operations
    int c;
    a=b=c=10;
    a=b==c;
    printf ("%d, %d, %d\n", a, b, c);  
    a== ( b=c++*2 );
    printf ("%d, %d, %d\n", a, b, c);
    a= b>c>=100;
    printf ("%d, %d, %d\n", a, b, c); 

    // Performing relational operations
    printf("The value of a is: %d\n",x>y? 1:0);

    return 0;
}
