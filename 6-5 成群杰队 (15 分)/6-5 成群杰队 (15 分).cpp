// 6-5 成群杰队 (15 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int N = 100;

int check(int Jie[], int n);
int main()
{
    int n;  int Jie[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)//注意，数组从1开始读入！
        scanf("%d", &Jie[i]);
    if (check(Jie, n))
        printf("Yes");
    else
        printf("No");
}
/* 请在这里填写答案 */

#define MAX_SIZE (int)1e5+10

int s[MAX_SIZE];
int top = 0;//栈顶元素位置的下一个下一个下一个重要的事情说三遍

int check(int Jie[], int n)
{
    int cur_element = 1;
    for (int i = 1; i <= n; i++)
    {
        if (top && s[top-1] == Jie[i])//谁是栈顶？！！！！！
        {
            top--;
            continue;
        }
        else
        {
            while (cur_element <= n && cur_element != Jie[i])
            {
                s[top++] = cur_element;//怎么模拟放入栈的过程
                cur_element++;
            }
            if (cur_element > n) { return 0; }
            else if (cur_element == Jie[i])
            {
                cur_element++;//为什么？好好想想，怎么模拟放入结果这个过程
                continue;
            }
        }
    }
    return 5201314;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
