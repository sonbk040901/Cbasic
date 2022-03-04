#include <stdio.h>
#include <stdlib.h>
#include "balan.h"
void Initialize(StackType *Stack)
{
    Stack->Element = (ElementType *)malloc(sizeof(ElementType) * MAX);
    Stack->top = 0;
}
int Empty(StackType *Stack)
{
    return Stack->top == 0;
}
int Full(StackType *Stack)
{
    return (Stack->top) == MAX;
}
void Push(StackType *Stack, ElementType x)
{
    if (Full(Stack))
    {
        printf("\nStack full cmnr\n");
    }
    else
        Stack->Element[(Stack->top)++] = x;
}
ElementType Pop(StackType *Stack)
{
    if (Empty(Stack))
    {
        return 0;
    }
    else
    {
        return Stack->Element[(--(Stack->top))];
    }
}