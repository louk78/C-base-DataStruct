#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct lsnode {
    ElemType data;          /*�洢�������*/
    struct lsnode *next;    /*ָ����*/
} LinkStack;
void InitStack(LinkStack *&ls)      /*lsΪ�����Ͳ���*/
{
    ls = NULL;
}
void Push(LinkStack *&ls, ElemType x)       /*��ջ����,lsΪ�����Ͳ���*/
{
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = ls;
    ls = p;
}
int Pop(LinkStack *&ls, ElemType &x)    /*��ջ����,lsΪ�����Ͳ���*/
{
    LinkStack *p;

    if (ls == NULL) /*ջ��,�����*/
        return 0;
    else {
        p = ls;
        x = p->data;
        ls = p->next;
        free(p);
        return 1;
    }
}
int GetTop(LinkStack *ls, ElemType &x)  /*ȡջ��Ԫ������*/
{
    if (ls == NULL) /*ջ��,�����*/
        return 0;
    else {
        x = ls->data;
        return 1;
    }
}
int StackEmpty(LinkStack *ls)   /*�ж�ջ������*/
{
    if (ls == NULL)
        return 1;
    else
        return 0;
}
void main()
{
    LinkStack *ls;
    ElemType e;
    InitStack(ls);
    printf("ջ%s\n", (StackEmpty(ls) == 1 ? "��" : "����"));
    printf("a��ջ\n");
    Push(ls, 'a');
    printf("b��ջ\n");
    Push(ls, 'b');
    printf("c��ջ\n");
    Push(ls, 'c');
    printf("d��ջ\n");
    Push(ls, 'd');
    printf("ջ%s\n", (StackEmpty(ls) == 1 ? "��" : "����"));
    GetTop(ls, e);
    printf("ջ��Ԫ��:%c\n", e);
    printf("��ջ����:");

    while (!StackEmpty(ls)) {
        Pop(ls, e);
        printf("%c ", e);
    }

    printf("\n");
}