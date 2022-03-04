#include <stdio.h>
#include <string.h>
void main()
{
    char a1[] = "computerize", a2[] = "computer";
    printf("%s", strstr(a1, a2));
}