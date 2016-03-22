#ifndef READ_CMD
#define READ_CMD

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>

	#define NB_MAX_COMMAND 100
	#define SIZE_READ_MAX 100
	#define NB_ARG_MAX 20
	#define ENTER 0

	#define QUIT(X) (strcmp(X, "quit") == 0)
	#define HIST(X) (strcmp(X, "hist") == 0)

	char** readCmd(int* background);

#endif
