#include <stdio.h>
#include <malloc.h>
typedef struct node {
    char data;          /*����ַ�*/
    struct node *next;  /*ָ����*/
} LinkString;
void Assign(LinkString *&s, char t[])
{
    int i = 0;
    LinkString *q, *tc;
    s = (LinkString *)malloc(sizeof(LinkString)); /*����ͷ���*/
    s->next = NULL;
    tc = s;                 /*tcָ��s����β���*/

    while (t[i] != '\0') {
        q = (LinkString *)malloc(sizeof(LinkString));
        q->data = t[i];
        tc->next = q;
        tc = q;
        i++;
    }

    tc->next = NULL;    /*�ն˽���next��NULL*/
}
void StrCopy(LinkString *&s, LinkString *t) /*t=>s*/
{
    LinkString *p = t->next, *q, *tc;
    s = (LinkString *)malloc(sizeof(LinkString)); /*����ͷ���*/
    s->next = NULL;
    tc = s;             /*tcָ��s����β���*/

    while (p != NULL) { /*����t�����н��*/
        q = (LinkString *)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }

    tc->next = NULL;    /*�ն˽���next��NULL*/
}
int StrLength(LinkString *s)
{
    int n = 0;
    LinkString *p = s->next;

    while (p != NULL) { /*ɨ�贮s�����н��*/
        n++;
        p = p->next;
    }

    return (n);
}
int StrEqual(LinkString *s, LinkString *t)
{
    LinkString *p = s->next, *q = t->next;

    while (p != NULL && q != NULL) { /*�Ƚ������ĵ�ǰ���*/
        if (p->data != q->data) /*data�򲻵�ʱ����0*/
            return (0);

        p = p->next;
        q = q->next;
    }

    if (p != NULL || q != NULL) /*�������Ȳ���ʱ����0*/
        return (0);

    return (1);
}
LinkString *Concat(LinkString *s, LinkString *t)
{
    LinkString *p = s->next, *q, *tc, *str;
    str = (LinkString *)malloc(sizeof(LinkString)); /*����ͷ���*/
    str->next = NULL;
    tc = str;           /*tc����ָ���������β���*/

    while (p != NULL) { /*��s�����Ƹ�str*/
        q = (LinkString *)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }

    p = t->next;

    while (p != NULL) { /*��t�����Ƹ�str*/
        q = (LinkString *)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }

    tc->next = NULL;
    return (str);
}
LinkString *SubStr(LinkString *s, int i, int j)
{
    int k = 1;
    LinkString *p = s->next, *q, *tc, *str;
    str = (LinkString *)malloc(sizeof(LinkString)); /*����ͷ���*/
    str->next = NULL;
    tc = str;                       /*tc����ָ���������β���*/

    while (k < i && p != NULL) {
        p = p->next;
        k++;
    }

    if (p != NULL) {
        k = 1;

        while (k <= j && p != NULL) { /*����j�����*/
            q = (LinkString *)malloc(sizeof(LinkString));
            q->data = p->data;
            tc->next = q;
            tc = q;
            p = p->next;
            k++;
        }

        tc->next = NULL;
    }

    return (str);
}
int Index(LinkString *s, LinkString *t)
{
    LinkString *p = s->next, *p1, *q, *q1;
    int i = 0;

    while (p != NULL) {     /*ѭ��ɨ��s��ÿ�����*/
        q = t->next;        /*�Ӵ����Ǵӵ�һ���ַ���ʼ�Ƚ�*/

        if (p->data == q->data) { /*�ж�������ǰ�ַ����*/
            /*�����ַ���ͬ,���ж�s����ַ��Ƿ���t��������ͬ*/
            p1 = p->next;
            q1 = q->next;

            while (p1 != NULL && q1 != NULL && p1->data == q1->data) {
                p1 = p1->next;
                q1 = q1->next;
            }

            if (q1 == NULL) /*������ͬ,�򷵻���ͬ���Ӵ�����ʼλ��*/
                return (i);
        }

        p = p->next;
        i++;
    }

    return (-1);    /*�������Ӵ�,����-1*/
}
int InsStr(LinkString *&s, int i, LinkString *t)
{
    int k;
    LinkString *q = s->next, *p, *str;
    StrCopy(str, t);    /*��t���Ƶ�str*/
    p = str;
    str = str->next;
    free(p);            /*ɾ��str��ͷ���*/

    for (k = 1; k < i; k++) { /*��s���ҵ���i-1�����,��pָ����,qָ����һ�����*/
        if (q == NULL)  /*λ�ò���i����*/
            return (0);

        p = q;
        q = q->next;
    }

    p->next = str;      /*��str�������ӵ�*p֮��*/

    while (str->next != NULL) /*��strָ��β���*/
        str = str->next;

    str->next = q;      /*��*q���ӵ�*str֮��*/
    return (1);
}
int DelStr(LinkString *&s, int i, int j)
{
    int k;
    LinkString *q = s->next, *p, *t;

    for (k = 1; k < i; k++) { /*��s���ҵ���i-1�����,��pָ����,qָ����һ�����*/
        if (q == NULL)      /*λ�ò���i����*/
            return (0);

        p = q;
        q = q->next;
    }

    for (k = 1; k <= j; k++) { /*ɾ��*p֮���j�����,����qָ����һ�����*/
        if (q == NULL)  /*���Ȳ���j����*/
            return (0);

        t = q;
        q = q->next;
        free(t);
    }

    p->next = q;
    return (1);
}
LinkString *RepStrAll(LinkString *s, LinkString *s1, LinkString *s2)
{
    int i;
    i = Index(s, s1);

    while (i >= 0) {
        DelStr(s, i + 1, StrLength(s1)); /*ɾ����s1*/
        InsStr(s, i + 1, s2);           /*���봮s2*/
        i = Index(s, s1);
    }

    return (s);
}
void DispStr(LinkString *s)
{
    LinkString *p = s->next;

    while (p != NULL) {
        printf("%c", p->data);
        p = p->next;
    }

    printf("\n");
}
void main()
{
    LinkString *s1, *s2, *s3, *s4, *s5, *s6, *s7;
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
