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

int visited[MAXVEX];
void DFS(AdjList *g, int vi)    /*���ڽӱ�G�Ӷ���vi��ʼ����������ȱ���*/
{
    ArcNode *p;
    printf("%d ", vi);          /*����vi����*/
    visited[vi] = 1;            /*���ѷ��ʱ�ʶ*/
    p = g->adjlist[vi].firstarc; /*��vi�ĵ�һ���ڽӵ�*/

    while (p != NULL) {         /*��vi�������ڽӵ�*/
        if (visited[p->adjvex] == 0)
            DFS(g, p->adjvex);  /*��viδ���ʹ����ڽӵ���������������*/

        p = p->next;            /*��vi����һ���ڽӵ�*/
    }
}

void DFS1(AdjList *G, int vi)       /*�ǵݹ�������ȱ����㷨*/
{
    ArcNode *p;
    ArcNode *St[MAXVEX];
    int top = -1, v;
    printf("%d ", vi);                  /*����vi����*/
    visited[vi] = 1;                    /*���ѷ��ʱ�ʶ*/
    top++;                              /*����ʼ����vi��firstarcָ���ջ*/
    St[top] = G->adjlist[vi].firstarc;

    while (top > -1) {                  /*ջ����ѭ��*/
        p = St[top];
        top--;                /*��ջһ������Ϊ��ǰ����*/

        while (p != NULL) {             /*ѭ�����������ڶ���*/
            v = p->adjvex;              /*ȡ���ڶ���ı��*/

            if (visited[v] == 0) {      /*���ö���δ���ʹ�*/
                printf("%d ", v);       /*����v����*/
                visited[v] = 1;         /*�÷��ʱ�ʶ*/
                top++;                  /*���ö���ĵ�1�����ڶ����ջ*/
                St[top] = G->adjlist[v].firstarc;
                break;                  /*�˳���ǰ���������*/
            }

            p = p->next;                /*����һ�����ڶ���*/
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

    for (i = 0; i < g.n; i++) visited[i] = 0; /*�����ʶ�ó�ֵ*/

    printf("�Ӷ���0��������ȱ�������:\n");
    printf("  �ݹ��㷨:");
    DFS(G, 0);
    printf("\n");

    for (i = 0; i < g.n; i++) visited[i] = 0; /*�����ʶ�ó�ֵ*/

    printf("  �ǵݹ��㷨:");
    DFS1(G, 0);
    printf("\n");
}

