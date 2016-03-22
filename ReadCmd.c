#include "ReadCmd.h"

char** readCmd(){
	char* cmd = calloc(SIZE_READ_MAX+1, sizeof(char));
	char* param;
	char** result = calloc(NB_ARG_MAX, sizeof(char*));
	int enter = ENTER;
	int i;

	read(enter, cmd, SIZE_READ_MAX);

	param = strtok(cmd, " ");

	i = 0;
	while((param != NULL) && (i < NB_ARG_MAX)){
		if(param[strlen(param)-1] == '\n'){
			param[strlen(param)-1]  = '\0';
		}
		result[i] = param;
		param = strtok(NULL, " ");
		i++;
	}

	return result;
}
