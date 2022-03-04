#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    FILE *f;
    f = fopen("text", "r");
    char str[MAX] = "computerizi", key[MAX], str1[MAX];
    fgets(key, MAX, stdin);
    key[strlen(key) - 1] = 0;
    while (!feof(f) && fgets(str, MAX, f))
    {
        int i;
        for (i = 0; i < strlen(str) - 1; i++)
            str1[i] = tolower(str[i]);
        str[i] = 0;
        if (strstr(str1, key))
            printf("%s\n", str);
    }
    fclose(f);
    return 0;
}
