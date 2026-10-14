/*
 * 质数判断程序
 * 输入一个正整数，判断它是否为质数
 */
#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    if (is_prime(n)) {
        printf("%d 是质数！\n", n);
    } else {
        printf("%d 不是质数！\n", n);
    }
    return 0;
}
