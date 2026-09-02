#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isvalid(char c[])
{
    char stack[20];
    int top = -1;

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '{' || c[i] == '[' || c[i] == '(')
        {
            stack[++top] = c[i];
        }
        else if (c[i] == '}' || c[i] == ']' || c[i] == ')')
        {
            if (top == -1)
                return 0;

            if ((c[i] == ')' && stack[top] == '(') ||
                (c[i] == ']' && stack[top] == '[') ||
                (c[i] == '}' && stack[top] == '{'))
            {
                top--;
            }
            else
            {
                return 0;
            }
        }
    }

    return top == -1;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int hasoverprecedence(char a, char b)
{
    if (precedence(a) == precedence(b))
    {
        if (a == '^')
            return 0;       // ^ is right associative
        else
            return 1;
    }

    return precedence(a) > precedence(b) ? 1 : 0;
}

char *postfix(char c[], int len)
{
    char *ans = (char *)calloc(len + 1, sizeof(char));

    int j = 0;
    char stack[20];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        /* Operand */
        if ((c[i] >= 'a' && c[i] <= 'z') ||
            (c[i] >= 'A' && c[i] <= 'Z') ||
            (c[i] >= '0' && c[i] <= '9'))
        {
            ans[j++] = c[i];
        }

        /* Opening bracket */
        else if (c[i] == '(')
        {
            stack[++top] = c[i];
        }

        /* Closing bracket */
        else if (c[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                ans[j++] = stack[top--];
            }

            if (top != -1)
                top--;       // remove '('
        }

        /* Operator */
        else if (c[i] == '+' || c[i] == '-' ||
                 c[i] == '/' || c[i] == '*' || c[i] == '^')
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   hasoverprecedence(stack[top], c[i]))
            {
                ans[j++] = stack[top--];
            }

            stack[++top] = c[i];
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        ans[j++] = stack[top--];
    }

    ans[j] = '\0';

    return ans;
}

float evalpostfix(char c[])
{
    int stack[20];
    int top = -1;

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            stack[++top] = c[i] - '0';
        }
        else
        {
            int a = stack[top--];
            int b = stack[top--];

            switch (c[i])
            {
                case '+':
                    stack[++top] = b + a;
                    break;

                case '-':
                    stack[++top] = b - a;
                    break;

                case '*':
                    stack[++top] = b * a;
                    break;

                case '/':
                    stack[++top] = b / a;
                    break;

                case '^':
                    stack[++top] = pow(b, a);
                    break;

                default:
                    printf("Invalid operator\n");
            }
        }
    }

    return stack[top];
}

int main()
{
    char expression[] = "(a+b)/c+d^e*c";

    if (isvalid(expression))
    {
        printf("It is valid\n");
    }
    else
    {
        printf("It is not valid\n");
    }

    char *ans = postfix(expression, strlen(expression));

    printf("Postfix: %s\n", ans);

    printf("Evaluation: %f\n", evalpostfix("12+3*24^-"));

    free(ans);

    return 0;
}