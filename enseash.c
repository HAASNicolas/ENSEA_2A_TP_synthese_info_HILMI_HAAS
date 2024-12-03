#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>

int main(int argc, char *argv[]) {
	
	write(argv[1], "$ ./enseash\n", 12);
	write(argv[1], "Bienvenue dans le Shell ENSEA.\n", 31);
	write(argv[1], "Pour quitter, tapez 'exit'.\n", 28);
	write(argv[1], "enseash % ", 10);
}
