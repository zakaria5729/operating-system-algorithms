#include<stdio.h>

int main()
{
    int n, i, j, l=0, sum=0, avg_wt=0, avg_tat=0, count=0, max, min, min_loc;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int bt[n], res[n], proc[n], wt[n];

    printf("Enter the %d process's burst time\n", n);
    for(i=0; i<n; i++)
    {
        printf("P%d = ", i+1);
        scanf("%d", &bt[i]);

        if(count == 0)
        {
            max = bt[i];
            min = bt[i];
            count++;
        }
        else
        {
            if(bt[i] < min)
            {
                min = bt[i];
                min_loc = i;
            }
            if(bt[i] > max)
            {
                max = bt[i];
            }
        }
    }

    for(i=0; i<n; i++)
    {
        sum += bt[min_loc];
        res[i] = sum;
        proc[i] = min_loc;

        wt[i] = res[i] - bt[min_loc];

        bt[min_loc] = ++max;
        min = ++max;

        for(j=0; j<n; j++)
        {
            if(bt[j] < min)
            {
                min = bt[j];
                min_loc = j;
            }
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
        printf("P%d\t%d\t%d\t%d\n", proc[i]+1, res[i], res[i], wt[i]);
        avg_tat += res[i];
        avg_wt += wt[i];
    }

    printf("\nAverage waiting time = %d\n", avg_wt/n);
    printf("Average turn-around time = %d\n", avg_tat/n);

    return 0;
}
