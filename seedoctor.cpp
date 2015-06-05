#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct QNode {
    char data[10];
    struct QNode *next;
} QType;        /*���ӽ������*/
typedef struct {
    QType *front, *rear;
} LinkQueue;    /*��������*/
void SeeDoctor()
{
    int sel, flag = 1;
    LinkQueue *lq;
    QType *s;
    char name[10];
    lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    lq->front = (QType *)malloc(sizeof(QType));
    lq->front->next = NULL;
    lq->rear = lq->front;

    while (flag == 1) { /*δ�°�ʱѭ��ִ��*/
        printf("1:�Ŷ� 2:��ҽ�� 3:�鿴�Ŷ� 0:�°�  ��ѡ��:");
        scanf("%d", &sel);

        switch (sel) {
        case 0:
            if (lq->front != lq->rear)  /*�Ӳ���*/
                printf("  >>���ŶӵĻ��������ҽ\n");

            flag = 0;
            break;

        case 1:
            printf("  >>���뻼������:");
            scanf("%s", name);
            s = (QType *)malloc(sizeof(QType));
            strcpy(s->data, name);
            s->next = NULL;
            lq->rear->next = s;
            lq->rear = s;
            break;

        case 2:
            if (lq->front == lq->rear)  /*�ӿ�*/
                printf("  >>û���ŶӵĻ���\n");
            else {
                s = lq->front->next;

                if (lq->rear == s)
                    lq->rear = lq->front;

                printf("  >>����%s��ҽ��\n", s->data);
                lq->front->next = s->next;
                free(s);
            }

            break;

        case 3:
            if (lq->front == lq->rear)  /*�ӿ�*/
                printf("  >>û�����еĻ���\n");
            else {
                s = lq->front->next;
                printf("  >>�Ŷӻ���:");

                while (s != NULL) {
                    printf("%s ", s->data);
                    s = s->next;
                }

                printf("\n");
            }

            break;
        }
    }
}
void main()
{
    SeeDoctor();
}
