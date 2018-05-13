#include<stdio.h>

int main()
{
    int n, i, j, sum=0, avg_wt=0, avg_tat=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    int bt[n], res[n];

    printf("Enter the %d process's burst time\n", n);
    for(i=0; i<n; i++)
    {
        printf("P%d = ", i+1);
        scanf("%d", &bt[i]);

        sum += bt[i];
        res[i] = sum;
    }

    printf("\nGantt chart->\n");
    for(i=0; i<n; i++)
    {
        printf("P%d = %d\n", i+1, res[i]);
    }

    printf("\n\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i+1, res[i], res[i], res[i]-bt[i]);
        avg_tat += res[i];
        avg_wt += res[i]-bt[i];
    }

    printf("\nAverage waiting time = %d\n", avg_wt/n);
    printf("Average turn-around time = %d\n", avg_tat/n);

    return 0;
}
