#include <stdio.h>
#define MaxSize 100
typedef int KeyType;        /*�ؼ�������*/
typedef char ElemType[10];  /*��������������*/
typedef struct {
    KeyType key;            /*�ؼ�����*/
    ElemType data;          /*����������*/
} LineList;                 /*���Ա�Ԫ������*/
void SelectSort(LineList R[], int n)
{
    int i, j, k;
    LineList tmp;

    for (i = 0; i < n - 1; i++) {
        k = i;

        for (j = i + 1; j < n; j++)
            if (R[j].key < R[k].key)
                k = j;      /*��kָ��ÿ�����������ε���СԪ��*/

        tmp = R[i];         /*��R[k]��R[i]����*/
        R[i] = R[k];
        R[k] = tmp;
    }
}
void main()
{
    LineList R[MaxSize];
    KeyType a[] = {75, 87, 68, 92, 88, 61, 77, 96, 80, 72};
    int n = 10, i;

    for (i = 0; i < n; i++)
        R[i].key = a[i];

    printf("����ǰ:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
    SelectSort(R, n);
    printf("�����:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
