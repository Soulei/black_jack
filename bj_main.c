#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"

#define LIBRE 0
#define BANQUE 1
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

void evaluer_score(short joueur, short carte_recue, short *score){
		carte_recue = donner_valeur_carte(joueur, carte_recue);
		if(carte_recue == 11){		//ajout de la condition où le score est > à 21 donc le as devient 1 point à la place de 11
			*score = *score + carte_recue;
			if((*score) > 21) {
			*score = *score - 10;
			}
		}
		else if(carte_recue<10){
			*score = *score + carte_recue;
		}
		else
			*score = *score + carte_recue;
		
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

																						MAIN


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int main(){
	short i=0;
	short num;
	short num_j, num_b; /*Numero de carte de la banque num_b et numero de carte du joueur num_j*/
	short score1 = 0;	/*Score de la banque score1*/
	short score2 = 0;	/*Score du joueur score2*/
	char reponse;
	
	nb_as_banque=0;
	nb_as_joueur=0;
	srand(time(NULL));
	
	while(i<52){

		cartes[i]=LIBRE;
		i++;		

	}
			printf("\n\n===================  		DISTRIBUTION  		============================\n");
	
	for(i=0;i<2;i++) {

		printf("\n\n    ========================  	MAIN JOUEUR:  	============================\n");
		
		num_j = tirer_carte(JOUEUR);
		afficher_carte(num_j);
		evaluer_score(JOUEUR, num_j, &score2);
		afficher_score(&score2);

		printf("\n\n    ========================  	MAIN BANQUE :  ============================\n");
		
		if(i<1) {		/*Condition if else qui permet de tirer une carte normale et face cachée de la banque dans une seule boucle */
			num_b = tirer_carte(BANQUE);
			afficher_carte(num_b);
			evaluer_score(BANQUE, num_b, &score1);
			afficher_score(&score1);
		}
		else{
			num_b = tirer_carte(BANQUE_CACHEE);
			evaluer_score(BANQUE, num_b, &score1);
			printf("CARTE FACE CACHEE\n");	
			
		}
	
	}
		
	
		printf("\n\n    ************************  TOUR DU JOUEUR :  ****************************\n");
	
	printf("\nVOULEZ VOUS UNE CARTE, n POUR NON, y POUR OUI\n");
	scanf("%c", &reponse);
	while((reponse != 'n') && (score2 < 21)) {
		
		num_j = tirer_carte(JOUEUR);
		afficher_carte(num_j);
		evaluer_score(JOUEUR, num_j, &score2);
		afficher_score(&score2);
		if(score2>21) {
			printf("Vous avez perdu!!!! \n");
			return 0;
		}
		if(score2==21 && nb_as_joueur != 1) {
			printf("Vous avez gagné!!!! \n");
			return 0;
		}
		printf("VOULEZ VOUS UNE CARTE ?\n");
		scanf("%*c%c", &reponse);
	}
	
	
	if(score2==21 && nb_as_joueur == 1) {
		
			printf("BLACK JACK !!!! Vous avez gagné!!!! \n");
			return 0;
			
	}
	
	printf("\n\n    ========================  	MAIN BANQUE CACHEE :  ============================\n");
	
	afficher_main_cachee();
	

		printf("\n\n    ************************  TOUR DE LA BANQUE :  ****************************   \n");
	
	while(score1 <= 16) {	/*Condition à laquelle la banque peut toujours tirer une carte*/
		
		num_b = tirer_carte(BANQUE);
		afficher_carte(num_b);
		evaluer_score(BANQUE, num_b, &score1);
		afficher_score(&score1);
		if(score1>21) {
			printf("La banque a perdu, VOUS AVEZ GAGNE!!!! :\n");
			return 0;
		}
		if(score1==21 && nb_as_banque != 1) {
			printf("Vous avez perdu, La banque a gagné!!!! :\n");
			return 0;
		}
		printf("\n");
	}
	
	if(score1==21 && nb_as_banque == 1) {
		
		printf("BLACK JACK !!!! La Banque a gagné avec un blackjack!!!! :\n");
		return 0;
	}
	
	printf("\n");
	
	if(score2>score1 && score1>=17) {
		
		printf("Felicitaion vous avez gagne\n");
	}
	
	else {
		
		printf("La BANQUE a gagne\n");
	}
	
	return 0;
}
