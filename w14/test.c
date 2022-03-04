#include <stdio.h>
int check(int a[])
{
    if (a[0] >= a[1] + a[2])
        return 0;
    if (a[1] >= a[0] + a[2])
        return 0;
    if (a[2] >= a[0] + a[1])
        return 0;
    return 1;
}
int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    if (check(a) == 0)
        puts("Day khong phai do dai 3 canh cua 1 tam giac!");
    else
    {
        if (a[0] == a[1] && a[1] == a[2])
        {
            puts("Day la tam giac deu!");
            return 0;
        }
        if (((a[0] - a[1]) * (a[1] - a[2]) * (a[2] - a[0])) == 0)
        {
            puts("Day la tam giac can!");
            return 0;
        }
    }
    return 0;
}