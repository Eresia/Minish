#include "ReadCmd.h"

char** readCmd(){
	char* cmd = calloc(SIZE_READ_MAX+1, sizeof(char));
	char* param;
	char** result = calloc(NB_ARG_MAX+1, sizeof(char*));
	int i;

	//On lit la console
	read(ENTER, cmd, SIZE_READ_MAX);

	//On enlève le retour chariot
	cmd[strlen(cmd)-1] = '\0';

	//On lit le nom de la commande
	param = strtok(cmd, " ");
	i = 0;

	//Tant qu'il reste des paramètres et qu'on ne dépasse pas le nombre d'arguments
	while((param != NULL) && (i < NB_ARG_MAX)){

		//On ajoute le paramètre
		result[i] = param;

		//On en lit un nouveau
		param = strtok(NULL, " ");

		i++;
	}

	return result;
}
