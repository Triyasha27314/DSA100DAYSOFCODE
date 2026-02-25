/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained 
by adding corresponding elements of the matrices.*/

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100], b[100][100], sum[100][100];
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}