#include <stdio.h>
#define MAXVEX 100
typedef struct {
    int u;     /*�ߵ���ʼ����*/
    int v;     /*�ߵ���ֹ����*/
    int w;     /*�ߵ�Ȩֵ*/
} Edge;
void Kruskal(Edge E[], int n, int e)
{
    int i, j, m1, m2, sn1, sn2, k;
    int vset[MAXVEX];

    for (i = 0; i < n; i++) vset[i] = i; /*��ʼ����������*/

    k = 1;                          /*k��ʾ������С�������ĵڼ�����,��ֵΪ1*/
    j = 0;                          /*E�бߵ��±�,��ֵΪ0*/

    while (k < n) {                 /*���ɵı���С��nʱѭ��*/
        m1 = E[j].u;
        m2 = E[j].v;      /*ȡһ���ߵ�ͷβ����*/
        sn1 = vset[m1];
        sn2 = vset[m2]; /*�ֱ�õ��������������ļ��ϱ��*/

        if (sn1 != sn2) {           /*����������ͬ�ļ���,�ñ�����С�������ı�*/
            printf("  ��(%d,%d)ȨΪ:%d\n", m1, m2, E[j].w);
            k++;                    /*���ɱ�����1*/

            for (i = 0; i < n; i++) /*��������ͳһ���*/
                if (vset[i] == sn2) /*���ϱ��Ϊsn2�ĸ�Ϊsn1*/
                    vset[i] = sn1;
        }

        j++;                        /*ɨ����һ����*/
    }
}
void main()
{
    int n = 7, e = 10;
    Edge E[] = {
        {3, 5, 30}, {1, 4, 40}, {3, 6, 42},
        {2, 6, 45}, {0, 1, 50}, {3, 4, 50},
        {2, 3, 52}, {0, 2, 60}, {1, 3, 65},
        {4, 5, 70}
    };
    printf("��С������:\n");
    Kruskal(E, n, e);
}