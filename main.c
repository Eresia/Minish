#include "ReadCmd.h"
#include "processExec.h"

int main(int argc, char** argv){

	char** cmd = readCmd();
	int result = 0;

	while(!QUIT(cmd[0]) && (result == 0)){
		result = proccesExec(cmd);
		cmd = readCmd();
	}

	return result;
}
