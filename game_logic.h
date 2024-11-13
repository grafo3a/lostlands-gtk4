#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "countries_dictionary.h"
//#include "alphabet.h"


// Les prototypes de fonction
void setLostLandLabel(GObject *p_label);
void setRoundNumberLabel(GObject *p_label);
void setPointsNumberLabel(GObject *p_label);
void setSuccessNumberLabel(GObject *p_label);
void setGameNumberLabel(GObject *p_label);
void setMessageLabel(GObject* p_messageLabel);
void setInputBox(GObject *p_editBox);
void setPlayButton(GObject* p_playButton);
void setContinueButton(GObject* p_continueButton);
void initialiserJeu();
void jouer();
char getLettreTapee();
char* masquerMot(char* p_masque, int tailleSecret);
void afficherMotMasqueh(char* p_masque);
void afficherNumeroRound(int roundNumber);
void afficherNombrePoints(int pointsNumber);
void afficherNombreSuccess(int successNumber);
void afficherNumeroGame(int gameNumber);
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
GObject* p_roundNumberLabel;
GObject* p_pointsNumberLabel;
GObject* p_successNumberLabel;
GObject* p_gameNumberLabel;
GObject* p_messageLabel;
GObject* p_inputBox;
GObject* p_playButton;
GObject* p_continueButton;
GObject* p_previousButton;
GObject* p_nextButton;
char* p_masque;
char* p_motMasqueh;
char* p_motSecret;
int roundsNumber = 0;
int pointsNumber = 0;
int successNumber = 0;
int gameNumber = 0;
int maxGameNumber = 0;
bool isRoundComplete = false;


void initialiserJeu() {
	/* Un nouveau round commence */

	isRoundComplete = false;
	roundsNumber++;
	afficherNumeroRound(roundsNumber);

	char* p_motAleatoire = genererMotSecret(p_motSecret);
	int tailleMotSecret = strlen(p_motAleatoire);
	p_motSecret = malloc(tailleMotSecret);

	int i = 0;
	while (i <= tailleMotSecret) {
		
		if (i < tailleMotSecret) {

			char c = p_motAleatoire[i];
			p_motSecret[i] = toupper(c);

		} else {
			p_motSecret[i] = '\0';
		}

		i++;
	}

	p_masque = malloc(tailleMotSecret);
	p_motMasqueh = masquerMot(p_masque, tailleMotSecret);

	// On calcule maxGameNumber (nombre de fois jouables)
	if (tailleMotSecret < 8) {
		maxGameNumber = 12;
	} else if (tailleMotSecret >= 8 && tailleMotSecret < 14) {
		maxGameNumber = 14;
	} else {
		maxGameNumber = 16;
	}

	gameNumber = 0;
	afficherNumeroGame(gameNumber);
	afficherMotMasqueh(p_motMasqueh);
	gtk_label_set_text(GTK_LABEL(p_messageLabel), "NEW ROUND. GOOD LUCK!");
	gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");
	gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");
	enablePlayButton();
	disableContinueButton();
}

void jouer() {
	/* Quand le bouton play est cliqueh */

	char lettreTapee = getLettreTapee();
	int tailleSecret = strlen(p_motSecret);
	jouerLettre(lettreTapee, p_motSecret, p_motMasqueh, tailleSecret);
	gameNumber++;

	if ( gameNumber > maxGameNumber) {
		gameNumber = 1;
	}
	
	afficherNumeroGame(gameNumber);
	afficherMotMasqueh(p_motMasqueh);
	disablePlayButton();
	enableContinueButton();
}

char* masquerMot(char* p_masque, int tailleMotSecret) {
	
	int i = 0;

	while(i <= tailleMotSecret){

		if(i < tailleMotSecret){
			p_masque[i] = '*';
			
		} else {
			p_masque[tailleMotSecret] = '\0';
		}
		
		i++;
	}
	
	return p_masque;
}

void afficherMotMasqueh(char* p_masque) {
  gtk_label_set_text(GTK_LABEL(p_lostLandLabel), p_masque);
}

void afficherNumeroRound(int roundNumber) {

	// On convertit le numero ressu en chaine de caracteres pour l'afficher
	char chaine[20];
    sprintf(chaine, "%d", roundNumber);
	gtk_label_set_text(GTK_LABEL(p_roundNumberLabel), chaine);
}

void afficherNombrePoints(int pointsNumber) {

	// On convertit le numero ressu en chaine de caracteres pour l'afficher
	char chaine[20];
    sprintf(chaine, "%d", pointsNumber);
	gtk_label_set_text(GTK_LABEL(p_pointsNumberLabel), chaine);
}

void afficherNombreSuccess(int successNumber) {

	// On convertit le numero ressu en chaine de caracteres pour l'afficher
	char chaine[20];
    sprintf(chaine, "%d", successNumber);
	gtk_label_set_text(GTK_LABEL(p_successNumberLabel), chaine);
}

void afficherNumeroGame(int gameNumber) {

	// On convertit le numero ressu en chaine de caracteres pour l'afficher
	char chaine[20];
    sprintf(chaine, "%d / %d", gameNumber, maxGameNumber);
	gtk_label_set_text(GTK_LABEL(p_gameNumberLabel), chaine);
}

