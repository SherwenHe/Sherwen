//按照金字塔输出从A到Z的26个字母，用+填充空白 
#include<stdio.h>
#include<math.h>
main()
{
	int i,j,k,n=9;
	char c='A'-1;	
	for(i=1;i<=2*n-1;i++)
	{
		k=n-abs(n-i);
	
		for(j=1;j<=abs(n-i)+1;j++)
        {
            printf("+");
        } 

		for(j=1;j<=2*k-1;j++)
		{
            c++;
            printf("%c",c);
            if(c=='Z')  
                c=c-26;
		}

        for(j=1;j<=abs(n-i)+1;j++)
		{
			printf("+");
		}

	    printf("\n");
	}
	return 0;
}

