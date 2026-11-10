/*
Input a string of length n (no more than 100,000), followed by an integer k (1–100).
Enter one command per line. The commands are:
! Invert the string and print it (0 becomes 1, and 1 becomes 0).
@ Reverse the string and print it (for example, 001 becomes 100).
# Count and print the number of 1s in the string.
*/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[100000+5];
    int str[100000+5];
    int q[100000+5];
    scanf("%s",s);
    for(int i=0;i<n;i++){
        str[i]=s[i]-'0';
    }
    int k;
    scanf("%d",&k);
    char a;
    while(k--){
        scanf(" %c",&a);
        if(a=='!'){
            for(int i=0;i<n;i++){
                if(str[i]==0){
                    str[i]=1;
                }
                else if(str[i]==1){
                    str[i]=0;
                }
                    printf("%d",str[i]);
            }
        }
        else if(a=='@'){
            for(int i=n-1;i>=0;i--){
                q[n-i-1]=str[i];
                printf("%d",str[i]);
            }
            for(int i=0;i<n;i++){
                str[i]=q[i];
            }
        }
        else if(a=='#'){
                int cnt=0;
                for(int i=0;i<n;i++){
                    if(str[i]==1){
                        cnt++;
                    }
                }
                printf("%d",cnt);
        }
        printf("\n");
    }
    return 0;
}
