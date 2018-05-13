#include<stdio.h>

int main()
{
    int n, i, j, sum=0, avg_wt=0, avg_tat=0, min_loc, min, max, count=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int bt[n], at[n], proc[n], tat[n], wt[n], res[n];

    printf("Enter the %d process's arrival & burst time\n", n);
    for(i=0; i<n; i++)
    {
        printf("P%d = ", i+1);
        scanf("%d%d", &at[i], &bt[i]);

        if(count == 0)
        {
            max = at[i];
            min = at[i];
            count++;
        }
        else
        {
            if(at[i] < min)
            {
                min = at[i];
                min_loc = i;
            }
            if(at[i] > max)
            {
                max = at[i];
            }
        }
    }
    sum = at[min_loc];

    for(i=0; i<n; i++)
    {
        sum += bt[min_loc];
        res[i] = sum;
        proc[i] = min_loc;

        tat[i] = res[i] - at[min_loc];
        wt[i] = tat[i] - bt[min_loc];

        at[min_loc] = ++max;
        min = ++max;

        for(j=0; j<n; j++)
        {
            if(at[j] < min)
            {
                min = at[j];
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
        printf("P%d\t%d\t%d\t%d\n", proc[i]+1, res[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage waiting time = %d\n", avg_wt/n);
    printf("Average turn-around time = %d\n", avg_tat/n);

    return 0;
}

