#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	// Using STDOUT_FILENO to write to standard output (the console)
    
	if (write(STDOUT_FILENO, "$ ./enseash\n", 12) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", 31) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Pour quitter, tapez 'exit'.\n", 28) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "enseash % ", 10) == -1) {exit(EXIT_FAILURE);};
	
	char * buffer; // Chars reading are saved in buffer
	if (read(STDIN_FILENO, &buffer, 20) == -1) {exit(EXIT_FAILURE);};
	
	exit(EXIT_SUCCESS); // Returns SUCCESS to indicate that everything went well
}
