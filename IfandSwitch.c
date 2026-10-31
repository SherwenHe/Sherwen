/*
编写一个 C 程序，根据用户输入的 用户等级 level 和 操作编号 op 输出提示信息：
    条件	             预期输出
非管理员，输入 1	      拒绝访问
非管理员，输入 2	      拒绝访问
非管理员，输入 3	      拒绝访问
管理员，输入 1	        管理员执行查询
管理员，输入 2	        管理员执行备份
管理员，输入 3	        管理员执行重启
其他输入	            无效操作
*/


#include <stdio.h>
int main(void) {
    int level;  /* 1: Administrator, 0: Regular user */
    int op;

    printf("Enter level (0/1) and operation (1-3): ");
    scanf("%d %d", &level, &op);
   
    if (level == 1)
    {
        switch (op) {
            case 1:
                printf("Switch: Lookup\n");
                break;
            case 2:
                printf("Switch: Backup\n");
                break;
            case 3:
                printf("Switch: Reboot\n");
                break;
            default:
                printf("Switch: Invalid operation\n");
                break;
        }   
    }
    else
        printf("Access denied\n");
    return 0;
}
