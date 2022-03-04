#include "B1.h"
void main()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("datasx.txt", "w+");
    ElementType x;
    int n;
    BinaryTree *tree = NULL;
    puts("Hay nhap so sinh vien:");
    scanf("%d", &n);
    while (!feof(fin) && n--)
    {
        if (fgets(x.name, 40, fin))
        {
            fgets(x.phone, 15, fin);
            fgets(x.email, 40, fin);
            tree = InsertData(tree, x);
        }
    }
    putchar('\n');
    printf("So nut cua cay la: %d\n", sonut(tree));
    printf("So luong nut la: %d\n", sola(tree));
    printf("Do cao cua cay la: %d\n", docao(tree));
    // while (tree != NULL)
    // {
    //     printf("Nhap gia tri cua node ma ban muon xoa: ");
    //     scanf("%d", &x);
    //     tree = delete (tree, x);
    //     printf("So nut cua cay la: %d\n", sonut(tree));
    //     printf("So luong nut la: %d\n", sola(tree));
    //     printf("Do cao cua cay la: %d\n", docao(tree));
    // }
    // PrintData_duyet_anh_em(fout, *tree);
    PrintData(fout, tree);
    fclose(fin);
    fclose(fout);
}