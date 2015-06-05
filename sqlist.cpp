#include <stdio.h>
#define MAXSIZE 100         /*˳��������*/
typedef char ElemType;
typedef struct {
    ElemType data[MAXSIZE]; /*���˳����Ԫ��*/
    int length;             /*˳����ʵ�ʳ���*/
} SqList;
void InitList(SqList &sq)   /*��ʼ�����Ա�*/
{
    sq.length = 0;
}
int GetLength(SqList sq)    /*�����Ա���*/
{
    return sq.length;
}
int GetElem(SqList sq, int i, ElemType &e)  /*�����Ա��е�i��Ԫ��*/
{
    if (i < 1 || i > sq.length) /*��Ч��iֵ*/
        return 0;
    else {
        e = sq.data[i - 1];
        return 1;
    }
}
int Locate(SqList sq, ElemType x)   /*��ֵ����*/
{
    int i = 0;

    while (sq.data[i] != x)          /*����ֵΪx�ĵ�1�����*/
        i++;

    if (i > sq.length)
        return (0);                  /*δ�ҵ�*/
    else
        return (i + 1);
}
int InsElem(SqList &sq, ElemType x, int i) /*����Ԫ��*/
{
    int j;

    if (i < 1 || i > sq.length + 1)     /*��Ч�Ĳ���i*/
        return 0;

    for (j = sq.length; j > i; j--)     /*��λ��Ϊi�Ľ�㼰֮��Ľ�����*/
        sq.data[j] = sq.data[j - 1];

    sq.data[i - 1] = x;             /*��λ��i������x*/
    sq.length++;                        /*���Ա�����1*/
    return 1;
}
int DelElem(SqList &sq, int i)  /*ɾ��Ԫ��*/
{
    int j;

    if (i < 1 || i > sq.length)     /*��Ч�Ĳ���i*/
        return 0;

    for (j = i; j < sq.length; j++) /*��λ��Ϊi�Ľ��֮��Ľ��ǰ��*/
        sq.data[j - 1] = sq.data[j];

    sq.length--;                    /*���Ա��ȼ�1*/       return 1;
}
void DispList(SqList sq)    /*������Ա�*/
{
    int i;

    for (i = 1; i <= sq.length; i++)
        printf("%c ", sq.data[i - 1]);

    printf("\n");
}

void main()
{
    int i;
    ElemType e;
    SqList sq;
    InitList(sq);       /*��ʼ��˳���sq*/
    InsElem(sq, 'a', 1); /*����Ԫ��*/
    InsElem(sq, 'c', 2);
    InsElem(sq, 'a', 3);
    InsElem(sq, 'e', 4);
    InsElem(sq, 'd', 5);
    InsElem(sq, 'b', 6);
    printf("���Ա�:");
    DispList(sq);
    printf("����:%d\n", GetLength(sq));
    i = 3;
    GetElem(sq, i, e);
    printf("��%d��Ԫ��:%c\n", i, e);
    e = 'a';
    printf("Ԫ��%c�ǵ�%d��Ԫ��\n", e, Locate(sq, e));
    i = 4;
    printf("ɾ����%d��Ԫ��\n", i);
    DelElem(sq, i);
    printf("���Ա�:");
    DispList(sq);
}
