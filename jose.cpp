#include <stdio.h>
#define MaxSize 50
void jose(int n, int m)
{
    int mon[MaxSize];           /*���n�����ӵı��*/
    int i, d, count;

    for (i = 0; i < n; i++)     /*���ú��ӵı��*/
        mon[i] = i + 1;

    printf("����ǰ:");          /*�������ǰ�ı��*/

    for (i = 0; i < n; i++)
        printf("%d ", mon[i]);

    printf("\n");
    printf("���Ӻ�:");
    count = 0;                  /*��¼�˳�Ȧ��ĺ��Ӹ���*/
    i = -1;                     /*��0��λ�õĺ��ӿ�ʼ����*/

    while (count < n) {
        d = 0;

        while (d < m) {         /*�ۼ�m������*/
            i = (i + 1) % n;

            if (mon[i] != 0)
                d++;
        }

        printf("%d ", mon[i]);  /*���ӳ���*/
        mon[i] = 0;
        count++;                /*��������1*/
    }

    printf("\n");
}
void main()
{
    int m, n;
    printf("������Ӹ���n,m:");
    scanf("%d%d", &n, &m);
    jose(n, m);
}