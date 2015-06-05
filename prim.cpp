#include <stdio.h>
#define MAXVEX 100
#define INF 32767       /*INF��ʾ��*/
void Prim(int cost[][MAXVEX], int n, int v)
/*�����С��������ÿ����*/
{
    int lowcost[MAXVEX], min;
    int closest[MAXVEX], i, j, k;

    for (i = 0; i < n; i++) {   /*��lowcost[]��closest[]�ó�ֵ*/
        lowcost[i] = cost[v][i];
        closest[i] = v;
    }

    for (i = 1; i < n; i++) {   /*�ҳ�n-1������*/
        min = INF;

        for (j = 0; j < n; j++) /*��(V-U)���ҳ���U����Ķ���k*/
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }

        printf("  ��(%d,%d)ȨΪ:%d\n", closest[k], k, min);
        lowcost[k] = 0;         /*���k�Ѿ�����U*/

        for (j = 0; j < n; j++) /*�޸�����lowcost��closest*/
            if (cost[k][j] != 0 && cost[k][j] < lowcost[j]) {
                lowcost[j] = cost[k][j];
                closest[j] = k;
            }
    }
}
void main()
{
    int n = 7;
    int cost[7][MAXVEX] = {
        {0, 50, 60, INF, INF, INF, INF},
        {50, 0, INF, 65, 40, INF, INF},
        {60, INF, 0, 52, INF, INF, 45},
        {INF, 65, 52, 0, 50, 30, 42},
        {INF, 40, INF, 50, 0, 70, INF},
        {INF, INF, INF, 30, 70, 0, INF},
        {INF, INF, 45, 42, INF, INF, 0}
    };
    printf("��С������:\n");
    Prim(cost, n, 0);
}