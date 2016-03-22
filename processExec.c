#include "processExec.h"

int proccesExec(char** commande){
	char* cmd = *commande;
	char** param = commande;
	switch(fork()){
		case -1 :
			perror("Erreur : Création de processus");
			return PROCESS;
		case 0 : //Création du fils
			printf("Execution de %s \n", cmd);
			execvp(cmd, param); //Execution de la commande
			printf("Le processus de PID %d à exécuté la commande %s\n", getpid(), cmd);
			exit(NORMAL); // Fin du fils
	}
	return NORMAL;
}
