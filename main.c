#include "ReadCmd.h"
#include "processExec.h"

int main(int argc, char** argv){

	char** cmd = readCmd();
	while(cmd[0][0] != EOF){
		proccesExec(cmd);
		cmd = readCmd();
	}

	return 0;
}
