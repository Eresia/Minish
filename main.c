#include "ReadCmd.h"
#include "processExec.h"

int main(int argc, char** argv){

	char** cmd = readCmd();
	int result = 0;

	while((cmd[0][0] != EOF) && (result == 0)){
		result = proccesExec(cmd);
		cmd = readCmd();
	}

	return result;
}
