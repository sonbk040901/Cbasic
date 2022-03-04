#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX 100
int main()
{
    ElementType c;
    ElementType a;
    STACK *First;
    First = MakeNullStack();
    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &c.x);
        a = c;
        Push(First, a);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%c", Pop(First).x);
    }
    putchar('\n');
    return 0;
}