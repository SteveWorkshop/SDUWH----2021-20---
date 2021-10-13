// 6-2 Basic Operation of Stack (10 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define STACK_INIT_SIZE 2

typedef int Stack_ElemType;
typedef struct Stack {
    Stack_ElemType* base;
    Stack_ElemType* top;
    int stack_size;
    int stack_length;
} my_stack;

bool InitStack(my_stack& S);
bool DestroyStack(my_stack& S);
bool StackEmpty(my_stack S);
int StackLength(my_stack S);
bool GetTop(my_stack S, Stack_ElemType& e);
bool Push(my_stack& S, Stack_ElemType e);
bool Pop(my_stack& S);

void Print(my_stack s)
{
    std::cerr << "------------IN THE STACK ARE--------------";
    for (int i = 0; i < s.stack_length; i++)
    {
        std::cerr << s.base[i] << "\t";
    }
    std::cerr << "\n";
}

int main() {
    my_stack S;
    if (!InitStack(S)) {
        printf("Failed to initialize, program exit\n");
        return 0;
    }
    int data_size = 0;
    scanf("%d", &data_size);
    while (data_size--) {
        int data = 0;
        scanf("%d", &data);
        if (!Push(S, data)) printf("Stack Overflow\n");
        else printf("%d is pushed into the stack\n", data);
        Print(S);
    }
    while (!StackEmpty(S)) {
        int tem = 0;
        if (!(GetTop(S, tem))) printf("Illegal operation: get top from an empty stack\n");
        else {
            printf("The top element of the stack is %d\n", tem);
            Pop(S);
        }
    }
    DestroyStack(S);
    return 0;
}

bool InitStack(my_stack& S)
{
    try { S.base = new int[STACK_INIT_SIZE]; }
    catch (const std::bad_alloc& e) { return false; }
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
    S.stack_length = 0;
    return true;
}

bool DestroyStack(my_stack& S)
{
    delete[] S.base;
    S.stack_length = 0;
    S.stack_size = 0;
    S.base = S.top = nullptr;
    return true;
}

bool StackEmpty(my_stack S)
{
    if (S.top == S.base) { return true; }
    else { return false; }
}

int StackLength(my_stack S)
{
    return S.stack_length;
}

bool GetTop(my_stack S, Stack_ElemType& e)
{
    if (StackEmpty(S)) { return false; }
    e = *(S.top - 1);
    return true;
}

bool Push(my_stack& S, Stack_ElemType e)
{
    if (S.stack_length == S.stack_size)
    {
        int* nwbase = nullptr;
        try { nwbase = new int[2 * S.stack_size]; }
        catch (const std::bad_alloc& e) { return false; }
        S.stack_size *= 2;
        for (int i = 0; i < S.stack_length; i++)
        {
            nwbase[i] = S.base[i];
        }
        delete[] S.base;
        S.base = nwbase;
        S.top = S.base + S.stack_length;
    }
    *S.top = e;
    S.top++;
    S.stack_length++;
    return true;
}

bool Pop(my_stack& S)
{
    if (StackEmpty(S)) { return false; }
    S.stack_length--;
    S.top--;
    return true;
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
