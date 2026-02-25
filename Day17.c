/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.*/

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

    int max = arr[0];
    int min = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}