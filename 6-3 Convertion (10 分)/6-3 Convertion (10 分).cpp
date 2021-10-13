// 6-3 Convertion (10 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define STACK_INIT_SIZE 100
typedef int Stack_ElemType;
typedef struct Stack {
    Stack_ElemType* base;
    Stack_ElemType* top;
    int stack_size;//代表元素个数
    int stack_length;//代表可用空间大小
} my_stack;//如果你不清楚某个实现，不要害怕去询问开发这部分的人！

bool InitStack(my_stack& S);
bool StackEmpty(my_stack S);
bool GetTop(my_stack S, Stack_ElemType& e);
bool Push(my_stack& S, Stack_ElemType e);
bool Pop(my_stack& S);
void Convertion(my_stack& S, long long num);
void PrintStack(my_stack S);
void StackClear(my_stack& S);

int main() {
    my_stack S;
    InitStack(S);
    long long num = 0;
    int que = 0;
    scanf("%d", &que);
    while (que--) {
        StackClear(S);
        scanf("%lld", &num);
        Convertion(S, num);
        PrintStack(S);
    }
    return 0;
}

bool InitStack(my_stack& S)
{
    try { S.base = new int[STACK_INIT_SIZE]; }
    catch (const std::bad_alloc& e) { return false; }
    S.top = S.base;
    S.stack_length = STACK_INIT_SIZE;
    S.stack_size = 0;
    return true;
}

bool StackEmpty(my_stack S)
{
    return S.top == S.base;
}

bool GetTop(my_stack S, Stack_ElemType& e)
{
    if (StackEmpty(S)) { return false; }
    e = *(S.top - 1);
    return true;
}

bool Push(my_stack& S, Stack_ElemType e)
{
    if (S.stack_size == S.stack_length)
    {
        int* nwbase = nullptr;
        try { nwbase = new int[2 * S.stack_length]; }
        catch (const std::bad_alloc& e) { return false; }
        S.stack_length *= 2;
        for (int i = 0; i < S.stack_size; i++)
        {
            nwbase[i] = S.base[i];
        }
        delete[] S.base;
        S.base = nwbase;
        S.top = S.base + S.stack_size;
    }
    *S.top = e;
    S.top++;
    S.stack_size++;
    return true;
}

bool Pop(my_stack& S)
{
    if (StackEmpty(S)) { return false; }
    S.top--;
    S.stack_size--;
    return true;
}

void Convertion(my_stack& S, long long num)
{
    do
    {
        int x = num % 2;
        Push(S, x);
        num /= 2;
    } while (num);
}

void PrintStack(my_stack S)
{
    for (int i = S.stack_size-1; i >= 0; i--)
    {
        std::cout << S.base[i];
    }
    std::cout << std::endl;
}

void StackClear(my_stack& S)
{
    delete[] S.base;
    S.base = S.top = nullptr;
    InitStack(S);
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
