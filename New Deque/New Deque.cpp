// New Deque.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node* PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord* Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push(ElementType X, Deque D);
ElementType Pop(Deque D);
int Inject(ElementType X, Deque D);
ElementType Eject(Deque D);

Operation GetOp();          /* details omitted */
void PrintDeque(Deque D); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch (GetOp()) {
        case push:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if (X == ERROR) printf("Deque is Empty!\n");
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if (X == ERROR) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Deque CreateDeque()
{
    Node* nwnode = (Node*)malloc(sizeof(Node));
    nwnode->Last = nwnode->Next = NULL;
    Deque deque = (Deque)malloc(sizeof(DequeRecord));
    deque->Front = deque->Rear = nwnode;
    return deque;
}

int Push(ElementType X, Deque D)
{
    Node* nwnode = (Node*)malloc(sizeof(Node));
    nwnode->Element = X;
    nwnode->Next = D->Front->Next;
    nwnode->Last = D->Front;
    Node* q = D->Front->Next;
    if (q) { q->Last = nwnode; }
    D->Front->Next = nwnode;

    if (D->Front == D->Rear) { D->Rear = nwnode; }
    return 1;
}

ElementType Pop(Deque D)
{
    if (D->Front == D->Rear) { return ERROR; }
    Node* tmp = D->Front->Next;
    ElementType res = tmp->Element;
    Node* q = tmp->Next;
    D->Front->Next = q;
    if (q) { q->Last = D->Front; }
    if (D->Rear == tmp) { D->Rear = D->Front; }
    free(tmp);
    return res;
}

int Inject(ElementType X, Deque D)
{
    Node* nwnode = (Node*)malloc(sizeof(Node));
    nwnode->Element = X;
    nwnode->Next = NULL;
    nwnode->Last = D->Rear;
    D->Rear->Next = nwnode;
    D->Rear = nwnode;
    return 1;
}

ElementType Eject(Deque D)
{
    if (D->Front == D->Rear) { return ERROR; }
    Node* tmp = D->Rear;
    ElementType res = tmp->Element;
    D->Rear = tmp->Last;
    D->Rear->Next = NULL;
    free(tmp);
    return res;
}

Operation GetOp()
{
    char s[8];
    scanf("%s", s);
    if (strcmp(s, "Push") == 0) { return push; }
    else if (strcmp(s, "Pop") == 0) { return pop; }
    else if (strcmp(s, "Inject") == 0) { return inject; }
    else if (strcmp(s, "Eject") == 0) { return eject; }
    else { return end; }
}

void PrintDeque(Deque D)
{
    if (D->Front == D->Rear) 
    { 
        printf("CNMD滚犊子！\n"); 
        return;
    }
    for (Node* it = D->Front->Next; it != NULL; it = it->Next)
    {
        printf("%d\t", it->Element);
    }
}

/* Your function will be put here */


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
