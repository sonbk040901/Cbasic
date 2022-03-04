#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int main(void)
{
    char rear[MAX], front[MAX];
    fgets(rear, MAX, stdin);
    rear[strlen(rear) - 1] = 0;
    fgets(front, MAX, stdin);
    front[strlen(front) - 1] = 0;
    char *root;
    root = (char *)calloc(sizeof(char), 1);
    strcat(root, rear);
    strcat(root, front);
    puts(root);
    free(root);
    return 0;
}