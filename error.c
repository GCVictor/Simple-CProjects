#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void ErrorHandler(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void Clear() {
	char ch;
	while ((ch = getchar()) != '\n');
}
