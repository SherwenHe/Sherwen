#include <stdio.h>

#define SORT_DATA_TYPE int

/**
 * @brief 打印数据
 *
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
 * @brief 快速排序
 *
 * @param arr 待排序的数组
 * @param left 数组的左边界索引
 * @param right 数组的右边界索引
 */

void quick_sort(SORT_DATA_TYPE arr[], int left, int right)
{
    int i = left;
    int j = right;

    SORT_DATA_TYPE p = arr[(left + right) / 2];
    SORT_DATA_TYPE temp;

    if (left >= right)
    {
        /* 排序完成 */
        return;
    }

    while (i <= j)
    {
        /*
            把小于中间基准值的数放到数组左边
            把大于中间基准值的数放到数组右边
         */

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
            /*
                交换数据，即小的放左边，大的放右边
            */
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    print_array(&arr[left], right - left + 1); /* 打印数组，调试使用 */

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main()
{
    SORT_DATA_TYPE arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("old arr : ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("new arr : ");
    print_array(arr, n);
    return 0;
}
