#include "ReadCmd.h"

char** readCmd(int* background){
	char* cmd = calloc(SIZE_READ_MAX+1, sizeof(char));
	char* param;
	char** result = calloc(NB_ARG_MAX+1, sizeof(char*));
	int i;

	//Tant qu'on a pas de commande
	do{
		//On lit la console
		read(ENTER, cmd, SIZE_READ_MAX);
	} while(strlen(cmd) <= 1);

	//On enlève le retour chariot
	cmd[strlen(cmd)-1] = '\0';

	//On lit le nom de la commande
	param = strtok(cmd, " ");
	i = 0;

	//Tant qu'il reste des paramètres et qu'on ne dépasse pas le nombre d'arguments
	while((param != NULL) && (i < NB_ARG_MAX)){

		if(!strcmp(param, "&")){
			*background = 1;
		}
		else{
			//On ajoute le paramètre
			result[i] = param;
		}

		//On en lit un nouveau
		param = strtok(NULL, " ");

		i++;
	}

	return result;
}
