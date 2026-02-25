/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];
    int i;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int j = 0;

    for(i = 1; i < n; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    for(i = 0; i <= j; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}