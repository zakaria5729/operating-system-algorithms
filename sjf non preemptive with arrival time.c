#include<stdio.h>

int main()
{
    int i=0, j, l=0, p=0, q=0, n, sum=0, temp, min_at_time, min_at_loc, max_at_time, min_bt_time, count1=0, avg_tat=0, avg_wt=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int at[n], bt[n], res[n], proc[n], wt[n];

    printf("\nEnter the arrival time & burst time of\n");
    for(i=0; i<n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);

        //find the min value & location of arrival time
        if(count1==0)
        {
            min_at_time = at[i];
            min_at_loc = i;
            count1++;
        }
        else
        {
            if(at[i] < min_at_time)
            {
                min_at_time = at[i];
                min_at_loc = i;
            }
        }
    }

    sum = min_at_time;
    sum += bt[min_at_loc];
    res[l++] = sum;

    proc[p++] = min_at_loc;
    bt[min_at_loc] = -1;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<(n-1)-i; j++)
        {
            if(bt[j] > bt[j+1])
            {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(bt[i] != -1)
        {
            sum += bt[i];
            res[l++] = sum;

            proc[p++] = i;
        }
    }

    printf("\nGantt chart->\n");
    for(i=0; i<n; i++)
    {
        printf("P%d = %d\n", proc[i]+1, res[i]);
    }

    printf("\n\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++)
    {
        wt[i] = res[i] - bt[i];
        printf("P%d\t%d\t%d\t%d\n", proc[i]+1, res[i], res[i], wt[i]);
        avg_tat += res[i];
        avg_wt += wt[i];
    }

    printf("\nAverage waiting time = %d\n", avg_wt/n);
    printf("Average turn-around time = %d\n", avg_tat/n);


    return 0;
}
