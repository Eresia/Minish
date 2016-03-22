#include "ReadCmd.h"

char** readCmd(){
	char* cmd = calloc(SIZE_READ_MAX+1, sizeof(char));
	char* param;
	char** result = calloc(NB_ARG_MAX+1, sizeof(char*));
	int i;

	read(ENTER, cmd, SIZE_READ_MAX);

	cmd[strlen(cmd)-1] = '\0';
	param = strtok(cmd, " ");
	i = 0;
	
	while((param != NULL) && (i < NB_ARG_MAX)){
		result[i] = param;
		param = strtok(NULL, " ");
		i++;
	}

	return result;
}
