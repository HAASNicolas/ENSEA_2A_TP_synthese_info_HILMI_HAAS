# TP de Synthèse – Ensea in the Shell

## Etudiants
* Anass HILMI
* Nicolas

## TP1
### 1. Affichage d’un message d’accueil, suivi d’un prompt simple.
Ce code permet d'affiche le message de début du shell, puis de lire en boucle ce que va rentrer l'utilisateur.
Nous utilisons STDOUT_FILENO pour écrire dans la console.
![Messages de début du shell](images/TP1_Q1_code.png)
![Code de write](images/TP1_Q1_result.png)

### 2. Exécution de la commande saisie et retour au prompt (REPL : read–eval–print loop)
Ce code permet de créer un processus fils qui va exécuter la commande, puis rendre la main au père qui aura attendu la fin du processus fils.
Nous voyons qu'on peut exécuter n'importe quelle commande. Ici on exécute "fortune" et "ls".
![code de fork](images/TP1_Q2_code.png)
![fortune](images/TP1_Q2_fortune.png)
![ls](images/TP1_Q2_ls.png)

### 3. Gestion de la sortie du shell avec la commande “exit” ou un <ctrl>+d
Nous avons ajouter le possibilité de fermer le shell en tappend la command "exit".
![Code de fermeture du shell](images/TP1_Q3_code.png)
![On peut fermer le shell](images/TP1_Q3_result.png)

#### 4. Affichage du code de retour (ou du signal) de la commande précédente dans le prompt
Commme le père attend la fin du processus fils, il suffit de mettre après cet attente un programme pour afficher le code de retour du fils. C'est ce que nous avons faut ci-dessous.
![Code d'affichage du code de retour](images/TP1_Q4_code.png)
![Affichage du code de retour](images/TP1_Q4_result.png)
