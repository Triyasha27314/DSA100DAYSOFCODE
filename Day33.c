/*Problem: Convert an infix expression to postfix notation using stack.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100];
    scanf("%s", infix);

    int i;
    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
                printf("%c", pop());

            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                printf("%c", pop());

            push(ch);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}