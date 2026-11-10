/*
Problem description: There are n activities that all require the same resource (such as a classroom), 
and the resource can be used by only one activity at any moment.

Each activity i has a start time si and end time fi for using the resource, and si < fi. 
In other words, if activity i is selected, it occupies the resource during the half-open interval [si, fi).

How should the activities be arranged so that as many activities as possible can use the public resource 
efficiently?

If the interval [si, fi) does not overlap with [sj, fj), then activities i and j are compatible; that is,
when sj ≥ fi, activities i and j are compatible. In this way, the activity scheduling problem becomes 
selecting the largest compatible subset of activities from the given set.
*/
/*
Sort the activities in ascending order of their end times and renumber them. Then perform the 
following greedy selection process: first select activity 1, and then check each activity i in 
sequence to see whether it is compatible with all previously selected activities. If it is compatible, 
add it to the selected set; otherwise, continue checking the next activity for compatibility.
*/


#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;

    printf("请输入活动数量: ");
    scanf("%d", &n);

    int start[MAXN];
    int end[MAXN];
    int index[MAXN];   // 记录原始编号，排序后仍能知道是第几个活动

    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个活动的开始时间和结束时间: ", i + 1);
        scanf("%d %d", &start[i], &end[i]);
        index[i] = i + 1;
    }

    // 按结束时间从小到大排序，结束时间相同时可按开始时间排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (end[j] > end[j + 1] ||
               (end[j] == end[j + 1] && start[j] > start[j + 1])) {

                int tmp;

                tmp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = tmp;

                tmp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tmp;

                tmp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tmp;
            }
        }
    }

    int count = 0;
    int lastEnd = -1;

    printf("\n选择的活动:\n");

    for (int i = 0; i < n; i++) {
        if (start[i] >= lastEnd) {
            count++;
            lastEnd = end[i];
            printf("活动 %d, 开始时间 %d, 结束时间 %d\n",
                   index[i], start[i], end[i]);
        }
    }

    printf("\n最多可以安排 %d 个活动\n", count);

    return 0;
}
