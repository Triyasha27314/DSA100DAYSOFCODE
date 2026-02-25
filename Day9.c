/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given 
code name so that its characters appear in the opposite order.*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("%s", str);

    return 0;
}