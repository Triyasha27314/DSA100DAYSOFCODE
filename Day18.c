/*Problem: Given an array of integers, rotate the array to the right by k positions.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100], temp[100];
    int i, k;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }

    for(i = n - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    for(i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}