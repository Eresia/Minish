#ifndef PROCESSEXEC
#define PROCESSEXEC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int proccesExec(char* commande);

#endif
