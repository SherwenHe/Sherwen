/* 反转字符串的程序 */
#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    printf("反转前的字符串：%s\n", str);
    reverse(str);
    printf("反转后的字符串：%s\n", str);
    return 0;
}
