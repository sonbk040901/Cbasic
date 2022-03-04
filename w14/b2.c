#include "lkd.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void MakeNUllSet(PointerType *list[])
{
    int i;
    for (int i = 0; i < MAX; i++)
    {
        list[i] = NULL;
    }
}
int Search