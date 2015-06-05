#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;        /*�ؼ�������*/
typedef char ElemType[10];  /*��������������*/
typedef struct {
    KeyType key;            /*�ؼ�����*/
    ElemType data;          /*����������*/
} LineList;                 /*���Ա�Ԫ������*/
void Merge(LineList R[], int low, int mid, int high)
{
    LineList *R1;
    int i = low, j = mid + 1, k = 0; /*k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�*/
    R1 = (LineList *)malloc((high - low + 1) * sizeof(LineList)); /*��̬����ռ�*/

    while (i <= mid && j <= high) /*�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��*/
        if (R[i].key <= R[j].key) { /*����1���еļ�¼����R1��*/
            R1[k] = R[i];
            i++;
            k++;
        } else {                    /*����2���еļ�¼����R1��*/
            R1[k] = R[j];
            j++;
            k++;
        }

    while (i <= mid) {          /*����1�����²��ָ��Ƶ�R1*/
        R1[k] = R[i];
        i++;
        k++;
    }

    while (j <= high) {       /*����2�����²��ָ��Ƶ�R1*/
        R1[k] = R[j];
        j++;
        k++;
    }

    for (k = 0, i = low; i <= high; k++, i++) /*��R1���ƻ�R��*/
        R[i] = R1[k];
}
void MergePass(LineList R[], int length, int n)
{
    int i;

    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) /*�鲢length�����������ӱ�*/
        Merge(R, i, i + length - 1, i + 2 * length - 1);

    if (i + length - 1 < n)             /*���������ӱ�,���߳���С��length*/
        Merge(R, i, i + length - 1, n - 1); /*�鲢�������ӱ�*/
}
void MergeSort(LineList R[], int n) /*��·�鲢�㷨*/
{
    int length;

    for (length = 1; length < n; length = 2 * length)
        MergePass(R, length, n);
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
    MergeSort(R, n);
    printf("�����:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
