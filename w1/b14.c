#include <stdio.h>
int main(int argc, char const *argv[])
{
    double x;
    scanf("%lf", &x);
    int y = (int)x;
    printf("%d %g\n", y, x -y);
    return 0;
}