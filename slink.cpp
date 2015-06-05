#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct node {
    ElemType data;      /*������*/
    struct node *next;  /*ָ����*/
} SLink;
void InitList(SLink *&L)    /*L��Ϊ�����Ͳ���*/
{
    L = (SLink *)malloc(sizeof(SLink)); /*����ͷ���*L*/
    L->next = NULL;
}
int GetLength(SLink *L) /*�����Ա�ĳ���*/
{
    int i = 0;
    SLink *p = L->next;

    while (p != NULL) {
        i++;
        p = p->next;
    }

    return i;
}
int GetElem(SLink *L, int i, ElemType &e) /*�����Ա��е�i��Ԫ��*/
{
    int j = 1;
    SLink *p = L->next;

    if (i < 1 || i > GetLength(L))
        return (0);             /*i��������ȷ,����0*/

    while (j < i) {             /*�ӵ�1����㿪ʼ��,���ҵ�i�����*/
        p = p->next;
        j++;
    }

    e = p->data;
    return (1);                 /*����1*/
}
int Locate(SLink *L, ElemType x) /*��ֵ����*/
{
    int i = 1;
    SLink *p = L->next;

    while (p != NULL && p->data != x) { /*�ӵ�1����㿪ʼ����data��Ϊx�Ľ��*/
        p = p->next;
        i++;
    }

    if (p == NULL)
        return (0);
    else
        return (i);
}
int InsElem(SLink *L, ElemType x, int i) /*������*/
{
    int j = 1;
    SLink *p = L, *s;
    s = (SLink *)malloc(sizeof(SLink)); /*����data��Ϊx�Ľ��*/
    s->data = x;
    s->next = NULL;

    if (i < 1 || i > GetLength(L) + 1)
        return 0;           /*i��������ȷ,����ʧ��,����0*/

    while (j < i) {     /*��ͷ��㿪ʼ��,���ҵ�i-1�����,��pָ����*/
        p = p->next;
        j++;
    }

    s->next = p->next;  /*��*s��next��ָ��*p����һ�����(����i�����)*/
    p->next = s;        /*��*p��next��ָ��*s,����*s��ɵ�i�����*/
    return 1;           /*��������ɹ�,����1*/
}
int DelElem(SLink *L, int i) /*ɾ�����*/
{
    int j = 1;
    SLink *p = L, *q;

    if (i < 1 || i > GetLength(L))
        return 0;       /*i��������ȷ,����ʧ��,����0*/

    while (j < i) {     /*��ͷ��㿪ʼ,���ҵ�i-1�����,��pָ����*/
        p = p->next;
        j++;
    }

    q = p->next;        /*��qָ���i�����*/
    p->next = q->next;  /*��*p��nextָ��*q֮����,����������ɾ����i�����*/
    free(q);                /*�ͷŵ�i�����ռ�õĿռ�*/
    return 1;           /*ɾ������ɹ�,����1*/
}
void DispList(SLink *L) /*���������*/
{
    SLink *p = L->next;

    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }

    printf("\n");
}
void main()
{
    int i;
    ElemType e;
    SLink *L;
    InitList(L);        /*��ʼ��������L*/
    InsElem(L, 'a', 1); /*����Ԫ��*/
    InsElem(L, 'c', 2);
    InsElem(L, 'a', 3);
    InsElem(L, 'e', 4);
    InsElem(L, 'd', 5);
    InsElem(L, 'b', 6);
    printf("���Ա�:");
    DispList(L);
    printf("����:%d\n", GetLength(L));
    i = 3;
    GetElem(L, i, e);
    printf("��%d��Ԫ��:%c\n", i, e);
    e = 'a';
    printf("Ԫ��%c�ǵ�%d��Ԫ��\n", e, Locate(L, e));
    i = 4;
    printf("ɾ����%d��Ԫ��\n", i);
    DelElem(L, i);
    printf("���Ա�:");
    DispList(L);
}
