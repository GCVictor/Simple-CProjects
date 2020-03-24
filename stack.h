#pragma once
#define NOTEXIST -1
#define LOWER    1
#define UPPER    3
#define MAXLINE  256

// 重新定义了一个bool类型
typedef enum bool{ false, true } bool;

// 用栈空间来模拟每一个汉诺塔
// 每一次移动汉诺塔相当于入栈出栈动作
struct Stack {
	int top;        // 当前栈指针的位置
	int maxSize;    // 栈的最大容量
	int* elements;  // 整数型指针用来存放数据
};

// 重新定义了指向Stack的指针
typedef struct Stack* PStack;

// 输入: 指向Stack的指针
// 输出: 该Stack里面的元素数量
int Size(const PStack stack);
// 输入: 指向Stack的指针
// 输出: 返回真如果Stack里面没有元素否则返回假
bool IsEmpty(const PStack stack);
// 输入: 指向Stack的指针
// 输出: 返回真如果Stack里面已经满了否则返回假
// 这个方法可以用来判断汉诺塔是否已经获得胜利
bool IsFull(const PStack stack);
// 输入: 指向Stack的指针
// 输出: 返回栈顶元素如果Stack为空就返回-1
int Peek(const PStack stack);
// 输入: 指向Stack的指针
// 输出: 返回栈顶元素并且移除该元素如果Stack为空就返回-1
int Pop(const PStack stack);
// 输入: 指向Stack的指针
// 如果Stack没有满就将该元素入栈
bool Push(PStack stack, int element);
// 输入: 栈的大小
// 输出: 返回指定大小的栈
PStack CreateStack(int maxSize);
// 输入: 指向Stack的指针
// 释放栈的内存空间
void DestroyStack(const PStack stack);
// 输入: 指向Stack的指针和层数
// 展示Stack某一层的数据
void Show(const PStack stack, int level);
// 输入: 数量n和字符c
// 用字符c进行占位
void Padding(int n, char c);
