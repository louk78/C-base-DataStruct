#include <stdio.h>
#define MaxSize 100
typedef int KeyType;        /*�ؼ�������*/
typedef char ElemType[10];  /*��������������*/
typedef struct {
    KeyType key;            /*�ؼ�����*/
    ElemType data;          /*����������*/
} LineList;                 /*���Ա�Ԫ������*/
void InsertSort(LineList R[], int n)
{
    int i, j;
    LineList tmp;

    for (i = 1; i < n; i++) {
        tmp = R[i];
        j = i - 1;

        while (j >= 0 && tmp.key < R[j].key) { /*Ԫ�غ���,�Ա��ڳ�һ��λ�ò���tmp*/
            R[j + 1] = R[j];
            j--;
        }

        R[j + 1] = tmp; /*��j+1λ�ô�����tmp*/
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
    InsertSort(R, n);
    printf("�����:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
