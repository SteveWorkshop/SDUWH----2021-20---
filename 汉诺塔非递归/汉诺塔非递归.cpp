// 汉诺塔非递归.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>

using std::stack;

struct Frame {
    int num;
    char x, y, z;
};

stack<Frame> sys_stack;

void dosth(int sec, char from, char to)
{
    std::cout << from << " -> " << to << std::endl;
}

void myMain(int n, char x, char y, char z)
{
    sys_stack.push(Frame{ n, x, y, z });//准备进入函数
    while (!sys_stack.empty())
    {
       
        Frame now = sys_stack.top();//刚刚进入函数 
        sys_stack.pop();//模拟拿出来的过程
        if (now.num == 1)
        {
            dosth(1, x, z);
            
        }
        sys_stack.push(Frame{ (now.num) - 1, now.x, now.z, now.y });//注意注意注意，不能写死否则就真死了（这不是递归！！！）
        dosth(now.num, now.x, now.z);
        sys_stack.push(Frame{ (now.num) - 1, now.y, now.x, now.z });

        //函数结束了
    }
}

int main()
{
    myMain(3, 'x', 'y', 'z');
    std::cout << "Hello World!\n";
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
