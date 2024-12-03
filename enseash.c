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
		// Ask the user to write a command
		if (write(STDOUT_FILENO, "enseash % ", 10) == -1) {exit(EXIT_FAILURE);};
		
		// Wait that the user write a command
		int size_reading = read(STDIN_FILENO, &command, 10);
		if (size_reading == -1) {exit(EXIT_FAILURE);}; // Read the command writing by the user
				
		command[size_reading-1] = 0; // Replaces \n with the end of text string character
		
		if (strcmp(command, "exit") == 0) { // Check if the command is exit
			if (write(STDOUT_FILENO, "Bye bye...\n", 11) == -1) {exit(EXIT_FAILURE);};
			break; // Execute the command "exit", so close the shell
		}
		
		// Create a fork
		int pid; int status;
		pid = fork();
		
		if (pid != 0) { // Father
			wait(&status); // Father wait that the son ends
		} else { // Son
			execlp(command, command, (char *)NULL); // Execute the command writed by the user
			exit(EXIT_SUCCESS); // Returns SUCCESS to indicate that everything went well
		}	
	}
	if (write(STDOUT_FILENO, "%", 1) == -1) {exit(EXIT_FAILURE);};
	exit(EXIT_SUCCESS); // Returns SUCCESS to indicate that everything went well
}

