#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
//#include <unistd.h>

// Les prototypes de fonction
int getNombreAleatoireMin1Max(int maximum);
char* convertirEnMajuscules(char* chaineCaracteres);


int getNombreAleatoireMin1Max(int maximum) {
	/* Cette fonction genere efficacement un nombre aleatoire
	dans l'intervalle [1 max] */
	
	/* Here we wait for 1 second on Windows.
	If on Unix systems, uncomment #include <unistd.h>
	and use "sleep(1000)" here */
	Sleep(1000);
	
	time_t t;
	
	/* On initialise le generateur de nombres aleatoires, ensuite on genere un nombre */
	srand((unsigned) time(&t));
	maximum++;
	int randomInt = 0;
	
	while(randomInt == 0){
		randomInt = rand() % maximum;
	}
	
	return randomInt;
}

char* convertirEnMajuscules(char* p_chaineCaracteres) {

	int taille = strlen(p_chaineCaracteres);
	char* p_chaineTemp = malloc(taille);
	int i = 0;

	while(i <= taille) {

		p_chaineTemp[i] = toupper(p_chaineCaracteres[i]);
		i++;
	}

	strcpy(p_chaineCaracteres, p_chaineTemp);

	// On libere la memoire allouee par malloc.
	free(p_chaineTemp);
	
	return p_chaineCaracteres;
}
