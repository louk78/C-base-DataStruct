#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXE 20         /*���Ա������Ԫ�ظ���*/
#define MAXR 10         /*���������ȡֵ*/
#define MAXD 8          /*�ؼ���λ�������ȡֵ*/
typedef struct node {
    char data[MAXD];    /*��¼�Ĺؼ��ֶ�����ַ���*/
    struct node *next;
} RecType;
void RadixSort(RecType *&p, int r, int d)
/*pΪ��������������ָ��,rΪ����,dΪ�ؼ���λ��*/
{
    RecType *head[MAXR], *tail[MAXR], *t; /*��������ӵ���βָ��*/
    int i, j, k;

    for (i = d - 1; i >= 0; i--) {      /*�ӵ�λ����λ��d������*/
        for (j = 0; j < r; j++)         /*��ʼ���������ס�βָ��*/
            head[j] = tail[j] = NULL;

        while (p != NULL) {             /*����ԭ������ÿ�����ѭ��*/
            k = p->data[i] - '0';       /*�ҵ�k������*/

            if (head[k] == NULL) {      /*���з���,������β�巨����������*/
                head[k] = p;
                tail[k] = p;
            } else {
                tail[k]->next = p;
                tail[k] = p;
            }

            p = p->next;                /*ȡ��һ���������Ԫ��*/
        }

        p = NULL;

        for (j = 0; j < r; j++)         /*����ÿһ������ѭ��*/
            if (head[j] != NULL) {      /*�����ռ�*/
                if (p == NULL) {
                    p = head[j];
                    t = tail[j];
                } else {
                    t->next = head[j];
                    t = tail[j];
                }
            }

        t->next = NULL;                 /*���һ������next����NULL*/
    }
}
void main()
{
    RecType *h = NULL, *p, *t;
    char *A[] = {"75", "87", "68", "92", "88", "61", "77", "96", "80", "72"};
    int i, n = 10;

    for (i = 0; i < n; i++) { /*���첻��ͷ���ĵ�����h*/
        p = (RecType *)malloc(sizeof(RecType));
        strcpy(p->data, A[i]);

        if (h == NULL) {
            h = p;
            t = h;
        } else {
            t->next = p;
            t = p;
        }
    }

    t->next = NULL;
    printf("����ǰ:");

    for (i = 0; i < n; i++)
        printf("%3s", A[i]);

    printf("\n");
    RadixSort(h, 10, 2);
    printf("�����:");
    p = h;

    while (p != NULL) {
        printf("%3s", p->data);
        p = p->next;
    }

    printf("\n");
}
