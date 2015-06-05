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
int BTHeight(BTNode *bt)    /*��������߶�*/
{
    int lchilddep, rchilddep;

    if (bt == NULL) return (0);         /*�����ĸ߶�Ϊ0*/
    else {
        lchilddep = BTHeight(bt->lchild); /*���������ĸ߶�Ϊlchilddep*/
        rchilddep = BTHeight(bt->rchild); /*���������ĸ߶�Ϊrchilddep*/
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}
int NodeCount(BTNode *bt)   /*�������bt�Ľ�����*/
{
    int num1, num2;

    if (bt == NULL) /*����������Ϊ0*/
        return 0;
    else {
        num1 = NodeCount(bt->lchild); /*����������Ľ����*/
        num2 = NodeCount(bt->rchild); /*����������Ľ����*/
        return (num1 + num2 + 1);
    }
}
int LeafCount(BTNode *bt)   /*�������bt��Ҷ�ӽ�����*/
{
    int num1, num2;

    if (bt == NULL) /*����Ҷ�ӽ�����Ϊ0*/
        return 0;
    else if (bt->lchild == NULL && bt->rchild == NULL)
        return 1;   /*��ΪҶ�ӽ�㷵��1*/
    else {
        num1 = LeafCount(bt->lchild); /*�����������Ҷ�ӽ����*/
        num2 = LeafCount(bt->rchild); /*�����������Ҷ�ӽ����*/
        return (num1 + num2);
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
void DispBTree1(BTNode *bt)  /*�԰����ʾ�����һ�ö�����*/
{
    BTNode *St[MaxSize], *p;
    int Level[MaxSize][2], top = -1, n, i, width = 4;
    char type;      /*ȡֵL��ʾΪ����,R��ʾΪ�ҽ��,B��ʾΪ�����*/

    if (bt != NULL) {
        top++;
        St[top] = bt;                   /*�������ջ*/
        Level[top][0] = width;
        Level[top][1] = 2;              /*2��ʾ�Ǹ�*/

        while (top > -1) {
            p = St[top];                /*��ջ��������ʾ�ý��ֵ*/
            n = Level[top][0];

            switch (Level[top][1]) {
            case 0:
                type = 'L';
                break;      /*����֮�����(L)*/

            case 1:
                type = 'R';
                break;      /*�ҽ��֮�����(R)*/

            case 2:
                type = 'B';
                break;      /*�����֮��ǰ���(B)*/
            }

            for (i = 1; i <= n; i++)    /*����nΪ��ʾ����,�ַ����Ҷ�����ʾ*/
                printf(" ");

            printf("%c(%c)", p->data, type);

            for (i = n + 1; i <= MaxWidth; i += 2)
                printf("��");

            printf("\n");
            top--;

            if (p->rchild != NULL) {
                /*���������������ջ*/
                top++;
                St[top] = p->rchild;
                Level[top][0] = n + width; /*������width,����width��������*/
                Level[top][1] = 1;      /*1��ʾ��������*/
            }

            if (p->lchild != NULL) {
                /*���������������ջ*/
                top++;
                St[top] = p->lchild;
                Level[top][0] = n + width; /*��ʾ������width*/
                Level[top][1] = 0;      /*0��ʾ��������*/
            }
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
    printf("bt�ĸ߶�:%d\n", BTHeight(bt));
    printf("bt�Ľ����:%d\n", NodeCount(bt));
    printf("bt��Ҷ�ӽ����:%d\n", LeafCount(bt));
    printf("bt�����ʾ:\n");
    DispBTree1(bt);
    printf("\n");
}