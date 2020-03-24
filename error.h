#pragma once

// 处理输入异常
// 假如需要用户输入两个汉诺塔整数
// 用户输入脏字符需要清空输入流避免对下一次输入产生影响
void Clear();

// 处理异常
// 主要是内存分配的问题
// 假如说内存分配失败(可能性较小)
// 就退出程序避免Crash
// 退出程序前输出错误信息方便调试
void ErrorHandler(const char* message);
