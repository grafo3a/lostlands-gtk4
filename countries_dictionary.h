#include <stdio.h>
#include <stdlib.h>
#include "utility_functions.h"


char* genererMotSecret(char* p_motSecret){
	
	int nombreAleatoire = getNombreAleatoireMin1Max(5);
	
	//printf("-> nombre aleatoire: %d\n", nombreAleatoire);
	
	switch(nombreAleatoire) {
		
		case 1: p_motSecret = "Matthieu"; break;
		case 2: p_motSecret = "Marc"; break;
		case 3: p_motSecret = "Luc"; break;
		case 4: p_motSecret = "Jean"; break;
		default: p_motSecret = "None";
	}
	
	printf("-> Mot secret 01: %s\n", p_motSecret);
	
	// On calcule la taille de la chaine de caracteres
	/*
	int tailleSecret = 0;
	while(p_motSecret[tailleSecret] != '\0'){
		tailleSecret++;
	}
	*/
	
	//printf("-> Taille via strlen: %d\n", strlen(p_motSecret));
	
	//p_motSecret = toupper(p_motSecret);
	//convertirChaineEnMajuscules(p_motSecret);
	//convertirEnMajuscules(p_motSecret);
	
	return p_motSecret;
}
