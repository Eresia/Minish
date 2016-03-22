#ifndef READ_CMD
#define READ_CMD

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>

	#define SIZE_READ_MAX 100
	#define NB_ARG_MAX 20
	#define ENTER 0

	char** readCmd();

#endif
