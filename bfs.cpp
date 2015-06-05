#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXVEX 100

typedef char VertexType[3];     /*����VertexTypeΪchar��������*/
typedef struct vertex {
    int adjvex;                     /*������*/
    VertexType data;            /*�������Ϣ*/
} VType;                        /*��������*/
typedef struct graph {
    int n, e;                   /*nΪʵ�ʶ�����,eΪʵ�ʱ���*/
    VType vexs[MAXVEX];         /*���㼯��*/
    int edges[MAXVEX][MAXVEX];  /*�ߵļ���*/
} AdjMatix;                     /*ͼ���ڽӾ�������*/

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
void MatToList(AdjMatix g, AdjList *&G) /*��6.3�㷨:���ڽӾ���gת�����ڽӱ�G*/
{
    int i, j;
    ArcNode *p;
    G = (AdjList *)malloc(sizeof(AdjList));

    for (i = 0; i < g.n; i++) {         /*���ڽӱ�������ͷ����ָ�����ó�ֵ*/
        G->adjlist[i].firstarc = NULL;
        strcpy(G->adjlist[i].data, g.vexs[i].data);
    }

    for (i = 0; i < g.n; i++)           /*����ڽӾ�����ÿ��Ԫ��*/
        for (j = g.n - 1; j >= 0; j--)
            if (g.edges[i][j] != 0) {   /*�ڽӾ���ĵ�ǰԪ�ز�Ϊ0*/
                p = (ArcNode *)malloc(sizeof(ArcNode)); /*����һ�����*p*/
                p->value = g.edges[i][j];
                p->adjvex = j;
                p->next = G->adjlist[i].firstarc;     /*��*p���������*/
                G->adjlist[i].firstarc = p;
            }

    G->n = g.n;
    G->e = g.e;
}
void BFS(AdjList *G, int vi)    /*���ڽӱ�g�Ӷ���vi��ʼ���й�����ȱ���*/
{
    int i, v, visited[MAXVEX];
    int Qu[MAXVEX], front = 0, rear = 0; /*ѭ������*/
    ArcNode *p;

    for (i = 0; i < G->n; i++)          /*��visited�����ó�ֵ0*/
        visited[i] = 0;

    printf("%d ", vi);                  /*���ʳ�ʼ����*/
    visited[vi] = 1;                    /*���ѷ��ʱ�ʶ*/
    rear = (rear = 1) % MAXVEX;         /*ѭ���ƶ���βָ��*/
    Qu[rear] = vi;                      /*��ʼ�������*/

    while (front != rear) {             /*���в�Ϊ��ʱѭ��*/
        front = (front + 1) % MAXVEX;
        v = Qu[front];                  /*����v����*/
        p = G->adjlist[v].firstarc;     /*��v�ĵ�һ���ڽӵ�*/

        while (p != NULL) {             /*��v�������ڽӵ�*/
            if (visited[p->adjvex] == 0) { /*δ���ʹ������֮*/
                visited[p->adjvex] = 1; /*���ѷ��ʱ�ʶ*/
                printf("%d ", p->adjvex); /*���ʸõ㲢ʹ֮�����*/
                rear = (rear + 1) % MAXVEX; /*ѭ���ƶ���βָ��*/
                Qu[rear] = p->adjvex;   /*����p->adjvex����*/
            }

            p = p->next;                /*��v����һ���ڽӵ�*/
        }
    }
}
void main()
{
    int i, j;
    AdjMatix g;
    AdjList *G;
    int a[5][5] = {{0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 1}, {1, 0, 1, 0, 1}, {0, 0, 1, 1, 0}};
    char *vname[MAXVEX] = {"a", "b", "c", "d", "e"};
    g.n = 5;
    g.e = 12; /*����ͼ6.1(a)������ͼ,ÿ1���������Ϊ2�������*/

    for (i = 0; i < g.n; i++)
        strcpy(g.vexs[i].data, vname[i]);

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = a[i][j];

    MatToList(g, G);    /*�����ڽӱ�*/
    DispAdjList(G);     /*����ڽӱ�*/
    printf("�Ӷ���0�Ĺ�����ȱ�������:\n");
    printf("\t");
    BFS(G, 0);
    printf("\n");
}

