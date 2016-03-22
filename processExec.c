#include "processExec.h"

int proccesExec(char** commande){
	char* cmd = *commande;
	char** param = commande;
	pid_t pid;
	switch(pid = fork()){
		case -1 :
			perror("Erreur : Création de processus");
			return PROCESS_ERR;
		case 0 :
		 //Création du fils

			printf("Execution de %s \n", cmd);
			execvp(cmd, param); //Execution de la commande
			printf("Le processus de PID %d à exécuté la commande %s\n", getpid(), cmd);
			exit(NO_ERR);

			// Fin du fils
	}
	return pid; //Envoi du pid du fils au père
}
