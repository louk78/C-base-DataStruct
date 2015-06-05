#include <stdio.h>
#define MaxSize 100
typedef int KeyType;        /*�ؼ�������*/
typedef char ElemType[10];  /*��������������*/
typedef struct {
    KeyType key;            /*�ؼ�����*/
    ElemType data;          /*����������*/
} LineList;                 /*���Ա�Ԫ������*/
void Sift(LineList R[], int low, int high)
{
    int i = low, j = 2 * i;     /*R[j]��R[i]������*/
    LineList tmp = R[i];

    while (j <= high) {
        if (j < high && R[j].key < R[j + 1].key) /*���Һ��ӽϴ�,��jָ���Һ���*/
            j++;                    /*j��Ϊ2i+1,ָ���Һ��ӽ��*/

        if (tmp.key < R[j].key) {
            R[i] = R[j];         /*��R[j]������˫�׽��λ����*/
            i = j;                /*�޸�i��jֵ,�Ա��������ɸѡ*/
            j = 2 * i;
        } else break;            /*ɸѡ����*/
    }

    R[i] = tmp;                   /*��ɸѡ����ֵ��������λ��*/
}
void HeapSort(LineList R[], int n)
{
    int i;
    LineList tmp;

    for (i = n / 2; i >= 1; i--) /*ѭ��������ʼ��*/
        Sift(R, i, n);

    for (i = n; i >= 2; i--) { /*����n-1��ѭ��,��ɶ�����*/
        tmp = R[1];         /*����һ��Ԫ��ͬ��ǰ������R[1]�Ի�*/
        R[1] = R[i];
        R[i] = tmp;
        Sift(R, 1, i - 1);  /*ɸѡR[1]���,�õ�i-1�����Ķ�*/
    }
}
void main()
{
    LineList R[MaxSize];
    KeyType a[] = {0, 75, 87, 68, 92, 88, 61, 77, 96, 80, 72}; /*��Ч���ݴ�a[1]��ʼ*/
    int n = 10, i;

    for (i = 0; i <= n; i++)
        R[i].key = a[i];

    printf("����ǰ:");

    for (i = 1; i <= n; i++)
        printf("%3d", R[i].key);

    printf("\n");
    HeapSort(R, n);
    printf("�����:");

    for (i = 1; i <= n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
