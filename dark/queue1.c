#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 5
struct Address
{
    char name[20];
    char phone[15];
    char email[30];
};
typedef struct Address ElementType;
typedef struct queue
{
    ElementType Elements[MaxLength];
    int Front;
    int Rear;
} Queue;
void MakeNull_Queue(Queue *Q)
{
    Q->Front = -1;
    Q->Rear = -1;
}
int Empty_Queue(Queue Q)
{
    return Q.Front == -1;
}
int Full_Queue(Queue Q)
{
    return (Q.Rear - Q.Front + 1) == MaxLength;
}
void En_Queue(Queue *Q, ElementType x)
{
    if (Full_Queue(*Q))
    {
        puts("Full queue roi ban eyy!");
    }
    else
    {
        if (Empty_Queue(*Q))
            Q->Front++;
        Q->Rear++;
        Q->Elements[Q->Rear] = x;
    }
}
ElementType De_Queue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        return Q->Elements[Q->Front];
        Q->Front++;
        if (Q->Front > Q->Rear)
        {
            MakeNull_Queue(Q);
        }
    }
    else
    {
        puts("Het Queue roi ban eyy!");
        exit(0);
    }
    
}
void main()
{
}