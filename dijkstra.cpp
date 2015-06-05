#include <stdio.h>
#define MAXVEX 100
#define INF 32767
void Dijkstra(int cost[][MAXVEX], int n, int v)
{
    int dist[MAXVEX], path[MAXVEX];
    int s[MAXVEX];
    int mindis, i, j, u, pre;

    for (i = 0; i < n; i++) {
        dist[i] = cost[v][i];       /*�����ʼ��*/
        s[i] = 0;                   /*s[]�ÿ�*/

        if (cost[v][i] < INF)       /*·����ʼ��*/
            path[i] = v;
        else
            path[i] = -1;
    }

    s[v] = 1;
    path[v] = 0;             /*Դ����v����s��*/

    for (i = 0; i < n; i++) {       /*ѭ��ֱ�����ж�������·�������*/
        mindis = INF;
        u = -1;

        for (j = 0; j < n; j++)     /*ѡȡ����s���Ҿ�����С����Ķ���u*/
            if (s[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }

        if (u != -1) {                  /*�ҵ���С����Ķ���u*/
            s[u] = 1;                   /*����u����s��*/

            for (j = 0; j < n; j++)     /*�޸Ĳ���s�еĶ���ľ���*/
                if (s[j] == 0)
                    if (cost[u][j] < INF && dist[u] + cost[u][j] < dist[j]) {
                        dist[j] = dist[u] + cost[u][j];
                        path[j] = u;
                    }
        }
    }

    printf("\n Dijkstra�㷨�������:\n");

    for (i = 0; i < n; i++) {       /*������·������,·���������*/
        if (i != v) {
            printf("  %d->%d:", v, i);

            if (s[i] == 1) {
                printf("·������Ϊ%2d ", dist[i]);
                pre = i;
                printf("·������Ϊ");

                while (pre != v) {  /*һֱ��⵽��ʼ����*/
                    printf("%d,", pre);
                    pre = path[pre];
                }

                printf("%d\n", pre);
            } else
                printf("������·��\n");
        }
    }
}
void main()
{
    int cost[6][MAXVEX] = {     /*ͼ6.9�Ĵ��۾���*/
        {0, 50, 10, INF, INF, INF},
        {INF, 0, 15, 50, 10, INF},
        {20, INF, 0, 15, INF, INF},
        {INF, 20, INF, 0, 35, INF},
        {INF, INF, INF, 30, 0, INF},
        {INF, INF, INF, 3, INF, 0}
    };
    Dijkstra(cost, 6, 1);
    printf("\n");
}
