#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>

int main(int argc, char *argv[]) {
	
	write(STDOUT_FILENO, "$ ./enseash\n", 12);
	write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", 31);
	write(STDOUT_FILENO, "Pour quitter, tapez 'exit'.\n", 28);
	write(STDOUT_FILENO, "enseash % ", 10);
}
