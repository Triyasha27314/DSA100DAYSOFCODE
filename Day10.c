/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;
    int flag = 1;

    while(start < end)
    {
        if(s[start] != s[end])
        {
            flag = 0;
            break;
        }

        start++;
        end--;
    }

    if(flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}