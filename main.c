#include "ReadCmd.h"
#include "processExec.h"

int main(int argc, char** argv){

	int result = 0;
	char** cmd;

	//On lit la commande
	cmd = readCmd();

	//Tant qu'on a pas quitté ou qu'il n'y a pas d'erreur
	while(!QUIT(cmd[0]) && (result == NO_ERR)){

		//On éxecute la commande
		result = proccesExec(cmd);

		//Si pas d'erreur
		if(result == NO_ERR){
			//On lit une nouvelle commande
			cmd = readCmd();

			//Si erreur dans la lecture
			if(cmd[0] == NULL){
				result = READ_ERR;
			}
		}
	}

	return result;
}
