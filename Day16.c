/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];
    int freq[100];
    int i, j;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        if(freq[i] == -1)
        {
            int count = 1;
            for(j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(freq[i] > 0)
        {
            printf("%d:%d ", arr[i], freq[i]);
        }
    }

    return 0;
}