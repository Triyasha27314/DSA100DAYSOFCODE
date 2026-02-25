/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square 
matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and 
j).*/

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];
    int i, j;
    int flag = 1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    if(m != n)
    {
        flag = 0;
    }
    else
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][j] != a[j][i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
    }

    if(flag == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}