#include <stdio.h>
#include <string.h>
int main()
{
    int a;
    FILE *f = fopen("test.txt", "r+");
    for (int i = 0; i < 2; i++)
    {
        // fscanf(f, "%d", &a);
        // printf("%d\n", a);
        // fseek(f, 1, SEEK_CUR);

        fseek(f, 1, SEEK_CUR);
        fprintf(f, "1");
    }
    fclose(f);
    return 0;
}