#include <stdio.h>
#include "balan.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int uutien(char c)
{
    switch (c)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '(':
        return 0;
        break;
    }
}
void make_math_stack(StackType *stack, char *x)
{
    for (int i = 0; i < strlen(x); i++)
    {
        Push(stack, x[strlen(x) - i - 1]);
    }
}
void push_char(StackType *stack, ElementType x)
{
    ElementType m, n;
    if (x == '(')
        Push(stack, x);
    else
        switch (x == ')')
        {
        case 0:
            m = Pop(stack);
            if (uutien(m) < uutien(x))
            {
                Push(stack, m);
                Push(stack, x);
            }
            else
            {
                printf("%c ", m);
                push_char(stack, x);
            }
            break;
        default:
            while ((n = Pop(stack)) != '(')
                printf("%c ", n);
            break;
        }
}
void main()
{
    StackType math;
    StackType characters;
    Initialize(&math);
    Initialize(&characters);
    ElementType root;
    char insert[MAX];
    fgets(insert, MAX, stdin);
    insert[strlen(insert) - 1] = 0;
    make_math_stack(&math, insert);
    while (!Empty(&math))
    {
        root = Pop(&math);
        if (isdigit(root))
        {
            printf("%c ", root);
        }
        else
            push_char(&characters, root);
    }
    while (root = Pop(&characters))
    {
        printf("%c ", root);
    }
    putchar('\n');
}