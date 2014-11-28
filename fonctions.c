#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

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

short tirer_carte(short joueur){
	short num;
	
	num=rand()%52;
	while(cartes[num] != LIBRE){
			num=rand()%52;
	}
	cartes[num] = joueur;
	return num;

}

void afficher_carte(short num){
	printf("\n\n");
	if((num>=DEB_COEURS) && (num<=FIN_COEURS)){
		switch(num%13){
			case 0:printf("\t\t\t\t as de coeur    ");break;
			case 1:printf("\t\t\t\t 2 de coeur     ");break;
			case 2:printf("\t\t\t\t 3 de coeur     ");break;
			case 3:printf("\t\t\t\t 4 de coeur     ");break;
			case 4:printf("\t\t\t\t 5 de coeur     ");break;
			case 5:printf("\t\t\t\t 6 de coeur     ");break;
			case 6:printf("\t\t\t\t 7 de coeur     ");break;
			case 7:printf("\t\t\t\t 8 de coeur     ");break;
			case 8:printf("\t\t\t\t 9 de coeur     ");break;
			case 9:printf("\t\t\t\t 10 de coeur    ");break;
			case 10:printf("\t\t\t\t valet de coeur     ");break;
			case 11:printf("\t\t\t\t dame de coeur      ");break;
			case 12:printf("\t\t\t\t roi de coeur       ");break;
		}	
	}		
				
	if((num>=DEB_CARREAUX) && (num<=FIN_CARREAUX)){
		switch(num%13){
			case 0:printf("\t\t\t\t as de coeur    ");break;
			case 1:printf("\t\t\t\t 2 de coeur     ");break;
			case 2:printf("\t\t\t\t 3 de coeur     ");break;
			case 3:printf("\t\t\t\t 4 de coeur     ");break;
			case 4:printf("\t\t\t\t 5 de coeur     ");break;
			case 5:printf("\t\t\t\t 6 de coeur     ");break;
			case 6:printf("\t\t\t\t 7 de coeur     ");break;
			case 7:printf("\t\t\t\t 8 de coeur     ");break;
			case 8:printf("\t\t\t\t 9 de coeur     ");break;
			case 9:printf("\t\t\t\t 10 de coeur    ");break;
			case 10:printf("\t\t\t\t valet de coeur     ");break;
			case 11:printf("\t\t\t\t dame de coeur      ");break;
			case 12:printf("\t\t\t\t roi de coeur       ");break;
		}
	}
	
	if((num>=DEB_PIQUES) && (num<=FIN_PIQUES)){
		switch(num%13){
			case 0:printf("\t\t\t\t as de coeur    ");break;
			case 1:printf("\t\t\t\t 2 de coeur     ");break;
			case 2:printf("\t\t\t\t 3 de coeur     ");break;
			case 3:printf("\t\t\t\t 4 de coeur     ");break;
			case 4:printf("\t\t\t\t 5 de coeur     ");break;
			case 5:printf("\t\t\t\t 6 de coeur     ");break;
			case 6:printf("\t\t\t\t 7 de coeur     ");break;
			case 7:printf("\t\t\t\t 8 de coeur     ");break;
			case 8:printf("\t\t\t\t 9 de coeur     ");break;
			case 9:printf("\t\t\t\t 10 de coeur    ");break;
			case 10:printf("\t\t\t\t valet de coeur     ");break;
			case 11:printf("\t\t\t\t dame de coeur      ");break;
			case 12:printf("\t\t\t\t roi de coeur       ");break;
		}
	}		
	if((num>=DEB_TREFLES) && (num<=FIN_TREFLES)){
		switch(num%13){
			case 0:printf("\t\t\t\t as de coeur    ");break;
			case 1:printf("\t\t\t\t 2 de coeur     ");break;
			case 2:printf("\t\t\t\t 3 de coeur     ");break;
			case 3:printf("\t\t\t\t 4 de coeur     ");break;
			case 4:printf("\t\t\t\t 5 de coeur     ");break;
			case 5:printf("\t\t\t\t 6 de coeur     ");break;
			case 6:printf("\t\t\t\t 7 de coeur     ");break;
			case 7:printf("\t\t\t\t 8 de coeur     ");break;
			case 8:printf("\t\t\t\t 9 de coeur     ");break;
			case 9:printf("\t\t\t\t 10 de coeur    ");break;
			case 10:printf("\t\t\t\t valet de coeur     ");break;
			case 11:printf("\t\t\t\t dame de coeur      ");break;
			case 12:printf("\t\t\t\t roi de coeur       ");break;
		}
	}
}

void afficher_main(short joueur){
	short num=0;
	while(num<52){
		if((cartes[num]==joueur) && (joueur!=3)){
			afficher_carte(num);
		}
		num++;				//on a oublié le numm++ sinon la boucle ne s'arrete pas
	}

}						

void afficher_main_cachee(void){			//fonction sans parametre
	short num=0;
	while(num<52){
		if(cartes[num] == BANQUE || cartes[num] == BANQUE_CACHEE) {			//Ajout de la condition BANQUE
			afficher_carte(num);
		}
		num++;	//on a oublié le numm++ sinon la boucle ne s'arrete pas
	}
}	



void afficher_score(short *score) {
	printf("\n\t\t\t\t LE NOUVEAU SCORE EST %i\n", *score);
}



