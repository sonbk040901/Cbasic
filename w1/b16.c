#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int n, char const *solieu[])
{
    if (n != 3)
    {
        puts("Ban chua nhap du chieu dai va chieu rong!!!");
        exit(0);
    }
    float a = atof(solieu[1]), b = atof(solieu[2]);
    printf("Dien tich va chu vi cua HCN la: %.2f va %.2f\n", a * b, 2 * (a + b));
    return 0;
}