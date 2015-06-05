#include <stdio.h>
typedef char ElemType;
#define StackSize 100       /*˳��ջ�ĳ�ʼ����ռ�*/
typedef struct {
    ElemType data[StackSize];   /*����ջ��Ԫ��*/
    int top;                    /*ջָ��*/
} SqStack;
void InitStack(SqStack &st)     /*stΪ�����Ͳ���*/
{
    st.top = -1;
}
int Push(SqStack &st, ElemType x)   /*��ջ����,stΪ�����Ͳ���*/
{
    if (st.top == StackSize - 1) /*ջ��*/
        return 0;
    else {                      /*ջ����*/
        st.top++;
        st.data[st.top] = x;
        return 1;
    }
}
int Pop(SqStack &st, ElemType &x)       /*��ջ����,st��xΪ�����Ͳ���*/
{
    if (st.top == -1)   /*ջ��*/
        return 0;
    else {              /*ջ����*/
        x = st.data[st.top];
        st.top--;
        return 1;
    }
}
int GetTop(SqStack st, ElemType &x) /*ȡջ��Ԫ��,xΪ�����Ͳ���*/
{
    if (st.top == -1)   /*ջ��*/
        return 0;
    else {
        x = st.data[st.top];
        return 1;
    }
}
int StackEmpty(SqStack st)  /*�ж�ջ������*/
{
    if (st.top == -1) /*ջ��*/
        return 1;
    else            /*ջ����*/
        return 0;
}
void main()
{
    SqStack st;
    ElemType e;
    InitStack(st);
    printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
    printf("a��ջ\n");
    Push(st, 'a');
    printf("b��ջ\n");
    Push(st, 'b');
    printf("c��ջ\n");
    Push(st, 'c');
    printf("d��ջ\n");
    Push(st, 'd');
    printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
    GetTop(st, e);
    printf("ջ��Ԫ��:%c\n", e);
    printf("��ջ����:");

    while (!StackEmpty(st)) {
        Pop(st, e);
        printf("%c ", e);
    }

    printf("\n");
}