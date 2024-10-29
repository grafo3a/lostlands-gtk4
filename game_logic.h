#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "countries_dictionary.h"

// Les prototypes de fonction
void setLostLandLabel(GObject *p_label);
void setMessageLabel(GObject* p_messageLabel);
void setInputBox(GObject *p_editBox);
void setPlayButton(GObject* p_playButton);
void setContinueButton(GObject* p_continueButton);
void initialiserJeu();
void jouer();
char getLettreTapee();
char* masquerMot(char* p_masque, int tailleSecret);
void afficherMotMasqueh(char* p_masque);
void jouerLettre(char lettreTapee, char* p_motSecret, char* p_motMasqueh, int tailleSecret);

void enablePlayButton();
void disablePlayButton();
void enableContinueButton();
void disableContinueButton();
void continuer();

// Les define
#define MAX_RANDOM_WORD_SIZE 50

// Les variables
GObject* p_lostLandLabel;
GObject* p_messageLabel;
GObject* p_inputBox;
GObject* p_playButton;
GObject* p_continueButton;
char* p_motMasqueh;
char* p_motSecret;
char* p_masque;
/*
int roundNumber;
int maxGamesNumber;
int success;
int leftGamesNumber;
*/

void initialiserJeu(){

	p_motSecret = genererMotSecret(p_motSecret);

	//printf("-> Mot secret genereh 01: %s\n", p_motSecret);

	int taille = strlen(p_motSecret);
	char* p_chaineTemp = malloc(taille);

	//printf("-> Adresse chaineTemp: %p\n", p_chaineTemp);

	p_motSecret = convertirEnMajuscules(p_motSecret, p_chaineTemp);

	//printf("-> Mot secret genereh 02: %s\n", p_motSecret);

	int tailleSecret = strlen(p_motSecret);
	
	// On conserve le mot en majuscules
	char p_secret[tailleSecret];
	
	int i = 0;
	while(i <= tailleSecret){
		
		if(i < tailleSecret){
			p_secret[i] = toupper(p_motSecret[i]);
			
		} else {
			p_secret[tailleSecret] = '\0';
		}
		
		i++;
	}

	//printf("-> Nouveau mot secret: %s\n", p_secret);
	//printf("\n-> Pointeur sur adresse 00: %p\n", p_motMasqueh );

	p_masque = (char*)malloc(tailleSecret * sizeof(char)); // We allocate memory

	//char p_masque[taille_secret];
	//printf("\n-> Pointeur sur adresse 01: %p\n", p_masque );

	p_motMasqueh = masquerMot(p_masque, tailleSecret);

	//printf("\n-> Pointeur sur adresse 02: %p\n", p_motMasqueh );

	//setMotMasqueh(p_motMasqueh);
	//p_motMasqueh = p_masque;

	//printf("-> Nouveau mot masqueh: %s\n", p_motMasqueh);

	afficherMotMasqueh(p_motMasqueh);
	enablePlayButton();
	disableContinueButton();

	//free(p_masque); // On doit liberer la memoire
	//return 0;
}

void jouer(){
	
	//while(diff != 0){
		
		char lettreTapee = getLettreTapee();

		int tailleSecret = strlen(p_motSecret);

		jouerLettre(lettreTapee, p_motSecret, p_motMasqueh, tailleSecret);
		
		//printf("\nLettre tapee: %c\n", lettreTapee);
		//printf("Mot secret actuel: %s\n", p_motSecret);

		//setMotMasqueh(p_motMasqueh);


		afficherMotMasqueh(p_motMasqueh);

		disablePlayButton();
		enableContinueButton();

		
	//free(p_motMasqueh);
}

char* masquerMot(char* p_masque, int tailleSecret){
	
	int i = 0;
	
	while(i <= tailleSecret){

		if(i < tailleSecret){
			p_masque[i] = '*';
			
		} else {
			p_masque[tailleSecret] = '\0';
		}
		
		i++;
	}

	return p_masque;
}

