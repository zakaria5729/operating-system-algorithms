#include<stdio.h>

int main()
{
    int n, r, i, l, j, k, p=0, q=0, ct=0, sum=0, avg_wt=0, avg_tat=0, flag=0, count=0, safe=0;
    printf("Enter the number of processes & resources: ");
    scanf("%d%d", &n, &r);

    int avail[r], proc[n], sum_arr[30]={0};
    int alloc[n][r], max[n][r], need[n][r];

    //sum_arr[0] = 0;

    //allocation input
    printf("\nEnter the allocation resources\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            scanf("%d", &alloc[i][j]);
            //sum of allocation in column wise
            sum_arr[j] += alloc[i][j];
        }
    }

    //maximum input
    printf("\nEnter the maximum resources\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    //available input
    printf("\nEnter the available resources\n");
    for(j=0; j<r; j++)
    {
        scanf("%d", &avail[j]);
        //sum of allocation + available memory
        sum_arr[j] += avail[j];
    }

    //need calculate
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    j = 0;
    while(count < n)
    {
        if(ct == n)
        {
            j = 0;
        }
        for(l=0; l<r; l++)
        {
            if(need[j][l] <= avail[l] && need[j][l]!= -7 && flag<=r)
            {
                flag++;

                if(flag == r)
                {
                    k = j;
                    for(l=0; l<r; l++)
                    {
                        avail[l] = avail[l] + alloc[k][l];
                        need[k][l] = -7;
                    }
                    count++;
                    proc[q++] = j;
                }
            }
        }
        j++, ct++, flag = 0;
    }

    printf("\n\nSum of total available resources\n");
    for(i=0; i<r; i++)
    {
        printf("%d ", avail[i]);
    }

    printf("\nSum of allocation + available memory\n");
    for(j=0; j<r; j++)
    {
        printf("%d ", avail[j]);

        if(avail[j] == sum_arr[j])
        {
            safe++;
        }
        else
        {
            safe = 0;
        }
    }

    if(safe == r)
    {
        printf("\n\nYes, We are in safe state.\n");

        printf("\nThe safe sequence is\n");
        for(i=0; i<n; i++)
        {
            printf("P%d ", proc[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n\nWe are not in safe state.\n");
    }

    return 0;
}
