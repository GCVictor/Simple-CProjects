#include "stack.h"
#include "error.h"
#include <stdlib.h>
#include <stdio.h>


int Size(const PStack stack) {
	return stack->top + 1;
}

bool IsEmpty(const PStack stack) {
	return Size(stack) == 0;
}

bool IsFull(const PStack stack) {
	if (stack == NULL) return false;

	return Size(stack) == stack->maxSize;
}

int Peek(const PStack stack) {
	if (IsEmpty(stack)) return NOTEXIST;
	return stack->elements[stack->top];
}

int Pop(const PStack stack) {
	if (IsEmpty(stack)) return NOTEXIST;
	int old = stack->elements[stack->top];
	stack->top--;

	return old;
}

bool Push(PStack stack, int element) {
	if (stack == NULL || IsFull(stack)) return false;
	stack->elements[++stack->top] = element;

	return true;
}

PStack CreateStack(int maxSize) {
	PStack stack = (PStack)malloc(sizeof(struct Stack));
	if (stack == NULL)
		ErrorHandler("Fail to allocate memory in `CreateStack`");
	else {
		stack->elements = (int*)malloc(sizeof(int) * maxSize);
		if (stack->elements == NULL)
			ErrorHandler("Fail to allocate memory in `CreateStack`");
		else {
			stack->top = -1;
			stack->maxSize = maxSize;
		}
	}

	return stack;
}

void DestroyStack(const PStack stack) {
	if (stack == NULL) return;
	free(stack->elements);
	free(stack);
}

void Show(const PStack stack, int level) {
	if (stack == NULL) return;
	const int LEFT = 12;
	if (level > stack->top) {
		Padding(LEFT * 2 + 1, ' ');
		return;
	}

	int element = stack->elements[level];
	int left = LEFT - ((stack->maxSize - element - 1) + 2);
	Padding(left, ' ');
	printf("|");
	Padding(stack->maxSize - element, ' ');
	printf("%d", stack->elements[level]);
	Padding(stack->maxSize - element, ' ');
	printf("|");
	Padding(left, ' ');
}

void Padding(int n, char c) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%c", c);
	}
}
