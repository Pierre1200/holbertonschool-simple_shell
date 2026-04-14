# holbertonschool-simple_shell
📝 Architecture Projet : Simple Shell (hsh)

📁 1. shell.h (Fiche Technique) Pierre
L'en-tête du projet. Aucun code logique ici, que des déclarations.
* [ ] Mettre les include guards (#ifndef SHELL_H, etc.) pour protéger le fichier.
* [ ] Inclure toutes les bibliothèques autorisées nécessaires (<stdio.h>, <stdlib.h>, <unistd.h>, <sys/wait.h>, <sys/types.h>, <sys/stat.h>, <string.h>).
* [ ] Écrire les prototypes de toutes les fonctions créées dans les fichiers .c (ex: char **split_string(char *line);).

📁 2. main.c (Read - Eval - Print - Loop) Hugo
Le point d'entrée du programme. Il dirige les opérations mais ne fait pas le sale boulot.
* [ ] Créer la fonction main(int argc, char **argv).
* [ ] Mettre en place la boucle principale infinie (while (1)).
* [ ] Vérifier le mode interactif avec isatty(STDIN_FILENO) pour savoir si on doit afficher le prompt ($) .
* [ ] Appeler la fonction de lecture (qui se trouve dans parser.c).
* [ ] Gérer le retour de la lecture (Si EOF / Ctrl+D -> libérer la mémoire et quitter proprement).
* [ ] Appeler la fonction de découpage (qui se trouve dans parser.c).
* [ ] Vérifier si la commande est un "built-in" (via builtins.c). Si oui, l'exécuter.
* [ ] Sinon, appeler l'exécuteur (via executor.c).
* [ ] Libérer la mémoire de la ligne et du tableau de mots à la fin de chaque tour de boucle.

📁 3. parser.c (Découpe) Pierre
Tout ce qui concerne la lecture et la manipulation de l'entrée utilisateur.
* [ ] Fonction de lecture : Utiliser getline pour récupérer ce que l'utilisateur tape. (Attention, getline alloue de la mémoire !).
* [ ] Fonction de découpage (Tokenization) : Prendre la chaîne brute (ex: "ls -l\n") et utiliser strtok pour créer un tableau de chaînes (char **) contenant ["ls", "-l", NULL].
* [ ] Gérer le cas où l'utilisateur tape juste sur "Entrée" (ligne vide ou juste des espaces).

📁 4. executor.c Pierre
Le cœur système du shell : la création de processus.
* [ ] Fonction d'exécution : Prendre le tableau de mots généré par le parser.
* [ ] Utiliser fork() pour créer un processus enfant.
* [ ] Dans l'enfant (fork == 0) : Appeler la fonction qui gère le PATH (dans path.c) pour trouver le bon chemin, puis utiliser execve() pour lancer le programme. Gérer l'erreur si execve échoue.
* [ ] Dans le parent (fork > 0) : Utiliser wait() ou waitpid() pour attendre que l'enfant termine son travail avant de rendre la main à la boucle principale.

📁 5. path.c (Recherche) Hugo
Permet au shell de comprendre ls au lieu de l'obliger à taper /bin/ls.
* [ ] Fonction de récupération du PATH : Chercher la ligne qui commence par "PATH=" dans l'environnement (environ) et en extraire la valeur.
* [ ] Fonction de recherche : Découper ce PATH (avec strtok et le délimiteur :).
* [ ] Boucler sur chaque dossier du PATH, concaténer  le dossier avec un / puis le nom de la commande (ex: /usr/bin + / + ls).
* [ ] Utiliser stat() pour vérifier si ce nouveau chemin existe. Si oui, retourner ce chemin complet à l'exécuteur.

📁 6. builtins.c (Manager) Hugo
Les commandes internes qui ne nécessitent pas de fork.
* [ ] Fonction check_builtin : Comparer la commande tapée avec "exit" ou "env".
* [ ] Fonction pour exit : Libérer absolument toutes les mémoires allouées (free) et appeler la vraie fonction exit().
* [ ] Fonction pour env : Parcourir le tableau global environ et imprimer chaque ligne avec un saut de ligne.

📁 7. utils.c (Outils) Pierre
Les petites fonctions d'aide pour ne pas surcharger les autres fichiers (Règle des 40 lignes de Betty).
* [ ] Fonctions de libération de mémoire (ex: une fonction qui fait proprement un free sur un tableau à deux dimensions char **).
* [ ] Fonctions d'affichage d'erreurs (pour formater les messages d'erreur exactement comme le vrai sh).

# Flowchart
The following diagram describes the logic of the `Simple_Shell` function:

<img width="2239" height="3045" alt="Image" src="https://github.com/user-attachments/assets/181cf82c-f8b5-4b6e-b77e-142c9fda1c60" />