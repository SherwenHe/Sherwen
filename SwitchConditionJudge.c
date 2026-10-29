#include <stdio.h>

int main() {
    int day;

    // 提示用户输入星期几的数字
    printf("请输入星期几的数字（1-7）：");
    scanf("%d", &day);

    // 使用 switch 语句进行多分支判断
    switch (day) {
        case 1:
            printf("星期一：今天是工作日，加油！\n");
            break;  // 必须加 break，否则会“穿透”到下一个 case
        case 2:
            printf("星期二：继续奋斗的一天。\n");
            break;
        case 3:
            printf("星期三：一周过半，坚持住！\n");
            break;
        case 4:
            printf("星期四：黎明前的黑暗，快到了！\n");
            break;
        case 5:
            printf("星期五：明天就是周末啦！\n");
            break;
        case 6:
            printf("星期六：周末快乐，好好休息！\n");
            break;
        case 7:
            printf("星期日：享受假期的最后一天吧。\n");
            break;
        default:
            printf("输入错误！请输入 1 到 7 之间的数字。\n");
            break;
    }

    return 0;
}
