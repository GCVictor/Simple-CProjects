#include "stack.h"
#include "error.h"
#include <stdio.h>

// 对游戏进行初始化
// 分配内存给Stack数组
// 设置每个Stack最大最大容量
void Init(PStack stacks[], int maxSize);
// 进行游戏
void Launch();
// 展示三个汉诺塔
void ShowTower(const PStack stacks[], int maxSize);

int main() {
	Launch();

	return 0;
}

void Launch() {
	int res, s ,e;
	const int maxSize = 8;
	PStack stacks[UPPER];
	Init(stacks, maxSize);
	// 如果游戏没有结束 无限循环
	while (!IsFull(stacks[UPPER - 1])) {
		ShowTower(stacks, maxSize);
		printf("\n>>> 请输入移动方式(1 2)\n");
		// 只是为了兼容 部分开发工具scanf会报错 visual studio
#ifdef _CRT_SECURE_NO_WARNINGS
		res = scanf("%d %d", &s, &e);
#else
		res = scanf_s("%d %d", &s, &e);
#endif // scanf_s
		// 假如输入脏字符 清空
		// 提示用户游戏玩法
		if (res != 2) {
			Clear();
			fprintf(stderr, ">>>  用法: 起点 终点\n");
		}
		else {
			// 假如输入的整数不在范围内
			if (s < LOWER || s > UPPER || e < LOWER || e > UPPER) {
				printf(">>>  汉诺塔范围是[%d-%d]!!!\n", LOWER, UPPER);
			}
			else {
				PStack src = stacks[s - 1];
				PStack dest = stacks[e - 1];
				// 假如移动方没有圆盘
				if (IsEmpty(src)) {
					printf(">>>  汉诺塔%d没有圆盘!!!\n", s);
				}
				else if (!IsEmpty(dest) && Peek(dest) > Peek(src)) {
					// 假如目的方的圆盘比较小
					printf(">>>  %d > %d移动失败!!!\n", Peek(dest), Peek(src));
				}
				else {
					Push(dest, Pop(src));
				}
			}
		}
		printf("\n\n");
	}

	ShowTower(stacks, maxSize);
	printf(">>> 恭喜你完成了挑战!\n");

	// 释放内存结束游戏
	int i;
	for (i = 0; i < UPPER; i++) {
		DestroyStack(stacks[i]);
	}
}

void ShowTower(const PStack stacks[], int maxSize) {
	int i, j;
	for (i = maxSize - 1; i >= 0; i--) {
		for (j = 0; j < UPPER; j++) {
			Show(stacks[j], i);
		}
		printf("\n");
	}
	printf("=====================================================================\n");
	printf("    一号的高度%d                 二号的高度%d              三号的高度%d\n",
		Size(stacks[0]), Size(stacks[1]), Size(stacks[2]));
}

void Init(PStack stacks[], int maxSize) {
	int i;
	for (i = 0; i < UPPER; i++) {
		stacks[i] = CreateStack(maxSize);
	}
	for (i = 0; i < maxSize; i++) {
		Push(stacks[0], i + 1);
	}
}
