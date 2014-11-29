Projet BlackJack 
=================

Yassine M'chaar
Elyass Hajajou
Souleiman Iman Choukri
Licence SPI 2eme année
TD3

Compilation du programme principale
===================================

$ make clean
$ make resblack

Compilation du fichier test
===========================

$ make clean
$ make test.exe

Fonctions utilisées pour la réalisation du programme
=====================================================

short tirer_carte(short joueur);
void afficher_carte(short num);
void afficher_main(short joueur);
void afficher_main_cachee(void);
void afficher_score(short *score);
short donner_valeur_carte(short joueur, short carte);
void evaluer_score(short joueur, short carte_recue, short *score);


