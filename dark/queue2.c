#include<stdio.h>
#include<stdlib.h>
struct Address
{
    char name[20];
    char phone[15];
    char email[30];
};
typedef struct Address ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef struct
{
    Position Front;
    Position Rear;
} Queue;
void MakeNull_Queue(Queue *Q)
{
    
}