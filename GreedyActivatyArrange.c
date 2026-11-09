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
int main()
{
    int act[11][3]={{1,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,8},{6,5,9},
                     {7,6,10},{8,8,11},{9,8,12},{10,2,13},{11,12,14}};

    int i,j,no,start,minfinal,loop,sel[11];     /* sel[] stores the compatible activity numbers */
    j=0;
    int n=11;
    start=0;        /* Activity start time */
    printf("Activate arrangement:\n");
    while(1)
    {
        loop=0;        /* Mark whether the loop should terminate */
        minfinal=24;    /* Record the earliest end time of activities judged in each round */
        no=0;            /* Record the index of the matching activity */
        for(i=0;i<n;i++)
            if(act[i][1]>=start  && act[i][2]<minfinal)     
            {   
                minfinal=act[i][2];
                no=i;
                loop=1;
            }

        if(loop)
            sel[j]=no;
        else
            break;
        start=act[no][2];
        j++;
    }
    
    for(i=0;i<j;i++)
        printf("Activity %2d: start time %3d,  end time %3d\n",sel[i]+1,act[sel[i]][1],act[sel[i]][2]);
}
