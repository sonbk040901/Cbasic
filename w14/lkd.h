
typedef int ElementType;
struct _PointerType{
  ElementType data;
  struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

PointerType *InsertMiddle(PointerType *Prev, ElementType X);

ElementType Delete(PointerType *Prev);

PointerType *InsertToHead(PointerType *First, ElementType X);

PointerType *InsertToLast(PointerType *First, ElementType X);

PointerType *DeleteHead(PointerType *First);

PointerType *DeleteLast(PointerType *First);

int IsEmpty(PointerType *First);

PointerType *MakeNull(PointerType *First);

void Print(PointerType *First);