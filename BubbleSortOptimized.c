#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;  // 每轮开始前清零标志位
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // 发生了交换
            }
        }
        if (!swapped) break;  // 本轮无交换，提前退出
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
