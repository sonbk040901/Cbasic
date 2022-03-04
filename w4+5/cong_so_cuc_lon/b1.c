#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main(int argc, char *value[])
{
    if (argc != 3)
    {
        printf("Chua nhap so hang!\n");
        exit(1);
    }
    int a = atoi(value[1]);
    int b = atoi(value[2]);
    STACK *value1, *value2, *value3;
    value1 = MakeNullStack();
    value2 = MakeNullStack();
    value3 = MakeNullStack();
    ElementType temp;
    int i;
    int r = 0;
    int v1, v2;
    for (i = 0; i < strlen(value[1]); i++)
    {
        temp = (a / (int)pow(10, strlen(value[1]) - i - 1)) % 10;
        Push(value1, temp);
    }
    for (i = 0; i < strlen(value[2]); i++)
    {
        temp = (b / (int)pow(10, strlen(value[2]) - i - 1)) % 10;
        Push(value2, temp);
    }
    while (!isEmptyS(value1) || !isEmptyS(value2) || r != 0)
    {
        v1 = Pop(value1);
        v2 = Pop(value2);
        Push(value3, ((v1 + v2) % 10 + r) % 10);
        r = (v1 + v2 + r) / 10;
    }
    while (!isEmptyS(value3))
    {
        printf("%d", Pop(value3));
    }
    putchar('\n');
}