// 6-6 在杰难逃 (15 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 30

int n;
char maze[N][N];

typedef struct Position
{
    int x;
    int y;
}Pos, QElemType;

typedef int Status;

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

struct Node {
    Pos pos;
    int step;
};

void getline(char* a)
{
    char c;
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        a[i] = c;
    }
}

int EscapePath(Pos source, Pos destination);

int main()
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        getline(maze[i]);
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }*/
    Pos source, destination;
    scanf("%d %d", &source.x, &source.y);
    scanf("%d %d", &destination.x, &destination.y);

    printf("%d\n", EscapePath(source, destination));//搜索只会BFS，数论只会GCD。。。

    return 0;
}

Node que[N * N+10];
int head = 0, tail = 0;

bool book[N][N];

int EscapePath(Pos source, Pos destination)
{
    que[0].pos = source;
    que[0].step = 0;//他应该是从0开始，你想想如果起点等于终点那么步数应该是0，从这个角度讲应该这样
    book[source.x][source.y] = true;
    tail++;
    while (head != tail)
    {
        int curstep = que[head].step;
        Pos curpos = que[head].pos;
        if (curpos.x == destination.x && curpos.y == destination.y)
        {
            return curstep;
        }
        int nextx, nexty;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0) { nextx = curpos.x + 1; nexty = curpos.y; }
            if (i == 1) { nextx = curpos.x; nexty = curpos.y + 1; }
            if (i == 2) { nextx = curpos.x - 1; nexty = curpos.y; }
            if (i == 3) { nextx = curpos.x; nexty = curpos.y - 1; }

            if (!book[nextx][nexty] && maze[nextx][nexty] != '#')
            {
                book[nextx][nexty] = true;//又忘了！！！！
                Pos nwpoint = { nextx,nexty };
                Node nwnode = { nwpoint,curstep + 1 };
                que[tail] = nwnode;
                tail++;
            }
        }
        head++;
    }
    return -1;
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
