#include "lkd.h"
// Than chuong trinh chinh
int main()
{
  PointerType *ds;
  PointerType *pv;
  ds = NULL;
  pv = NULL;
  int i, p;
  // Chen 3 gia tri vao vi tri dau
  ds = InsertToHead(ds, 1);
  ds = InsertToHead(ds, 2);
  ds = InsertToHead(ds, 3);
  // In ra danh sach sau khi chen
  printf("In ra danh sach sau khi chen vao dau \n");
  Print(ds);
  // Chen so 4 vao vi tri cuoi cua danh sach
  printf("Danh sach sau khi chen 4 vao cuoi \n");
  ds = InsertToLast(ds, 4);
  Print(ds);

  // In ra danh sach sau khi xoa phan tu dau
  printf("In ra danh sach sau khi xoa dau \n");
  ds = DeleteHead(ds);
  Print(ds);

  // In ra danh sach sau khi xoa phan tu cuoi
  printf("In ra danh sach sau khi xoa cuoi \n");
  ds = DeleteLast(ds);
  Print(ds);

  // In ra danh sach sau khi xoa phan tu dau
  printf("Cho vi tri ban muon chen 4 vao sau p = ");
  scanf("%d", &p);
  pv = ds;
  i = 1;
  while (i < p)
  {
    pv = pv->Next;
    i++;
  }
  InsertMiddle(pv, 4);
  Print(ds);
  getchar();
  return 0;
}