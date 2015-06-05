#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct tnode {
    ElemType data;
    struct tnode *lchild, *rchild;
} BTNode;
void CreateBTree(BTNode * &bt, char *str)   /*��str����������bt*/
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    bt = NULL;          /*�����Ķ�������ʼʱΪ��*/
    ch = str[j];

    while (ch != '\0') { /*strδɨ����ʱѭ��*/
        switch (ch) {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;    /*Ϊ���ӽ��*/

        case ')':
            top--;
            break;

        case ',':
            k = 2;
            break;                    /*Ϊ���ӽ���ҽ��*/

        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;

            if (bt == NULL)                 /**pΪ�������ĸ����*/
                bt = p;
            else {                          /*�ѽ��������������*/
                switch (k) {
                case 1:
                    St[top]->lchild = p;
                    break;

                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }

        j++;
        ch = str[j];
    }
}
void DispBTree(BTNode *bt)  /*�����ű�ʾ�����������*/
{
    if (bt != NULL) {
        printf("%c", bt->data);

        if (bt->lchild != NULL || bt->rchild != NULL) {
            printf("(");
            DispBTree(bt->lchild);      /*�ݹ鴦��������*/

            if (bt->rchild != NULL)
                printf(",");

            DispBTree(bt->rchild);      /*�ݹ鴦��������*/
            printf(")");
        }
    }
}
void PreOrder(BTNode *bt)
{
    if (bt != NULL) {
        printf("%c ", bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
void InOrder(BTNode *bt)
{
    if (bt != NULL) {
        InOrder(bt->lchild);
        printf("%c ", bt->data);
        InOrder(bt->rchild);
    }
}
void PostOrder(BTNode *bt)
{
    if (bt != NULL) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%c ", bt->data);
    }
}
void LevelOrder(BTNode *b)
{
    BTNode *p;
    BTNode *qu[MaxSize];            /*���廷�ζ���,��Ž��ָ��*/
    int front, rear;                /*�����ͷ�Ͷ�βָ��*/
    front = rear = -1;              /*�ö���Ϊ�ն���*/
    rear++;
    qu[rear] = b;                   /*�����ָ��������*/

    while (front != rear) {         /*���в�Ϊ��*/
        front = (front + 1) % MaxSize;
        p = qu[front];              /*��ͷ������*/
        printf("%c ", p->data);     /*���ʽ��*/

        if (p->lchild != NULL) {    /*������ʱ�������*/
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->lchild;
        }

        if (p->rchild != NULL) {    /*���Һ���ʱ�������*/
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->rchild;
        }
    }
}
void main()
{
    BTNode *bt;
    CreateBTree(bt, "A(B(D,E(G,H)),C(,F(I)))"); /*����ͼ5.10(a)��ʾ�Ķ�����*/
    printf("������bt:");
    DispBTree(bt);
    printf("\n");
    printf("�����������:");
    PreOrder(bt);
    printf("\n");
    printf("�����������:");
    InOrder(bt);
    printf("\n");
    printf("�����������:");
    PostOrder(bt);
    printf("\n");
    printf("��α�������:");
    LevelOrder(bt);
    printf("\n");
}