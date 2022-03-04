#include "bin.h"
#include <ctype.h>
int main()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("word.txt", "r");
    fout = fopen("demtu.txt", "w+");
    BinaryTree *tree = NULL;
    char word[10];
    ElementType x;
    while (!feof(fin) && fscanf(fin, "%s", word))
    {
        for (int i = 0; i < strlen(word); i++)
        {
            word[i] = toupper(word[i]);
        }
        strcpy(x.key, word);
        x.dem = 1;
        tree = InsertData(tree, x);
    }
    PrintData(fout, tree);
}