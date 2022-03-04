#include <stdio.h>
#define MAX 5
int main(int argc, char const *argv[])
{
    int mang1[MAX];
    int mang2[MAX];
    int i = 0;
    for (int j = 0; j < MAX; j++)
        scanf("%d", &mang1[j]);
    for (int j = 0; j < MAX; j++)
        scanf("%d", &mang2[j]);
    while (mang1[i] != mang2[i] && i < MAX)
        i++;
    if (i < MAX)
        puts("Hay mang giong nhau!");
    else
        puts("Hai mang khong giong nhau!");
    return 0;
}
