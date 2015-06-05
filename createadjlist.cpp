#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100
typedef char VertexType[3];
typedef struct edgenode {
    int adjvex;                 /*�ڽӵ����*/
    int value;                  /*�ߵ�Ȩֵ*/
    struct edgenode *next;      /*��һ���ߵĶ���*/
} ArcNode;                      /*ÿ�����㽨���ĵ������н�������*/
typedef struct vexnode {
    VertexType data;            /*�����Ϣ*/
    ArcNode *firstarc;          /*ָ���һ���߽��*/
} VHeadNode;                    /*�������ͷ�������*/
typedef struct {
    int n, e;                   /*nΪʵ�ʶ�����,eΪʵ�ʱ���*/
    VHeadNode adjlist[MAXVEX];  /*������ͷ�������*/
} AdjList;                      /*ͼ���ڽӱ�����*/
int CreateAdjList(AdjList *&G)  /*��������ͼ���ڽӱ�*/
{
    int i, b, t, w;
    ArcNode *p;
    G = (AdjList *)malloc(sizeof(AdjList));
    printf("������(n),����(e):");
    scanf("%d%d", &G->n, &G->e);

    for (i = 0; i < G->n; i++) {
        printf("   ���Ϊ%d�Ķ�����Ϣ:", i);
        scanf("%s", G->adjlist[i].data);
        G->adjlist[i].firstarc = NULL;
    }

    for (i = 0; i < G->e; i++) {
        printf("   ���Ϊ��=>", i);
        printf(" ���� �յ�� Ȩֵ:");
        scanf("%d%d%d", &b, &t, &w);

        if (b < G->n && t < G->n && w > 0) {
            p = (ArcNode *)malloc(sizeof(ArcNode)); /*����*p���*/
            p->value = w;
            p->adjvex = t;
            p->next = G->adjlist[b].firstarc; /**p���뵽adjlist[b]�ĵ�����֮��*/
            G->adjlist[b].firstarc = p;
        } else {
            printf("�������!\n");
            return (0);
        }
    }

    return (1);
}
void DispAdjList(AdjList *G)
{
    int i;
    ArcNode *p;
    printf("ͼ���ڽӱ��ʾ����:\n");

    for (i = 0; i < G->n; i++) {
        printf("  [%d,%3s]=>", i, G->adjlist[i].data);
        p = G->adjlist[i].firstarc;

        while (p != NULL) {
            printf("(%d,%d)->", p->adjvex, p->value);
            p = p->next;
        }

        printf("��\n");
    }
}
void main()
{
    AdjList *G;
    CreateAdjList(G);
    DispAdjList(G);
}
