#Valeur representant le fichier test#
Test = test

#Pour la compilation du programme principale#
res_black:	main.o	fonctions.o
		gcc -o res_black main.o fonctions.o -Wall
main.o:		main.c
		gcc -c main.c
fonctions.o:	fonctions.c
		gcc -c fonctions.c

#Pour la compilation du programme de test#

test.exe: fonction_test.o donner_val_carte.o fonctions.o
		gcc -o test.exe fonction_test.o fonctions.o donner_val_carte.o -Wall
		
donner_val_carte.o:$(Test)/donner_valeur_carte.c
		gcc -c $(Test)/donner_val_carte.c

fonction_test.o:$(Test)/fonction_test.c
		gcc -c $(Test)/fonction_test.c

#Permet de supprimer les executables et les fichiers binaires#
clean:
	rm -f res_black test.exe *o
	
