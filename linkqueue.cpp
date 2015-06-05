#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QType;                /*�����н�������*/
typedef struct qptr {
    QType *front, *rear;
} LinkQueue;            /*��������*/
void InitQueue(LinkQueue *&lq)          /*lqΪ�����Ͳ���*/
{
    lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    lq->rear = lq->front = NULL;            /*��ʼ���*/
}
void EnQueue(LinkQueue *&lq, ElemType x)    /*�������,lqΪ�����Ͳ���*/
{
    QType *s;
    s = (QType *)malloc(sizeof(QType));     /*�����½�㣬���뵽���ӵ�ĩβ*/
    s->data = x;
    s->next = NULL;

    if (lq->front == NULL && lq->rear == NULL)  /*�ն�*/
        lq->rear = lq->front = s;
    else {
        lq->rear->next = s;
        lq->rear = s;
    }
}
int DeQueue(LinkQueue *&lq, ElemType &x)    /*��������,lq��x��Ϊ�����Ͳ���*/
{
    QType *p;

    if (lq->front == NULL && lq->rear == NULL) /*�ն�*/
        return 0;

    p = lq->front;
    x = p->data;

    if (lq->rear == lq->front) /*��ԭ������ֻ��һ�����,ɾ������б��*/
        lq->rear = lq->front = NULL;
    else
        lq->front = lq->front->next;

    free(p);
    return 1;
}
int GetHead(LinkQueue *lq, ElemType &x)     /*ȡ��ͷԪ������,xΪ�����Ͳ���*/
{
    if (lq->front == NULL && lq->rear == NULL)  /*�ӿ�*/
        return 0;

    x = lq->front->data;
    return 1;
}
int QueueEmpty(LinkQueue *lq)   /*�ж϶ӿ�����*/
{
    if (lq->front == NULL && lq->rear == NULL)
        return 1;
    else
        return 0;
}

void main()
{
    LinkQueue *lq;
    ElemType e;
    InitQueue(lq);
    printf("��%s\n", (QueueEmpty(lq) == 1 ? "��" : "����"));
    printf("a����\n");
    EnQueue(lq, 'a');
    printf("b����\n");
    EnQueue(lq, 'b');
    printf("c����\n");
    EnQueue(lq, 'c');
    printf("d����\n");
    EnQueue(lq, 'd');
    printf("��%s\n", (QueueEmpty(lq) == 1 ? "��" : "����"));
    GetHead(lq, e);
    printf("��ͷԪ��:%c\n", e);
    printf("���Ӵ���:");

    while (!QueueEmpty(lq)) {
        DeQueue(lq, e);
        printf("%c ", e);
    }

    printf("\n");
}