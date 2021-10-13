// 6-4 许多小鱼游来了 (10 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
三、亲子游戏《小鱼游》 
师：“请家长们双手相搭，站成一排搭山洞，做成一个长鱼网。
幼儿扮小鱼从里面钻进去，当唱到最后一句“快快捉住”时，鱼网放下，捉住在鱼网下的小鱼。”
 玩法：邀请家长双手相搭，做成长鱼网，幼儿扮小鱼，在音乐声中自由地在鱼网下钻来钻去，
 当唱到“快快捉住”时，鱼网放下，捉住在鱼网下的小鱼，游戏继续进行。
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef int Status;
typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode* next;
}QNode, * QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q);
Status EnQueue(LinkQueue* Q, QElemType e);
Status DeQueue(LinkQueue* Q, QElemType* e);
int Capture(LinkQueue* Q, int Len, int N, int Cnt);

void _test()
{
    LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(q);
    for (int i = 1; i <= 5; i++)
    {
        EnQueue(q, i);
    }
    int now;
    for (int i = 1; i <= 5; i++)
    {
        DeQueue(q, &now);
        printf("%d poped!\n", now);
    }
    for (int i = 1; i <= 5; i++)
    {
        EnQueue(q, i);
    }
    for (int i = 1; i <= 5; i++)
    {
        DeQueue(q, &now);
        printf("%d poped!\n", now);
    }
}

int main()
{
    //_test();
    int n, m, i;
    scanf("%d %d", &n, &m);
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
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

Status InitQueue(LinkQueue* Q)
{
    QNode* head = (QNode*)malloc(sizeof(QNode));
    if (!head) { return 0; }
    head->next = NULL;
    Q->front = head;
    Q->rear = head;
    return 1;
}

Status EnQueue(LinkQueue* Q, QElemType e)
{
    QNode* nwnode = (QNode*)malloc(sizeof(QNode));
    if (!nwnode) { return 0; }
    nwnode->next = NULL;
    nwnode->data = e;
    Q->rear->next = nwnode;
    Q->rear = nwnode;
    return 1;
}

Status DeQueue(LinkQueue* Q, QElemType* e)
{
    if (Q->front->next == NULL) { return 0; }
    QNode* tmp = Q->front->next;
    *e = tmp->data;
    Q->front->next = tmp->next;
    if (Q->rear == tmp) { Q->rear = Q->front; }
    free(tmp);
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
