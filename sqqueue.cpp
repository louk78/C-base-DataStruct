#include <stdio.h>
#define QueueSize 100
typedef char ElemType;
typedef struct {
    ElemType data[QueueSize];   /*�������Ԫ��*/
    int front, rear;            /*��ͷ�Ͷ�βָ��*/
} SqQueue;
void InitQueue(SqQueue &qu)     /*quΪ�����Ͳ���*/
{
    qu.rear = qu.front = 0;       /*ָ���ʼ��*/
}
int EnQueue(SqQueue &qu, ElemType x) /*�������,quΪ�����Ͳ���*/
{
    if ((qu.rear + 1) % QueueSize == qu.front) /*����*/
        return 0;

    qu.rear = (qu.rear + 1) % QueueSize; /*��βָ���1*/
    qu.data[qu.rear] = x;
    return 1;
}
int DeQueue(SqQueue &qu, ElemType &x)   /*��������,qu��xΪ�����Ͳ���*/
{
    if (qu.rear == qu.front)
        return 0;

    qu.front = (qu.front + 1) % QueueSize; /*��ͷָ���1*/
    x = qu.data[qu.front];
    return 1;
}
int GetHead(SqQueue qu, ElemType &x)    /*ȡ��ͷԪ������,xΪ�����Ͳ���*/
{
    if (qu.rear == qu.front)    /*�ӿ�*/
        return 0;

    x = qu.data[(qu.front + 1) % QueueSize];
    return 1;
}
int QueueEmpty(SqQueue qu)      /*�ж϶ӿ�����*/
{
    if (qu.rear == qu.front)    /*�ӿ�*/
        return 1;
    else
        return 0;
}
void main()
{
    SqQueue qu;
    ElemType e;
    InitQueue(qu);
    printf("��%s\n", (QueueEmpty(qu) == 1 ? "��" : "����"));
    printf("a����\n");
    EnQueue(qu, 'a');
    printf("b����\n");
    EnQueue(qu, 'b');
    printf("c����\n");
    EnQueue(qu, 'c');
    printf("d����\n");
    EnQueue(qu, 'd');
    printf("��%s\n", (QueueEmpty(qu) == 1 ? "��" : "����"));
    GetHead(qu, e);
    printf("��ͷԪ��:%c\n", e);
    printf("���Ӵ���:");

    while (!QueueEmpty(qu)) {
        DeQueue(qu, e);
        printf("%c ", e);
    }

    printf("\n");
}