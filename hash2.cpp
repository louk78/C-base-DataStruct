#include <stdio.h>
#include <malloc.h>
#define MaxSize 100     /*��ϣ����󳤶�*/
typedef int KeyType;
typedef struct node {
    KeyType key;    /*�ؼ���ֵ*/
    int si;         /*̽�����*/
    struct node *next;
} Node;     /*���ݽ������*/
typedef struct {
    Node *link;
} HNode;    /*ͷ�������*/
void CreateHT(HNode *ht[], KeyType a[], int n, int p) /*�����ϣ��*/
{
    int i, d, cnt;
    Node *s, *q;

    for (i = 0; i < p; i++) { /*����ͷ����link���ÿ�*/
        ht[i] = (HNode *)malloc(sizeof(HNode));
        ht[i]->link = NULL;
    }

    for (i = 0; i < n; i++) {
        cnt = 1;
        s = (Node *)malloc(sizeof(Node)); /*����һ�����ݽ��*/
        s->key = a[i];
        s->next = NULL;
        d = a[i] % p;                   /*�����ϣ��ַ*/

        if (ht[d]->link == NULL) {
            ht[d]->link = s;
            s->si = cnt;
        } else {
            q = ht[d]->link;

            while (q->next != NULL) {
                q = q->next;
                cnt++;
            }

            cnt++;
            s->si = cnt;
            q->next = s;
        }
    }
}
void DispHT(HNode *ht[], int n, int p)  /*�����ϣ��*/
{
    int i, sum = 0;
    Node *q;
    printf("��ϣ��:\n");

    for (i = 0; i < p; i++) {
        q = ht[i]->link;
        printf("%d:link->", i);

        while (q != NULL) {
            sum += q->si;
            printf("[%d,%d]->", q->key, q->si);
            q = q->next;
        }

        printf("��\n");
    }

    printf("\nƽ�����ҳ���:ASL=%g\n", 1.0 * sum / n);
}

void main()
{
    HNode *ht[MaxSize];
    KeyType a[] = {87, 25, 310, 8, 27, 132, 68, 95, 187, 123, 70, 63, 47};
    int n = 13, p = 13;
    CreateHT(ht, a, n, p);
    DispHT(ht, n, p);
}