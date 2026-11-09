/*
The knapsack problem is a classic optimization problem in computer science and belongs to the NP-complete problem class. It models a real-world scenario: given a set of items, each with a weight and a value,
determine how to choose items under the capacity constraint of the knapsack to maximize the total value.
Dynamic programming (DP) is an effective method for solving this type of problem by breaking it into subproblems and storing the solutions to those subproblems to avoid repeated computation.

To implement the knapsack problem in C, we first need to understand several core concepts:

State definition: dp[i][v] represents the maximum value that can be obtained by putting the first i items into a knapsack with capacity v.
State transition equation: the mathematical expression that describes how the states transfer to each other.
Boundary conditions: the initial state, usually set as dp[0][v] = 0.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_V 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int main() 
{
    int n, V;  // Number of items and knapsack capacity
    int w[MAX_N + 1], c[MAX_N + 1];  // Weight and value arrays
    int dp[MAX_V + 1] = {0};  // One-dimensional DP array, initialized to 0
    
    // Input data
    scanf("%d %d", &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &c[i]);
    }
    
    // Dynamic programming solution
    for(int i = 1; i <= n; i++) {
        // Important: iterate through capacities in descending order
        for(int v = V; v >= w[i]; v--) {
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    
    printf("Maximum value: %d\n", dp[V]);
    
    return 0;
}
