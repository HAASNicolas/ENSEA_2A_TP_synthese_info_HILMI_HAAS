// code test fault + time_edted
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	// Using STDOUT_FILENO to write to standard output (the console)
	if (write(STDOUT_FILENO, "$ ./enseash\n", 12) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", 31) == -1) {exit(EXIT_FAILURE);};
	if (write(STDOUT_FILENO, "Pour quitter, tapez 'exit'.\n", 28) == -1) {exit(EXIT_FAILURE);};
		
	if (write(STDOUT_FILENO, "enseash", 7) == -1) {exit(EXIT_FAILURE);}; // Ask the user to write a command
	
	char command[50]; // Chars reading are saved in this buffer
	while (1) {

		if (write(STDOUT_FILENO, " % ", 3) == -1) {exit(EXIT_FAILURE);}; // Ask the user to write a command
			
		// Wait that the user write a command
		int size_command = read(STDIN_FILENO, &command, 50);
		if (size_command == -1) {exit(EXIT_FAILURE);}; // Read the command writing by the user
				
		command[size_command-1] = 0; // Replaces \n with the end of text string character
		
		if (strcmp(command, "exit") == 0) { // Check if the command is exit
			if (write(STDOUT_FILENO, "Bye bye...\n", 11) == -1) {exit(EXIT_FAILURE);};
			break; // Execute the command "exit", so close the shell
		}
		
		// Create a fork
		int pid; int status;
		pid = fork();
		
		if (pid != 0) { // Father
			
			// Get the execute start time
			struct timespec tp_start, tp_end;
			clock_gettime(CLOCK_REALTIME, &tp_start);
			
			wait(&status); // Father wait that the son ends
			
			// Get the execute end time
			clock_gettime(CLOCK_REALTIME, &tp_end);
			long int delta_time = (tp_end.tv_sec - tp_start.tv_sec) * 1000 + (tp_end.tv_nsec - tp_start.tv_nsec)/1000000;
			
			if (write(STDOUT_FILENO, "enseash", 7) == -1) {exit(EXIT_FAILURE);};
			
			
			// Display the return code or the son's signal and the execute time
			char msg[16];
			if (WIFEXITED(status)) { // WIFEXITED is true if the process exited via the exit() system call
				sprintf(msg, " [exit:%d|%ldms]", WEXITSTATUS(status), delta_time);
			} else if (WIFSIGNALED(status)) { // WIFSIGNALED is true if the process ends with an unhandled error
				sprintf(msg, " [sign:%d|%ldms]", WTERMSIG(status), delta_time);
			}
			if (write(STDOUT_FILENO, msg, sizeof(msg)) == -1) {exit(EXIT_FAILURE);}; // Display
			
		} else { // Son
			execlp(command, command, (char *) NULL); // Execute the command writed by the user
			if (write(STDOUT_FILENO, "Error command unfind\n", 21) == -1) {exit(EXIT_FAILURE);};
			exit(EXIT_FAILURE);
		}	
	}
	if (write(STDOUT_FILENO, "%", 1) == -1) {exit(EXIT_FAILURE);};
	exit(EXIT_SUCCESS); // Returns SUCCESS to indicate that everything went well
}