void afficherMotMasqueh(char* p_masque) {
  
  //printf("\nMot masqueh: %s\n", p_masque);

  gtk_label_set_text(GTK_LABEL(p_lostLandLabel), p_masque);
}

void jouerLettre(char lettreTapee, char* p_motSecret, char* p_motMasqueh, int tailleSecret) {

	int occurrence = 0;
	int i = 0;

	char messagePresence[] = "* is present";
	char messageAbsence[] = "* is absent";


	while(i <= tailleSecret) {
		// Iteration sur chaque lettre
		
		if(i < tailleSecret) {

			if(toupper(p_motSecret[i]) == toupper(lettreTapee)) {
				// Si la lettre est presente dans le mot
				p_motMasqueh[i] = toupper(lettreTapee);
				occurrence++;
			}

		} else {
			p_motMasqueh[tailleSecret] = '\0';
		}

		i++;
	}

	if (occurrence > 0) {
		// Si la lettre est presente dans le mot
		messagePresence[0] = lettreTapee;
		gtk_label_set_text(GTK_LABEL(p_messageLabel), messagePresence);


		gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");
		gtk_widget_add_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");

	} else {
		// Si la lettre est absente dans le mot
		messageAbsence[0] = lettreTapee;
		gtk_label_set_text(GTK_LABEL(p_messageLabel), messageAbsence);


		gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");
		gtk_widget_add_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");
	}
	
}

char getLettreTapee(){

  const gchar *chaineTapee;
  chaineTapee = gtk_editable_get_text (GTK_EDITABLE (p_inputBox));
  char lettreTapee = chaineTapee[0];

  //printf("\nLettre tapee: %c\n", lettreTapee);
  
  return lettreTapee;
}

void clearLettreTapee(){
	gtk_editable_set_text(GTK_EDITABLE (p_inputBox), "");
}

void setLostLandLabel(GObject *p_label){
  p_lostLandLabel = p_label;
}

void setMessageLabel(GObject* p_mLabel){
	p_messageLabel = p_mLabel;
}

void setInputBox(GObject *p_editBox){
  p_inputBox = p_editBox;
}

void setPlayButton(GObject* p_pButton){
  p_playButton = p_pButton;
};

void setContinueButton(GObject* p_cButton){
	p_continueButton = p_cButton;
}

void enablePlayButton(){

	gtk_widget_remove_css_class(GTK_WIDGET(p_playButton), "bouton-inactif");
	gtk_widget_add_css_class(GTK_WIDGET(p_playButton), "bouton-actif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_playButton), TRUE);

	int diff = 1;
	diff = strcmp(p_motSecret, p_motMasqueh);
	
	//printf("\nDiff p_motSecret - p_mot_masqueh: %d\n", diff);
	
	if (diff == 0){
		printf("\n---- BRAVO! LE MOT EST: %s\n", p_motMasqueh);
		initialiserJeu();
	}
}

void enableContinueButton(){

	gtk_widget_remove_css_class(GTK_WIDGET(p_continueButton), "bouton-inactif");
	gtk_widget_add_css_class(GTK_WIDGET(p_continueButton), "bouton-actif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_continueButton), TRUE);
}

void disablePlayButton(){

	gtk_widget_remove_css_class(GTK_WIDGET(p_playButton), "bouton-actif");
	gtk_widget_add_css_class(GTK_WIDGET(p_playButton), "bouton-inactif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_playButton), FALSE);
}

void disableContinueButton(){

	gtk_widget_remove_css_class(GTK_WIDGET(p_continueButton), "bouton-actif");
	gtk_widget_add_css_class(GTK_WIDGET(p_continueButton), "bouton-inactif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_continueButton), FALSE);
}

void continuer(){

	clearLettreTapee();
	disableContinueButton();
	enablePlayButton();
}
