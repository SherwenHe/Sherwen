/*
The knapsack problem is commonly divided into the 0/1 knapsack problem and the fractional knapsack problem. 
In typical exercises, "solving the knapsack problem with a greedy algorithm" refers to the fractional knapsack 
problem, where items can be divided and packed proportionally. In this case, the greedy algorithm is guaranteed 
to find an optimal solution. For the 0/1 knapsack problem, the greedy algorithm may only find an approximate 
solution and is not guaranteed to be optimal. This code solves the fractional knapsack problem, where items can 
be divided.
Given a capacity C and n items, each with weight w[i] and value v[i], choose items to put in the knapsack so 
that the total weight is at most C and the total value is maximized.
For the 0/1 knapsack problem, where items cannot be divided, a greedy algorithm is not guaranteed to find 
an optimal solution.
*/

#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);

    int weight[MAXN];
    int value[MAXN];
    double ratio[MAXN];

    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);

        if (weight[i] > 0) {
            ratio[i] = (double)value[i] / weight[i];
        } else {
            ratio[i] = 0;
        }
    }

    // Sort in descending order of value per unit of weight (bubble sort; swap all three arrays together)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                double tmpR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tmpR;
                // Swap weight
                int tmpW = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tmpW;
                // Swap value
                int tmpV = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmpV;
            }
        }
    }

    double totalValue = 0.0;
    double remaining = capacity;

    printf("\nGreedy selection process:\n");

    for (int i = 0; i < n; i++) {
        if (remaining <= 0) {
            break;
        }

        if (weight[i] <= remaining) {
            totalValue += value[i];
            remaining -= weight[i];
            printf("Item %d added in full, weight %d, value %d\n",
                   i + 1, weight[i], value[i]);
        } else {
            double fraction = remaining / weight[i];
            totalValue += fraction * value[i];
            printf("Item %d added partially (weight %.2f), value gained %.2f\n",
                   i + 1, remaining, fraction * value[i]);
            remaining = 0;
        }
    }

    printf("\nMaximum knapsack value: %.2f\n", totalValue);

    return 0;
}
