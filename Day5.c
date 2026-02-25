/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted 
in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>

int main()
{
    int p, q;
    int i, j, k;

    scanf("%d", &p);
    int arr1[100];

    for(i = 0; i < p; i++)
    {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &q);
    int arr2[100];

    for(i = 0; i < q; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int result[200];

    i = 0;
    j = 0;
    k = 0;

    while(i < p && j < q)
    {
        if(arr1[i] < arr2[j])
        {
            result[k] = arr1[i];
            i++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < p)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while(j < q)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }

    for(i = 0; i < p + q; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}