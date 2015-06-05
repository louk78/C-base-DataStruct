#include <stdio.h>
#define MaxSize 100
typedef int KeyType;        /*�ؼ�������*/
typedef char ElemType[10];  /*��������������*/
typedef struct {
    KeyType key;            /*�ؼ�����*/
    ElemType data;          /*����������*/
} LineList;                 /*���Ա�Ԫ������*/
void ShellSort(LineList R[], int n)
{
    int i, j, gap;
    LineList tmp;
    gap = n / 2;                    /*�����ó�ֵ*/

    while (gap > 0) {
        for (i = gap; i < n; i++) { /*���������gapλ�õ�����Ԫ�����������*/
            tmp = R[i];
            j = i - gap;

            while (j >= 0 && tmp.key < R[j].key) { /*�����gapλ�õ�Ԫ�����������*/
                R[j + gap] = R[j];
                j = j - gap;                    /*�Ƶ������е�ǰһ��Ԫ��*/
            }

            R[j + gap] = tmp;
            j = j - gap;
        }

        gap = gap / 2;  /*��С����*/
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
    ShellSort(R, n);
    printf("�����:");

    for (i = 0; i < n; i++)
        printf("%3d", R[i].key);

    printf("\n");
}
