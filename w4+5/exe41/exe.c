#include "stack.h"
#define MAX 100
int main()
{
    ElementType x;
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("out.txt", "w+");
    STACK *s;
    s = MakeNullStack();
    while (!feof(fin))
    {
        fgets(x.name, 40, fin);
        fgets(x.phone, 15, fin);
        fgets(x.email, 40, fin);
        Push(s, x);
    }
    while (!isEmptyS(s))
    {
        x = Pop(s);
        fputs(x.name, fout);
        fputs(x.phone, fout);
        fputs(x.email, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}