#define MAX 50
typedef char ElementType;
typedef struct StackType
{
    ElementType *Element;
    int top;
}StackType;
void Initialize(StackType *Stack);
int Empty(StackType *Stack);
int Full(StackType *Stack);
void Push(StackType *Stack, ElementType x);
ElementType Pop(StackType *Stack);