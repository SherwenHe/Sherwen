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

typedef struct {
    int weight;     // Item weight
    int value;      // Item value
    double ratio;   // Value per unit of weight
} Item;

int main(void)
{
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);

    Item items[MAXN];

    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        if (items[i].weight > 0) {
            items[i].ratio = (double)items[i].value / items[i].weight;
        } else {
            items[i].ratio = 0;
        }
    }

    // Sort in descending order of value per unit of weight
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
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

        if (items[i].weight <= remaining) {
            // The entire item fits in the knapsack
            totalValue += items[i].value;
            remaining -= items[i].weight;
            printf("Item %d added in full, weight %d, value %d\n",
                   i + 1, items[i].weight, items[i].value);
        } else {
            // Only part of the item fits
            double fraction = remaining / items[i].weight;
            totalValue += fraction * items[i].value;
            printf("Item %d added partially (weight %.2f), value gained %.2f\n",
                   i + 1, remaining, fraction * items[i].value);
            remaining = 0;
        }
    }

    printf("\nMaximum knapsack value: %.2f\n", totalValue);

    return 0;
}
