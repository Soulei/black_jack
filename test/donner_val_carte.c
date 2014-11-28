#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"

#define LIBRE 0
#define BANQUE 1
/*Fonction à tester*/

#define JOUEUR 2
#define BANQUE_CACHEE 3

#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51

short cartes[52];
short nb_as_joueur = 0;		/*Initialisation du nombre de as dans banque et joueur*/
short nb_as_banque = 0;



short donner_valeur_carte(short joueur, short carte){

	carte= carte%13; 	//affecter à carte une valeur entre 0 et 12 
	
	if(carte==10 || carte==11 || carte==12){
		return 10;
	}

	else if(carte==0){
			
		switch(joueur){
			case BANQUE:nb_as_banque++;break;
			case JOUEUR:nb_as_joueur++;break;
		}
		
		return 11;
	}
	
	else
		return carte+1;		
}					
