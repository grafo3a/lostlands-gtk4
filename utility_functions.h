#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
//#include <unistd.h>

// Les prototypes de fonction
int getNombreAleatoireMin1Max(int maximum);
char* convertirEnMajuscules(char* chaineCaracteres, char* dynamicString);

int getNombreAleatoireMin1Max(int maximum) {
	/* Cette fonction genere efficacement un nombre aleatoire
	dans l'intervalle [1 max] */
	
	/* Here we wait for 1 second on Windows.
	If on Unix systems, uncomment #include <unistd.h>
	and use "sleep(1000)" here */
	Sleep(1000);
	
	time_t t;
	
	/* We initialize the random number generator */
	srand((unsigned) time(&t));
	maximum++;
	int randomInt = 0;
	
	while(randomInt == 0){
		randomInt = rand() % maximum;
	}
	
	return randomInt;
}

char* convertirEnMajuscules(char* p_chaineCaracteres, char* p_chaineTemp){

	int taille = strlen(p_chaineCaracteres);

	printf("Taille test: %d\n", taille);
	
	//char *dynamicString = malloc(taille);
	strcpy(p_chaineTemp, p_chaineCaracteres);

	int i = 0;
	
	while(i <= taille){
		
		if(i < taille){

			printf("-- element %d: %c\n", i, p_chaineTemp[i]);
			
			p_chaineTemp[i] = toupper(p_chaineCaracteres[i]);
			
		} else {
			p_chaineTemp[taille] = '\0';
		}
		
		i++;
	}

	printf("-> Mot secret majuscule 01: %s ---- %p\n", p_chaineTemp, p_chaineTemp);

	p_chaineCaracteres = p_chaineTemp;

	printf("-> Mot secret 02: %s ---- %p\n", p_chaineCaracteres, p_chaineCaracteres);

	// **** Si necessaire, liberer la memoire ici!
	return p_chaineCaracteres;
}
