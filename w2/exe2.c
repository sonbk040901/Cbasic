#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct point
{
    double x;
    double y;
} point_t;
typedef struct circle
{
    point_t center;
    double radius;
} circle_t;
int is_in_circle(point_t p, circle_t c)
{
    if (pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2) > pow(c.radius, 2))
        return 0;
    return 1;
}
int main(void)
{
    point_t point;
    circle_t ci;
    puts("Hay nhap toa do tam va ban kinh cua duong tron:");
    scanf("%lf%lf%lf", &ci.center.x, &ci.center.y, &ci.radius);
    puts("Hay nhap toa do cua diem can kiem tra:");
    scanf("%lf%lf", &point.x, &point.y);
    printf("%d\n", is_in_circle(point, ci));
    return 0;
}