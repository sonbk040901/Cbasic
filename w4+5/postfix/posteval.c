#include "stack.h"
#include <ctype.h>
int tinh(int a, int b, char pt)
{
    switch (pt)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        /*...*/
        break;
    default:
        break;
    }
}
int main(int argc, char const *argv[])
{
    STACK *s;
    s = MakeNullStack();
    ElementType root;
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalnum(argv[1][i]))
        {
            root.x = argv[1][i] - 48;
            Push(s, root);
        }
        else
        {
            int b = Pop(s).x;
            int a = Pop(s).x;
            root.x = tinh(a, b, argv[1][i]);
            Push(s, root);
        }
    }
    printf("Dap an: %d\n", Pop(s).x);
    return 0;
}
