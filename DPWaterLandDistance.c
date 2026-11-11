/*
Problem description
Given an N x M binary matrix, where 1 represents land and 0 represents water, find the distance 
from each cell to the nearest water cell.
The distance between a cell and any of its four neighbors (up, down, left, or right) is 1.
Input
Multiple test cases.
The first line contains two integers, N and M.
The next N lines each contain M zeros or ones representing the map.
The input is guaranteed to contain at least one water cell.
For 30% of the test cases, 1 <= N, M <= 100.
For all test cases, 1 <= N, M <= 800.
Output
Print N lines, each containing M space-separated integers. Each integer is the distance from that 
cell to the nearest water cell.
Sample input
4 4
0110
1111
1111
0110
Sample output
0 1 1 0
1 2 2 1
1 2 2 1
0 1 1 0
*/
//#define _CRT_SECURE_NO_WARNINGS 1 // 1. 必须放在最前面，允许使用 scanf
#include <stdio.h>
//#include <stdlib.h>
#define maxn 80+2
#define maxm 80+2

int map[maxn][maxm]; // The mapping of the land and water cells
int dp[maxn][maxm]; // The distance matrix to store the minimum distances to water cells

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    //while(scanf("%d %d",&n,&m)!=EOF)
    //{
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                dp[i][j]=n*m-2; // Initialize dp array with a large value (maximum possible distance)
            }
        }
        // Read the map data
        for(i=1;i<=n;i++)
		{
            for(j=1;j<=m;j++)
			{
                scanf("%1d",&map[i][j]);
                if(map[i][j]==0)
                {
                    dp[i][j]=0; // If the cell is water, set its distance to 0
                }
            }
        }
        // Perform a forward pass
        for(i=1;i<=n;i++)
		{
            for(j=1;j<=m;j++)
			{
                int val=min(dp[i-1][j],dp[i][j-1])+1;// Calculate the minimum distance from the top and left neighbors
                dp[i][j]=min(val,dp[i][j]);// Update the distance for the current cell
            }
        }
        // Perform a backward pass
        for(i=n;i>=1;i--)
		{
            for(j=m;j>=1;j--)
			{
                int val=min(dp[i+1][j],dp[i][j+1])+1; // Calculate the minimum distance from the bottom and right neighbors
                dp[i][j]=min(val,dp[i][j]);// Update the distance for the current cell
            }
        }
        // Print the resulting distance matrix
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(j>1) printf(" ");
                printf("%d",dp[i][j]);
            }
            printf("\n");
        }
    //}
    return 0;
}

