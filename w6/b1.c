#include <stdio.h>
#include <stdlib.h>
#define MAX 11
int search(int *arr, int key)
{
    int i = 0;
    while (arr[i] != key)
        i++;
    return i == MAX - 1 ? 0 : i;
}
int main()
{
    int arr[MAX];
    int root;
    printf("Hay nhap vao %d gia tri:\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key = arr[MAX - 1];
    root = search(arr, key);
    if (root != MAX)
        printf("Vi tri cua phan tu can tim la: %d\n", root + 1);
    else
    {
        printf("Khong tim thay phan tu can tim\n");
    }
    return 0;
}