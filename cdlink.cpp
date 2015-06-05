#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct node {
    ElemType data;              /*������*/
    struct node *prior, *next; /*�ֱ�ָ��ǰ�����ͺ�̽���ָ��*/
} DLink;
void InitList(DLink *&L)
{
    L = (DLink *)malloc(sizeof(DLink));
    L->prior = L->next = L;
}
int GetLength(DLink *L) /*�������*/
{
    int i = 0;
    DLink *p = L->next;

    while (p != L) {
        i++;
        p = p->next;
    }

    return i;
}
int GetElem(DLink *L, int i, ElemType &e) /*�����Ա��е�i��Ԫ��*/
{
    int j = 1;
    DLink *p = L->next;

    if (i < 1 || i > GetLength(L))
        return (0);             /*i��������ȷ,����0*/

    while (j < i) {             /*�ӵ�1����㿪ʼ,���ҵ�i�����*/
        p = p->next;
        j++;
    }

    e = p->data;
    return (1);                 /*����1*/
}
int Locate(DLink *L, ElemType x) /*��ֵ����*/
{
    int i = 1;
    DLink *p = L->next;

    while (p != L && p->data != x) { /*�ӵ�1����㿪ʼ����data��Ϊx�Ľ��*/
        p = p->next;
        i++;
    }

    if (p == L)
        return (0);
    else
        return (i);
}
int InsElem(DLink *L, ElemType x, int i) /*��������*/
{
    int j = 1;
    DLink *p = L, *s;
    s = (DLink *)malloc(sizeof(DLink));
    s->data = x;
    s->prior = s->next = NULL;

    if (i < 1 || i > GetLength(L) + 1)
        return 0;

    while (j < i) {         /*�ҵ���i-1�����,��pָ����*/
        p = p->next;
        j++;
    }

    s->next = p->next;  /*s��next��ָ��p֮��Ľ��*/
    s->next->prior = s; /*p֮�����prior��ָ��s*/
    p->next = s;        /*p��next��ָ��s*/
    s->prior = p;       /*s��prior��ָ��p*/
    return 1;
}
int DelElem(DLink *L, int i) /*ɾ������*/
{
    int j = 1;
    DLink *p = L, *q;

    if (i < 1 || i > GetLength(L))
        return 0;

    while (j < i) {     /*�ҵ���i-1�����,��pָ����*/
        p = p->next;
        j++;
    }

    q = p->next;        /*qָ��p����һ�����,��Ҫɾ���Ľ��*/
    p->next = q->next;  /*p��nextָ��q����һ�����*/
    q->next->prior = p; /*q����һ������prior��ָ��p*/
    free(q);            /*�ͷ�q��ռ�õĿռ�*/
    return 1;
}

void DispList(DLink *L) /*������Ա�*/
{
    DLink *p = L->next;

    while (p != L) {
        printf("%c ", p->data);
        p = p->next;
    }

    printf("\n");
}
void main()
{
    int i;
    ElemType e;
    DLink *L;
    InitList(L);        /*��ʼ��˫����L*/
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
