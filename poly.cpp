#include <stdio.h>
#include <malloc.h>
typedef struct node {
    float coef;         /*����*/
    int expn;           /*ָ��*/
    struct node *next;  /*ָ����һ������ָ��*/
} PolyNode;
void InitList(PolyNode *&L)     /*��ʼ������ʽ������*/
{
    L = (PolyNode *)malloc(sizeof(PolyNode)); /*����ͷ���*/
    L->next = NULL;
}
int GetLength(PolyNode *L)      /*�����ʽ������ĳ���*/
{
    int i = 0;
    PolyNode *p = L->next;

    while (p != NULL) { /*ɨ�赥����L,��i�ۼ����ݽ�����*/
        i++;
        p = p->next;
    }

    return i;
}
PolyNode *GetElem(PolyNode *L, int i)   /*���ض���ʽ�������е�i������ָ��*/
{
    int j = 1;
    PolyNode *p = L->next;

    if (i < 1 || i > GetLength(L))
        return NULL;

    while (j < i) {         /*��next���ҵ�i�����*/
        p = p->next;
        j++;
    }

    return p;
}
PolyNode *Locate(PolyNode *L, float c, int e) /*�ڶ���ʽ�������а�ֵ����*/
{
    PolyNode *p = L->next;

    while (p != NULL && (p->coef != c || p->expn != e))
        p = p->next;

    return p;
}
int InsElem(PolyNode *&L, float c, int e, int i) /*�ڶ���ʽ�������в���һ�����*/
{
    int j = 1;
    PolyNode *p = L, *s;
    s = (PolyNode *)malloc(sizeof(PolyNode));
    s->coef = c;
    s->expn = e;
    s->next = NULL;

    if (i < 1 || i > GetLength(L) + 1)
        return 0;

    while (j < i) { /*���ҵ�i-1�����*p*/
        p = p->next;
        j++;
    }

    s->next = p->next;
    p->next = s;
    return 1;
}
int DelElem(PolyNode *L, int i)     /*�ڶ���ʽ��������ɾ��һ�����*/
{
    int j = 1;
    PolyNode *p = L, *q;

    if (i < 1 || i > GetLength(L))
        return 0;

    while (j < i) { /*�ڵ������в��ҵ�i-1�����*p*/
        p = p->next;
        j++;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
void DispList(PolyNode *L)      /*�������ʽ�������Ԫ��ֵ*/
{
    PolyNode *p = L->next;

    while (p != NULL) {
        printf("(%g,%d) ", p->coef, p->expn);
        p = p->next;
    }

    printf("\n");
}
void CreaPolyList(PolyNode *&L, float C[], int E[], int n)
{
    int i;
    InitList(L);

    for (i = 0; i < n; i++)
        InsElem(L, C[i], E[i], i + 1);
}
void SortPloy(PolyNode *&L) /*��L�Ķ���ʽ������expn���������*/
{
    PolyNode *p = L->next, *q, *pre;
    L->next = NULL;

    while (p != NULL) {
        if (L->next == NULL) {              /*�����1�����*/
            L->next = p;
            p = p->next;
            L->next->next = NULL;
        } else {                            /*����������*/
            pre = L;
            q = pre->next;

            while (q != NULL && p->expn > q->expn) { /*��q->expn�մ��ڻ����p->expn�Ľ��*q��ǰ�����*pre*/
                pre = q;
                q = q->next;
            }

            q = p->next;                    /*��*pre���֮�����*p*/
            p->next = pre->next;
            pre->next = p;
            p = q;
        }
    }
}
PolyNode *AddPoly(PolyNode *pa, PolyNode *pb)
{
    PolyNode *pc, *p1 = pa->next, *p2 = pb->next, *p, *tc, *s;
    pc = (PolyNode *)malloc(sizeof(PolyNode));  /*�½�ͷ���*/
    pc->next = NULL;                /*pcΪ�½��������ͷ���*/
    tc = pc;                        /*tcʼ��ָ���½�������������*/

    while (p1 != NULL && p2 != NULL) {
        if (p1->expn < p2->expn) {  /*��*p1��㸴�Ƶ�*s������pcβ*/
            s = (PolyNode *)malloc(sizeof(PolyNode));
            s->coef = p1->coef;
            s->expn = p1->expn;
            s->next = NULL;
            tc->next = s;
            tc = s;
            p1 = p1->next;
        } else if (p1->expn > p2->expn) { /*��*p2��㸴�Ƶ�*s������pcβ*/
            s = (PolyNode *)malloc(sizeof(PolyNode));
            s->coef = p2->coef;
            s->expn = p2->expn;
            s->next = NULL;
            tc->next = s;
            tc = s;
            p2 = p2->next;
        } else { /*p1->expn=p2->expn�����*/
            if (p1->coef + p2->coef != 0) { /*������Ӳ�Ϊ0ʱ�½����*s������pcβ*/
                s = (PolyNode *)malloc(sizeof(PolyNode));
                s->coef = p1->coef + p2->coef;
                s->expn = p1->expn;
                s->next = NULL;
                tc->next = s;
                tc = s;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    if (p1 != NULL) p = p1; /*����δɨ��������½�㸴�Ʋ����ӵ�pc������֮��*/
    else p = p2;

    while (p != NULL) {
        s = (PolyNode *)malloc(sizeof(PolyNode));
        s->coef = p->coef;
        s->expn = p->expn;
        s->next = NULL;
        tc->next = s;
        tc = s;
        p = p->next;
    }

    tc->next = NULL;    /*�½�������������next���ÿ�*/
    return pc;
}
void main()
{
    PolyNode *L1, *L2, *L3;
    float C1[] = {3, 7, 5, 9}, C2[] = { -9, 8, 22};
    int E1[] = {1, 0, 17, 8}, E2[] = {8, 1, 7};
    InitList(L1);
    InitList(L2);
    InitList(L3);
    CreaPolyList(L1, C1, E1, 4);
    CreaPolyList(L2, C2, E2, 3);
    printf("������ʽ�������\n");
    printf("     ԭ����ʽA:");
    DispList(L1);
    printf("     ԭ����ʽB:");
    DispList(L2);
    SortPloy(L1);
    SortPloy(L2);
    printf("�����Ķ���ʽA:");
    DispList(L1);
    printf("�����Ķ���ʽB:");
    DispList(L2);
    L3 = AddPoly(L1, L2);
    printf("����ʽ��ӽ��:");
    DispList(L3);
}
