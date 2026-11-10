/*
The knapsack problem is a classic optimization problem in computer science and belongs to the NP-complete problem class. 
It models a real-world scenario: given a set of items, each with a weight and a value,
determine how to choose items under the capacity constraint of the knapsack to maximize the total value.
Dynamic programming (DP) is an effective method for solving this type of problem by breaking it into subproblems 
and storing the solutions to those subproblems to avoid repeated computation.

To implement the knapsack problem in C, we first need to understand several core concepts:

State definition: dp[i][v] represents the maximum value that can be obtained by putting the first i items into a knapsack with capacity v.
State transition equation: the mathematical expression that describes how the states transfer to each other.
Boundary conditions: the initial state, usually set as dp[0][v] = 0.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
#define MAX_V 100

int max(int a, int b) {
    return a > b ? a : b;
}

int main( ) 
{
    int n, V;  // Number of items, knapsack capacity
    int w[MAX_N], c[MAX_N];  // Weight array, value array
    int dp[MAX_N][MAX_V] = {0};
    
    // Input data
    scanf("%d %d", &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &c[i]);
    }
    
    // Dynamic programming solution
    for(int i = 1; i <= n; i++) {
        for(int v = 0; v <= V; v++) {
            if(v < w[i]) { // If the current capacity is less than the weight of the item, we cannot include it
                dp[i][v] = dp[i-1][v];
            } else {
                // If we can include the item, we take the maximum of including it or not
                dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i]] + c[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int v = 0; v <= V; v++) {
            printf("%d ", dp[i][v]);
        }
        printf("\n");
    }
    
    printf("Maximum value: %d\n", dp[n][V]);
    
    return 0;
}
