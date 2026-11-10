/*
The knapsack problem is a classic optimization problem in computer science and belongs to 
the NP-complete problem class. It models a real-world scenario: given a set of items, each 
with a weight and a value, determine how to choose items under the capacity constraint of the 
knapsack to maximize the total value.
Dynamic programming (DP) is an effective method for solving this type of problem by breaking 
it into subproblems and storing the solutions to those subproblems to avoid repeated computation.

To implement the knapsack problem, we first need to understand several core concepts:

State definition: dp[w] represents the maximum value achievable with capacity w.
State transition equation: the mathematical expression that describes how the states transfer to each other.
Boundary conditions: the initial state, usually set as dp[w] = 0.
*/

#include <stdio.h>

#define MAXN 100
#define MAXW 10001

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int weight[MAXN];
    int value[MAXN];

    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    // dp[w] represents the maximum value achievable with capacity w
    int dp[MAXW] = {0};

    for (int i = 0; i < n; i++) {
        // Important: iterate through capacities in descending order to prevent using the same item more than once
        for (int w = capacity; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    printf("\nMaximum knapsack value: %d\n", dp[capacity]);

    // Optional: backtrack to find which items were selected
    printf("\nSelected items: ");
    int remain = capacity;
    for (int i = n - 1; i >= 0; i--) {
        if (remain >= weight[i] && dp[remain] == dp[remain - weight[i]] + value[i]) {
            printf("%d ", i + 1);
            remain -= weight[i];
        }
    }
    printf("\n");

    return 0;
}
