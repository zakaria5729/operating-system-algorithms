#include<stdio.h>

int main()
{

    int count,j,n,time,remain,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

    printf("Enter Total Process: ");
    scanf("%d",&n);
    remain=n;

    printf("\nEnter the %d process's arrival & burst time\n", n);
    for(count=0; count<n; count++)
    {
        printf("P%d: ", count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&time_quantum);

    printf("\n\tTAT\tWT\n");
    for(time=0,count=0; remain!=0;)
    {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0)
        {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
            remain--;
            printf("P%d\t%d\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }

        if(count==n-1)
        {
            count=0;
        }
        else if(at[count+1]<=time)
        {
            count++;
        }
        else
        {
            count=0;
        }
    }
    printf("\nAverage Waiting Time= %.2f\n",wait_time*1.0/n);
    printf("Avg Turnaround Time = %.2f\n",turnaround_time*1.0/n);

    return 0;
}
