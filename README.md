# TP de Synthèse – Ensea in the Shell

## Student
* Anass HILMI
* Nicolas HAAS

## TP1
### 1. Display a greeting message, followed by a simple prompt.
This code displays the shell start message, then loops what the user enters.
We use STDOUT_FILENO to write to the console.
![Messages de début du shell](images/TP1_Q1_code.png)
![Code de write](images/TP1_Q1_result.png)

### 2. Execute the entered command and return to the prompt (REPL: read–eval–print loop)
This code allows you to create a child process that will execute the command, then return control to the parent who will have waited for the end of the child process.
We see that we can execute any command. Here we execute "fortune" and "ls".
![code de fork](images/TP1_Q2_code.png)
![fortune](images/TP1_Q2_fortune.png)
![ls](images/TP1_Q2_ls.png)

### 3. Managing shell exit with the “exit” command or a <ctrl>+d
We added the ability to close the shell by tapping the "exit" command.
![Code de fermeture du shell](images/TP1_Q3_code.png)
![On peut fermer le shell](images/TP1_Q3_result.png)

### 4. Display the return code (or signal) of the previous command in the prompt
Since the parent is waiting for the child process to finish, we just need to put after this wait a program to display the child's return code. This is what we need below.
![Code d'affichage du code de retour](images/TP1_Q4_code.png)
![Display the return code](images/TP1_Q4_result.png)

### 5. Measuring command execution time using clock_gettime call:
We have taken the difference of the time before and after the execution of the child process. Which gives us the execution time to display.

![](images/TP1_Q5_1.png)
![](images/TP1_Q5_2.png)
![Execute time and exit code](images/TP1_Q4&5.png)

We have modified Son code, because the code after execlp will be executed only if the command does not exist.
![](images/TP1_Son_process.png)
