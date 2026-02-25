/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.*/

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

    int k;
    scanf("%d", &k);

    int count = 0;
    int found = 0;

    for(i = 0; i < n; i++)
    {
        count++;

        if(arr[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", count);

    return 0;
}