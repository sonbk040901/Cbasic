#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20
int main(int argc, char const *argv[])
{
    char str[MAX];
    int time[26];
    gets(str);
    for (int i = 0; i < 26; i++)
        time[i] = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
        time[(int)str[i] - 65]++;
    }
    for (int i = 0; i < 26; i++)
        if (time[i] != 0)
            printf("Chu cai %c: %d\n", 65 + i, time[i]);
    return 0;
}