#include <stdio.h>
#define MaxSize 100  /*����ַ�����*/
typedef struct {
    char ch[MaxSize];   /*��Ŵ��ַ�*/
    int len;            /*��Ŵ���ʵ�ʳ���*/
} SqString;             /*˳������*/
void Assign(SqString &s, char t[])  /*����ֵ����*/
{
    int i = 0;

    while (t[i] != '\0') {
        s.ch[i] = t[i];
        i++;
    }

    s.len = i;
}
void StrCopy(SqString &s, SqString t)   /*����������*/
{
    int i;

    for (i = 0; i < t.len; i++)
        s.ch[i] = t.ch[i];

    s.len = t.len;
}
int StrLength(SqString s)   /*�󴮳�����*/
{
    return (s.len);
}
int StrEqual(SqString s, SqString t) /*�жϴ��������*/
{
    int i = 0;

    if (s.len != t.len)     /*������ͬʱ����0*/
        return (0);
    else {
        for (i = 0; i < s.len; i++)
            if (s.ch[i] != t.ch[i]) /*��һ����Ӧ�ַ���ͬʱ����0*/
                return (0);

        return (1);
    }
}
SqString Concat(SqString s, SqString t) /*����������*/
{
    SqString r;
    int i, j;

    for (i = 0; i < s.len; i++) /*��s���Ƶ�r*/
        r.ch[i] = s.ch[i];

    for (j = 0; j < t.len; j++) /*��t���Ƶ�r*/
        r.ch[s.len + j] = t.ch[j];

    r.len = i + j;
    return (r);                 /*����r*/
}
SqString SubStr(SqString s, int i, int j) /*���Ӵ�����*/
{
    SqString t;
    int k;

    if (i < 1 || i > s.len || j < 1 || i + j > s.len + 1)
        t.len = 0;          /*��������ʱ���ؿմ�*/
    else {
        for (k = i - 1; k < i + j; k++)
            t.ch[k - i + 1] = s.ch[k];

        t.len = j;
    }

    return (t);
}
int Index(SqString s, SqString t)   /*�����Ӵ�λ������*/
{
    int i = 0, j = 0, k;        /*i��j�ֱ�ɨ������s���Ӵ�t*/

    while (i < s.len && j < t.len) {
        if (s.ch[i] == t.ch[j]) { /*��Ӧ�ַ���ͬʱ,�����Ƚ���һ���ַ�*/
            i++;
            j++;
        } else {            /*����,���Ӵ�ָ��������¿�ʼ��һ��ƥ��*/
            i = i - j + 1;
            j = 0;
        }
    }

    if (j >= t.len)
        k = i - t.len + 1; /*�����һ���ַ���λ��*/
    else
        k = -1;     /*������ֵ-1*/

    return (k);
}
int InsStr(SqString &s, int i, SqString t)  /*�Ӵ���������*/
{
    int j;

    if (i > s.len + 1)
        return (0);                 /*λ�ò���ֵ����*/
    else {
        for (j = s.len; j >= i - 1; j--) /*��s.ch[i-1]-s.ch[s.len-1]*/
            s.ch[j + t.len] = s.ch[j]; /*����t.len��λ��*/

        for (j = 0; j < t.len; j++)
            s.ch[i + j - 1] = t.ch[j];

        s.len = s.len + t.len;      /*�޸�s������*/
        return (1);
    }
}
int DelStr(SqString &s, int i, int j) /*�Ӵ�ɾ������*/
{
    int k;

    if (i < 1 || i > s.len || j < 1 || i + j > s.len + 1)
        return (0);     /*λ�ò���ֵ����*/
    else {
        for (k = i + j - 1; k < s.len; k++) /*��s�ĵ�i+jλ��֮����ַ�ǰ��jλ*/
            s.ch[k - j] = s.ch[k];

        s.len = s.len - j;          /*�޸�s�ĳ���*/
        return (1);
    }
}
SqString RepStrAll(SqString s, SqString s1, SqString s2) /*�Ӵ��滻����*/
{
    int i;
    i = Index(s, s1);

    while (i >= 0) {
        DelStr(s, i, s1.len); /*ɾ��*/
        InsStr(s, i, s2);   /*����*/
        i = Index(s, s1);
    }

    return (s);
}
void DispStr(SqString s)    /*���������*/
{
    int i;

    for (i = 0; i < s.len; i++)
        printf("%c", s.ch[i]);

    printf("\n");
}
void main()
{
    SqString s1, s2, s3, s4, s5, s6, s7;
    Assign(s1, "abcd");
    printf("s1:");
    DispStr(s1);
    printf("s1�ĳ���:%d\n", StrLength(s1));
    printf("s1=>s2\n");
    StrCopy(s2, s1);
    printf("s2:");
    DispStr(s2);
    printf("s1��s2%s\n", (StrEqual(s1, s2) == 1 ? "��ͬ" : "����ͬ"));
    Assign(s3, "12345678");
    printf("s3:");
    DispStr(s3);
    printf("s1��s3����=>s4\n");
    s4 = Concat(s1, s3);
    printf("s4:");
    DispStr(s4);
    printf("s3[2..5]=>s5\n");
    s5 = SubStr(s3, 2, 4);
    printf("s5:");
    DispStr(s5);
    Assign(s6, "567");
    printf("s6:");
    DispStr(s6);
    printf("s6��s3��λ��:%d\n", Index(s3, s6));
    printf("��s3��ɾ��s3[3..6]�ַ�\n");
    DelStr(s3, 3, 4);
    printf("s3:");
    DispStr(s3);
    printf("��s4�н�s6�滻��s1=>s7\n");
    s7 = RepStrAll(s4, s6, s1);
    printf("s7:");
    DispStr(s7);
}
