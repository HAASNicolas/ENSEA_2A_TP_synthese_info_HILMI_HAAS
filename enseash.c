#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	// Using STDOUT_FILENO to write to standard output (the console)
	if (write(STDOUT_FILENO, "$ ./enseash\n", 12) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", 31) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Pour quitter, tapez 'exit'.\n", 28) == -1) {exit(EXIT_FAILURE);};
	
	char command[10]; // Chars reading are saved in this buffer
	while (1) {
		// Ask and wait a command
		if (write(STDOUT_FILENO, "enseash % ", 10) == -1) {exit(EXIT_FAILURE);};
		if (read(STDIN_FILENO, &command, 10) == -1) {exit(EXIT_FAILURE);};
		
		// Execute the command, strcmp allows us to compare two strings.
		if (strcmp(command, "fortune\n") == 0) {
			// Execute the command "fortune", by writing a phrase in the shell
			if (write(STDOUT_FILENO, "Today is what happened to yesterday.\n", 37) == -1) {exit(EXIT_FAILURE);};
		}
	}
	
	//exit(EXIT_SUCCESS); // Returns SUCCESS to indicate that everything went well
}

