// 妹子测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNING

#include <stdlib.h>
#include <stdio.h>

typedef int Status;
typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
int Capture (LinkQueue *Q, int Len, int N, int Cnt);

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    LinkQueue * queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    InitQueue(queue);
    for (i = 1; i <= n; i++)
        EnQueue(queue, i);
    for (i = 0; i < m; i++)
    {
        int len;
        scanf("%d", &len);
        printf("%d\n", Capture(queue, len, n, i));
    }

  return 0;

}

// typedef int QElemType;
// typedef struct QNode
// {
//     QElemType data;
//     struct QNode *next;
// }QNode, *QueuePtr;
// typedef struct
// {
//     QueuePtr front;
//     QueuePtr rear;
// }LinkQueue;
Status InitQueue(LinkQueue* Q) {//初始化一个空队列
    QueuePtr q;

    q = (QueuePtr)malloc(sizeof(struct QNode));     //create a node
    if (!q) {
        return 0;
    }
    q->next = NULL;
    Q->front = Q->rear = q;

    return 1;

}

Status EnQueue(LinkQueue* Q, QElemType e) {      //插入元素e为Q的新的队尾元素
    QueuePtr q;

    q = (QueuePtr)malloc(sizeof(struct QNode));     //create a node
    if (!q) {     //if full
        return 0;
    }
    if (Q->front == Q->rear) {    //if empty
        q->data = e;
        q->next = NULL;
        Q->front->next = q;
        Q->rear = q;

        return 1;
    }
    else {
        q->data = e;
        q->next = NULL;
        Q->rear->next = q;
        Q->rear = q;

        return 1;
    }
}

Status DeQueue(LinkQueue* Q, QElemType* e) {     //若队列不空，则删除Q的队头元素并用指针传回e
    QueuePtr q;

    if (Q->front == Q->rear) {    //if empty
        return 0;
    }
    *e = Q->front->next->data;
    if (Q->front->next == Q->rear) {    //if only one left
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
    else {
        q = Q->front->next;
        Q->front->next = q->next;
        free(q);
    }

    return 1;

}

int Capture(LinkQueue* Q, int Len, int N, int Cnt) {    //Len为节拍数，N为小鱼总数，cnt为抓鱼次数（从零开始）
    int r = Len  % (N - Cnt), e;

    if (r == 0) {     //不用循环的节拍
        r = N - Cnt;
    }
    for (int i  = 1; i  <= r; i++) {
        DeQueue(Q, &e);
        if (i  != r) {
            EnQueue(Q, e);
        }
        else {
            return e;
        }

    }
}



/* 请在这里填写答案 */
/* 请在这里填写答案 */

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