void jouerLettre(char lettreTapee, char* p_motSecret, char* p_motMasqueh, int tailleMotSecret) {

	int occurrence = 0;
	int i = 0;
	char messagePresence[] = "* is present";
	char messageAbsence[] = "* is absent";

	while(i <= tailleMotSecret) {
		// Iteration sur chaque lettre

		if(i < tailleMotSecret) {
			if(toupper(p_motSecret[i]) == toupper(lettreTapee)) {
				// Si la lettre est presente dans le mot, on remplace * par la lettre

				p_motMasqueh[i] = toupper(lettreTapee);
				occurrence++;
			}

		} else {
			p_motMasqueh[tailleMotSecret] = '\0';
		}

		i++;
	}

	if (occurrence > 0) {
		// Si la lettre est presente dans le mot

		messagePresence[0] = lettreTapee;
		gtk_label_set_text(GTK_LABEL(p_messageLabel), messagePresence);
		gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");
		gtk_widget_add_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");

		/* On verifie si motSecret = motMasqueh */
		int difference = 1;
		difference = strcmp(p_motSecret, p_motMasqueh);
		
		if (difference == 0) {
			/* La fin d'un round en cas de succes. */

			pointsNumber++;
			successNumber = (pointsNumber * 100) / roundsNumber;

			afficherNombrePoints(pointsNumber);
			afficherNombreSuccess(successNumber);

			char messageSuccess[] = "";
			sprintf(messageSuccess, "%s\nBravo! The word is %s", messagePresence, p_motSecret);
			gtk_label_set_text(GTK_LABEL(p_messageLabel), messageSuccess);
			isRoundComplete = true;
			
		} else {
			/* La fin d'un round en cas d'un caractere correct mais le mot devoileh incorrect */

			messageAbsence[0] = lettreTapee;
			gtk_label_set_text(GTK_LABEL(p_messageLabel), messageAbsence);
			gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");
			gtk_widget_add_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");

			if (gameNumber == (maxGameNumber - 1)) {

				char messageEchec[] = "";
				sprintf(messageEchec, "%s but you fail.\nThe word was %s", messagePresence, p_motSecret);
				gtk_label_set_text(GTK_LABEL(p_messageLabel), messageEchec);
				isRoundComplete = true;
			}
		}
		
	} else {
		// Si la lettre est absente du mot secret

		messageAbsence[0] = lettreTapee;
		gtk_label_set_text(GTK_LABEL(p_messageLabel), messageAbsence);
		gtk_widget_remove_css_class(GTK_WIDGET(p_messageLabel), "texte-vert");
		gtk_widget_add_css_class(GTK_WIDGET(p_messageLabel), "texte-rouge");

		if (gameNumber == (maxGameNumber - 1)) {
			
			char messageEchec[] = "";
			sprintf(messageEchec, "%s\nOh, you fail! The word was %s", messageAbsence, p_motSecret);
			gtk_label_set_text(GTK_LABEL(p_messageLabel), messageEchec);
			isRoundComplete = true;
		}
	}
	
	// A la fin du round, on libere la memoire allouee par malloc
	if (isRoundComplete) {
		free(p_masque);
		free(p_motSecret);
	}
}

char getLettreTapee() {
	
	const gchar *chaineTapee;
	chaineTapee = gtk_editable_get_text (GTK_EDITABLE (p_inputBox));
	char lettreTapee = chaineTapee[0];
	return lettreTapee;
}

void clearLettreTapee() {
	gtk_editable_set_text(GTK_EDITABLE (p_inputBox), "");
}

void setLostLandLabel(GObject *p_label) {
	p_lostLandLabel = p_label;
}

void setRoundNumberLabel(GObject *p_label) {
	p_roundNumberLabel = p_label;
}

void setPointsNumberLabel(GObject *p_label) {
	p_pointsNumberLabel = p_label;
}

void setSuccessNumberLabel(GObject *p_label) {
	p_successNumberLabel = p_label;
}

void setGameNumberLabel(GObject *p_label) {
	p_gameNumberLabel = p_label;
}

void setMessageLabel(GObject* p_mLabel) {
	p_messageLabel = p_mLabel;
}

void setInputBox(GObject *p_editBox) {
	p_inputBox = p_editBox;
}

void setPlayButton(GObject* p_pButton) {
	p_playButton = p_pButton;
}

void setContinueButton(GObject* p_cButton) {
	p_continueButton = p_cButton;
}

void setPreviousButton(GObject* p_prevButton){
	p_previousButton = p_prevButton;
}

void setNextButton(GObject* p_nextButton){
	p_nextButton = p_nextButton;
}


//===========================================
void setPreviousLetter(){
}

void setNextLetter(){
}
//=============================================


void enablePlayButton() {

	gtk_widget_remove_css_class(GTK_WIDGET(p_playButton), "bouton-inactif");
	gtk_widget_add_css_class(GTK_WIDGET(p_playButton), "bouton-actif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_playButton), TRUE);
}

void enableContinueButton() {

	gtk_widget_remove_css_class(GTK_WIDGET(p_continueButton), "bouton-inactif");
	gtk_widget_add_css_class(GTK_WIDGET(p_continueButton), "bouton-actif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_continueButton), TRUE);
}

void disablePlayButton() {

	gtk_widget_remove_css_class(GTK_WIDGET(p_playButton), "bouton-actif");
	gtk_widget_add_css_class(GTK_WIDGET(p_playButton), "bouton-inactif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_playButton), FALSE);
}

void disableContinueButton() {

	gtk_widget_remove_css_class(GTK_WIDGET(p_continueButton), "bouton-actif");
	gtk_widget_add_css_class(GTK_WIDGET(p_continueButton), "bouton-inactif");
	gtk_widget_set_sensitive(GTK_WIDGET(p_continueButton), FALSE);
}

void continuer() {

	clearLettreTapee();
	disableContinueButton();
	enablePlayButton();

	if (isRoundComplete) {
		initialiserJeu();
	}
}
