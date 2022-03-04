#include "stack.h"
STACK *MakeNullStack(void)
{
    STACK *S;
    S = (STACK *)malloc(sizeof(STACK));
    S->top = NULL;
    return S;
}
int sizeS(STACK *S)
{
    LinkList *root = S->top;
    int i = 0;
    while (root&& ++i)
        root = root->next;
    return i;
}
int isEmptyS(STACK *S)
{
    return (S->top == NULL);
}
int isFullS(STACK *S)
{
    return (sizeS(S) == FULL);
}
int Push(STACK *S, ElementType x)
{
    if (!isFullS(S))
    {
        LinkList *new;
        new = (LinkList *)malloc(sizeof(LinkList));
        new->next = S->top;
        new->data = x;
        S->top = new;
    }
    else
    {
        puts("Full Stack!");
    }
    return sizeS(S);
}
ElementType Pop(STACK *S)
{
    if (!isEmptyS(S))
    {
        ElementType x;
        LinkList *root;
        root = S->top;
        S->top = root->next;
        x = root->data;
        free(root);
        return x;
    }
    else
    {
        ElementType zero = (ElementType)0;
        return zero;
    }
}
void PrintS(STACK *S) /*Ham nay phu thuoc vao cau truc du lieu cua data*/
{
    /*code*/
}