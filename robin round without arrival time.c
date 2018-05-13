#include<stdio.h>

int main()
{
    int n, i, l=0, j=0, k=0, bt[50], res[50], pro[50], q, sum=0, count=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("P%d burst time: ", i+1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &q);

    while(count < n)
    {
        for(i=0; i<n; i++)
        {
            if(bt[i] <= q && bt[i] != -1)
            {
                sum += bt[i];
                res[j++] = sum;

                bt[i] = -1;
                count++;

                pro[k++] = i+1;
            }
            else if(bt[i] > q && bt[i] != -1 & bt[i] != 0)
            {
                sum += q;
                res[j++] = sum;

                bt[i] = bt[i] - q;
                pro[k++] = i+1;
            }
        }
    }

    res[j] = -7;
    printf("\n");

    printf("Gantt chart-->")
    while(res[l] != -7)
    {
        printf("P%d = %d\n", pro[l], res[l]);
        l++;
    }

    return 0;
}
