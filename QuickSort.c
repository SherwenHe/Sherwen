/*快速排序是一种分治算法 ，通过选择一个基准值（pivot）将数组分为两部分：
小于基准值的元素和大于基准值的元素。递归地对这两部分进行排序，最终完成整个数组的排序。*/

#include <stdio.h>

/**
 * @param arr 数组
 * @param n 数组元素个数
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
 * @param arr 待排序的数组
 * @param left 数组的左边界索引
 * @param right 数组的右边界索引
 */

void quick_sort(int arr[], int left, int right)
{
    int i = left;
    int j = right;

    int p = arr[(left + right) / 2];
    int temp;

    if (left >= right)
    {
        return;  // 排序完成
    }

    while (i <= j)
    {
        /* 把小于中间基准值的数放到数组左边, 把大于中间基准值的数放到数组右边  */
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
            /*交换数据，即小的放左边，大的放右边 */
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } 

    quick_sort(arr, left, p-1);
    quick_sort(arr, p+1, right);
    //print_array(&arr[left], right - left + 1); /* 打印数组，调试使用 */
}

int main()
{
    int arr[] = {4, 3, 2, 1, 5, 6, 7, 8, 9, 10, 11, 89};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("old arr : ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("new arr : ");
    print_array(arr, n);
    return 0;
}
