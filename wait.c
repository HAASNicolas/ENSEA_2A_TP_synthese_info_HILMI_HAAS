#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	execlp("sleep", "sleep", "1", (char *)NULL);
	exit(EXIT_SUCCESS);
}