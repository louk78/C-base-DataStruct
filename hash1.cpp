#include <stdio.h>
#define MaxSize 100     /*��ϣ����󳤶�*/
typedef int KeyType;
typedef struct {
    KeyType key;    /*�ؼ���ֵ*/
    int si;         /*̽�����*/
} HashTable;
void CreateHT(HashTable ht[], KeyType a[], int n, int m, int p) /*�����ϣ��*/
{
    int i, d, cnt;

    for (i = 0; i < m; i++) { /*�ó�ֵ*/
        ht[i].key = 0;
        ht[i].si = 0;
    }

    for (i = 0; i < n; i++) {
        cnt = 1;            /*�ۼ�̽�����*/
        d = a[i] % p;

        if (ht[d].key == 0) {
            ht[d].key = a[i];
            ht[d].si = cnt;
        } else {
            do {        /*�����ͻ*/
                d = (d + 1) % m;
                cnt++;
            } while (ht[d].key != 0);

            ht[d].key = a[i];
            ht[d].si = cnt;
        }
    }
}
void DispHT(HashTable ht[], int n, int m)   /*�����ϣ��*/
{
    int i;
    double avg;
    printf("i:  ");

    for (i = 0; i < m; i++)
        printf("%-3d", i);

    printf("\n");
    printf("key:");

    for (i = 0; i < m; i++)
        printf("%-3d", ht[i].key);

    printf("\n");
    printf("si: ");

    for (i = 0; i < m; i++)
        printf("%-3d", ht[i].si);

    printf("\n");
    avg = 0;

    for (i = 0; i < m; i++)
        avg += ht[i].si;

    avg = avg / n;
    printf("ƽ�����ҳ���:ASL(%d)=%g\n", n, avg);
}
void main()
{
    HashTable ht[MaxSize];
    KeyType a[] = {19, 1, 23, 14, 55, 20, 84, 27, 68, 11, 10, 77};
    int n = 12, m = 19, p = 13;
    CreateHT(ht, a, n, m, p);
    DispHT(ht, n, m);
}