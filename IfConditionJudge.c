#include <stdio.h>

int main() {
    int score;

    // 提示用户输入成绩
    printf("请输入你的考试成绩（0-100）：");
    scanf("%d", &score);

    // 使用 if-else if-else 进行条件判断
    if (score < 0 || score > 100) {
        printf("输入错误！成绩必须在 0 到 100 之间。\n");
    } else if (score >= 90) {
        printf("优秀！你的成绩是 A。\n");
    } else if (score >= 80) {
        printf("良好！你的成绩是 B。\n");
    } else if (score >= 70) {
        printf("中等！你的成绩是 C。\n");
    } else if (score >= 60) {
        printf("及格！你的成绩是 D。\n");
    } else {
        printf("不及格！你的成绩是 F，需要继续努力。\n");
    }

    return 0;
}
