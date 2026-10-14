#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess;
    srand(time(0));
    num = rand() % 100 + 1;
    do
    {
        printf("请输入一个数字（ 1-100 ）：");
        scanf("%d", &guess);
        if (guess > num)
        {
            printf("太大了！\n");
        }
        else if (guess < num)
        {
            printf("太小了！\n");
        }
    } while (guess != num);
    printf("猜对了！\n");
    return 0;
}
