#include "ReadCmd.h"
#include "processExec.h"

int main(int argc, char** argv){

	int result = 0;
	char** cmd;
	pid_t pidFils;
	int background = 0;

	//On lit la commande
	cmd = readCmd(&background);

	//Tant qu'on a pas quitté ou qu'il n'y a pas d'erreur
	while(!QUIT(cmd[0]) && (result >= NO_ERR)){

		//On éxecute la commande
		result = proccesExec(cmd);

		//Si pas d'erreur
		if(result > 0){
			//On lit une nouvelle commande
			cmd = readCmd(&background);

			pidFils = result;

			//Si erreur dans la lecture
			if(cmd[0] == NULL){
				result = READ_ERR;
			}
		}
		if(!background){
			while(waitpid(pidFils,0,0)!=-1);
		}
		else{
			background = 0;
		}
	}

	return result;
}
