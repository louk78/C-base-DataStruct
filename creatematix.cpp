#include <stdio.h>
#define MAXVEX  100
typedef char VertexType[3];     /*����VertexTypeΪchar��������*/
typedef struct vertex {
    int adjvex;                 /*������*/
    VertexType data;            /*�������Ϣ*/
} VType;                        /*��������*/
typedef struct graph {
    int n, e;                   /*nΪʵ�ʶ�����,eΪʵ�ʱ���*/
    VType vexs[MAXVEX];         /*���㼯��*/
    int edges[MAXVEX][MAXVEX];  /*�ߵļ���*/
} AdjMatix;                     /*ͼ���ڽӾ�������*/
int CreateMatix(AdjMatix &g)
{
    int i, j, k, b, t;
    int w;
    printf("������(n)�ͱ���(e):");
    scanf("%d%d", &g.n, &g.e);

    for (i = 0; i < g.n; i++) {
        printf("   ���Ϊ%d�Ķ�����Ϣ:", i);
        scanf("%s", g.vexs[i].data);
        g.vexs[i].adjvex = i;   /*������Ϊi*/
    }

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = 0;

    for (k = 0; k < g.e; k++) {
        printf("   ���Ϊ%d�ı�=>", k);
        printf("  ���� �յ�� Ȩֵ:");
        scanf("%d%d%d", &b, &t, &w);

        if (b < g.n && t < g.n && w > 0)
            g.edges[b][t] = w;
        else {
            printf("�������!\n");
            return (0);
        }
    }

    return (1);
}
void DispMatix(AdjMatix g)
{
    int i, j;
    printf("\nͼ���ڽӾ���:\n");

    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            printf("%3d", g.edges[i][j]);

        printf("\n");
    }
}
void main()
{
    AdjMatix g;
    CreateMatix(g);
    DispMatix(g);
}