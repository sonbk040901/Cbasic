#include <stdio.h>
#include <stdlib.h>
#define MAX 100
static int i;
int Binary_Search(int a[], int lower, int highter, int key)
{
    if (lower == highter)
    {
        return a[lower] == key ? lower : -1;
    }
    int mid = (lower + highter) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] > key)
    {
        i++;
        return Binary_Search(a, lower, mid - 1, key);
    }
    else
    {
        i++;
        return Binary_Search(a, mid + 1, highter, key);
    }
}
void main()
{
    int arr[MAX];
    int j = 0;
    while (j < MAX)
    {
        arr[j] = j+1;
        j++;
    }
    int key, root;
    puts("Hay nhap gia tri ma ban muon tim: ");
    scanf("%d", &key);
    i = 1;
    root = Binary_Search(arr, 0, MAX - 1, key);
    if (root != -1)
    {
        printf("Vi tri cua gia tri %d trong mang la: %d\n", key, root);
        printf("So phep toan duoc thuc hien la: %d\n", i);
    }
    else
    {
        puts("Khong tim thay gia tri ma ban muon tim");
        printf("So phep toan duoc thuc hien la: %d\n", i);
    }
}