#include <stdio.h>
#define MAXVEX 100
#define INF 32767
void Floyed(int cost[][MAXVEX], int n)
{
    int A[MAXVEX][MAXVEX], path[MAXVEX][MAXVEX];
    int i, j, k, pre;

    for (i = 0; i < n; i++) /*�ó�ֵ*/
        for (j = 0; j < n; j++) {
            A[i][j] = cost[i][j];
            path[i][j] = -1;
        }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (A[i][j] > (A[i][k] + A[k][j])) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
    }

    printf("\n Floyed�㷨�������:\n");

    for (i = 0; i < n; i++) /*������·��*/
        for (j = 0; j < n; j++)
            if (i != j) {
                printf("   %d->%d:", i, j);

                if (A[i][j] == INF) {
                    if (i != j)
                        printf("������·��\n");
                } else {
                    printf("·������Ϊ:%3d ", A[i][j]);
                    printf("·��Ϊ%d ", i);
                    pre = path[i][j];

                    while (pre != -1) {
                        printf("%d ", pre);
                        pre = path[pre][j];
                    }

                    printf("%d\n", j);
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
    Floyed(cost, 6);
    printf("\n");
}
