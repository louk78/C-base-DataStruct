#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char ElemType[10];
typedef struct tnode {
    KeyType key;
    ElemType data;
    struct tnode *lchild, *rchild;
} BSTNode;
BSTNode *BSTSearch(BSTNode *bt, KeyType k)
{
    BSTNode *p = bt;

    while (p != NULL && p->key != k) {
        if (k < p->key)
            p = p->lchild; /*������������*/
        else
            p = p->rchild; /*������������*/
    }

    return (p);
}
int BSTInsert(BSTNode *&bt, KeyType k)
{
    BSTNode *f, *p = bt;

    while (p != NULL) {
        if (p->key == k)
            return (0);

        f = p;                      /*fָ��*p����˫�׽��*/

        if (p->key > k)
            p = p->lchild;          /*���������в���*/
        else
            p = p->rchild;          /*���������в���*/
    }

    p = (BSTNode *)malloc(sizeof(BSTNode)); /*�����½��*/
    p->key = k;
    p->lchild = p->rchild = NULL;

    if (bt == NULL)                 /*ԭ��Ϊ��ʱ,*p��Ϊ��������*/
        bt = p;
    else if (k < f->key)
        f->lchild = p;              /*����*p��Ϊ*f������*/
    else
        f->rchild = p;              /*����*p��Ϊ*f���Һ���*/

    return (1);
}
void CreateBST(BSTNode *&bt, KeyType str[], int n)
{
    bt = NULL;                    /*��ʼʱbtΪ����*/
    int i = 0;

    while (i < n) {
        BSTInsert(bt, str[i]); /*���ؼ���str[i]�������������bt��*/
        i++;
    }
}
void DispBST(BSTNode *bt)
{
    if (bt != NULL) {
        printf("%d", bt->key);

        if (bt->lchild != NULL || bt->rchild != NULL) {
            printf("(");
            DispBST(bt->lchild);                /*�ݹ鴦��������*/

            if (bt->rchild != NULL) printf(",");

            DispBST(bt->rchild);                /*�ݹ鴦��������*/
            printf(")");
        }
    }
}
int BSTDelete(BSTNode *&bt, KeyType k)
{
    BSTNode *p = bt, *f, *r, *f1;
    f = NULL;                   /*pָ����ȽϵĽ��,fָ��*p��˫�׽��*/

    while (p != NULL && p->key != k) { /*����ֵ��Ϊx�Ľ��*/
        f = p;

        if (p->key > k)
            p = p->lchild;      /*���������в���*/
        else
            p = p->rchild;      /*���������в���*/
    }

    if (p == NULL)              /*δ�ҵ�key��Ϊk�Ľ��*/
        return (0);
    else if (p->lchild == NULL) { /**pΪ��ɾ���,������������*/
        if (f == NULL)          /**p�Ǹ����,�����Һ����滻��*/
            bt = p->rchild;
        else if (f->lchild == p) { /**p��˫�׽�������,�������Һ����滻��*/
            f->lchild = p->rchild;
            free(p);
        } else if (f->rchild == p) { /**p��˫�׽����Һ���,�������Һ����滻��*/
            f->rchild = p->rchild;
            free(p);
        }
    } else if (p->rchild == NULL) { /**pΪ��ɾ���,������������*/
        if (f == NULL)          /**p�Ǹ����,���������滻��*/
            bt = p->lchild;

        if (f->lchild == p) {   /**p��˫�׽�������,�����������滻��*/
            f->lchild = p->lchild;
            free(p);
        } else if (f->rchild == p) { /**p��˫�׽����Һ���,�����������滻��*/
            f->rchild = p->lchild;
            free(p);
        }
    } else {                    /**pΪ��ɾ���,��������������������*/
        f1 = p;
        r = p->lchild;     /*����*p���������е������½��*r*/

        while (r->rchild != NULL) { /**rһ�������������Ľ��,*f1��Ϊr��˫��*/
            f1 = r;
            r = r->rchild;
        }

        if (f1->lchild == r)    /**r��*f1������,ɾ��*r*/
            f1->lchild = r->rchild;
        else if (f1->rchild == r) /**r��*f1���Һ���,ɾ��*r*/
            f1->rchild = r->lchild;

        r->lchild = p->lchild;  /*�����������*r���*p*/
        r->rchild = p->rchild;

        if (f == NULL)          /**fΪ�����*/
            bt = r;             /*��ɾ����Ǹ����*/
        else if (f->lchild == p) /**p��*f������*/
            f->lchild = r;
        else                    /**p��*f���Һ���*/
            f->rchild = r;

        free(p);
    }

    return (1);
}
void main()
{
    BSTNode *bt = NULL, *p;
    KeyType a[] = {10, 6, 12, 8, 3, 20, 9, 25, 15}, k;
    int n = 9;
    CreateBST(bt, a, n);
    printf("BST:");
    DispBST(bt);
    printf("\n");
    k = 9;
    printf("���ҹؼ���Ϊ%d�Ľ��\n", k);
    p = BSTSearch(bt, k);

    if (p != NULL)
        printf("���ڹؼ���Ϊ%d���\n", k);
    else
        printf("�����ڹؼ���Ϊ%d���\n", k);

    k = 7;
    printf("����ؼ���Ϊ%d�Ľ��\n", k);
    BSTInsert(bt, k);
    printf("BST:");
    DispBST(bt);
    printf("\n");
    k = 10;
    printf("ɾ���ؼ���Ϊ%d�Ľ��\n", k);
    BSTDelete(bt, k);
    printf("BST:");
    DispBST(bt);
    printf("\n");
}
