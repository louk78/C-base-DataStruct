#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType[10];
typedef struct {
    KeyType key;    /*��Źؼ���,KeyTypeΪ�ؼ�������*/
    ElemType data;  /*��������, ElemTypeΪ�������ݵ�����*/
} LineList;
int SeqSearch(LineList R[], int n, KeyType k)
{
    int i = 0;

    while (i < n && R[i].key != k) i++;

    if (i >= n)
        return (-1);
    else
        return (i);
}
void main()
{
    KeyType a[] = {3, 9, 1, 5, 8, 10, 6, 7, 2, 4}, k = 6;
    LineList R[MaxSize];
    int n = 10, i;

    for (i = 0; i < n; i++)
        R[i].key = a[i];

    i = SeqSearch(R, n, k);

    if (i >= 0)
        printf("R[%d].key=%d\n", i, k);
    else
        printf("%d����a��\n", k);
}

