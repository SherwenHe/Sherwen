/*Quick sort is a divide-and-conquer algorithm. It chooses a pivot value and divides
the array into elements smaller than the pivot and elements greater than the pivot.
It recursively sorts both parts until the entire array is sorted.*/

#include <stdio.h>

/**
 * @param arr Array
 * @param n Number of elements in the array
 */

void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @param arr Array to be sorted
 * @param left Left boundary index of the array
 * @param right Right boundary index of the array
 */

void quick_sort(int arr[], int left, int right)
{
    int i = left;
    int j = right;

    int p = arr[(left + right) / 2];
    int temp;

    if (left >= right)
    {
        return;  // Sorting is complete
    }

    while (i <= j)
    {
        /* Place values smaller than the middle pivot on the left and values greater than the pivot on the right */
        while (arr[i] < p)
        {
            i++;
        }

        while (arr[j] > p)
        {
            j--;
        }

        if (i <= j)
        {
            /* Swap the values so that smaller values are on the left and larger values are on the right */
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } 

    //Hoare partition mehtod
    quick_sort(arr, left, j);
    quick_sort(arr, j + 1, right);

    /* // or
    quick_sort(arr, left, i-1);
    quick_sort(arr, i, right);
    */
    print_array(&arr[left], right - left + 1); /* Print the array for debugging */
}

int main()
{
    int arr[] = {40, 30, 20, 10, 50, 60, 70, 80, 90, 100, 110, 89};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Old arr : ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("New arr : ");
    print_array(arr, n);
    return 0;
}
