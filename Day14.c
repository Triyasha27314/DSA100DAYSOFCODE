/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in 
which all diagonal elements are 1 and all non-diagonal elements are 0.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[100][100];
    int i, j;
    int flag = 1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                if(a[i][j] != 1)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if(a[i][j] != 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}