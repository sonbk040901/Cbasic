#include <stdio.h>
#include <stdlib.h>
void main()
{
    int x, *y, i, sum = 0;
    FILE *f;
    if ((f = fopen("ducha.txt", "a+")) == NULL)
    {
        printf("File not found!\n");
        exit(1);
    }
    printf("Hay nhap vao du lieu: ");
    scanf("%d", &x);
    y = malloc(x * sizeof(int));
    for (i = 0; i < x; i++)
    {
        scanf("%d", &y[i]);
        sum += y[i];
    }
    for (i = x-1; i >= 0; i--)
    {
        fprintf(f, "%d ", y[i]);
    }
    fprintf(f,"%d\n", sum);
    free(y);
    fclose(f);
}