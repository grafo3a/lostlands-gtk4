#ifndef ALPHABET_H
#define ALPHABET_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char getPreviousLetter(char lettre) {

    lettre = toupper(lettre);
    char prevLetter;

    switch (lettre) {
        case 'A': prevLetter = '-'; break;
        case 'B': prevLetter = 'A'; break;
        case 'C': prevLetter = 'B'; break;
        case 'D': prevLetter = 'C'; break;
        case 'E': prevLetter = 'D'; break;
        case 'F': prevLetter = 'E'; break;
        case 'G': prevLetter = 'F'; break;
        case 'H': prevLetter = 'G'; break;
        case 'I': prevLetter = 'H'; break;
        case 'J': prevLetter = 'I'; break;
        case 'K': prevLetter = 'J'; break;
        case 'L': prevLetter = 'K'; break;
        case 'M': prevLetter = 'L'; break;
        case 'N': prevLetter = 'M'; break;
        case 'O': prevLetter = 'N'; break;
        case 'P': prevLetter = 'O'; break;
        case 'Q': prevLetter = 'P'; break;
        case 'R': prevLetter = 'Q'; break;
        case 'S': prevLetter = 'R'; break;
        case 'T': prevLetter = 'S'; break;
        case 'U': prevLetter = 'T'; break;
        case 'V': prevLetter = 'U'; break;
        case 'W': prevLetter = 'V'; break;
        case 'X': prevLetter = 'W'; break;
        case 'Y': prevLetter = 'X'; break;
        case 'Z': prevLetter = 'Y'; break;
        case '-': prevLetter = 'Z'; break;

    default:
        prevLetter = '-'; break;
    }

    return prevLetter;
}

char getNextLetter(char lettre) {

    lettre = toupper(lettre);
    char nextLetter;

    switch (lettre) {
        case 'A': nextLetter = 'B'; break;
        case 'B': nextLetter = 'C'; break;
        case 'C': nextLetter = 'D'; break;
        case 'D': nextLetter = 'E'; break;
        case 'E': nextLetter = 'F'; break;
        case 'F': nextLetter = 'G'; break;
        case 'G': nextLetter = 'H'; break;
        case 'H': nextLetter = 'I'; break;
        case 'I': nextLetter = 'J'; break;
        case 'J': nextLetter = 'K'; break;
        case 'K': nextLetter = 'L'; break;
        case 'L': nextLetter = 'M'; break;
        case 'M': nextLetter = 'N'; break;
        case 'N': nextLetter = 'O'; break;
        case 'O': nextLetter = 'P'; break;
        case 'P': nextLetter = 'Q'; break;
        case 'Q': nextLetter = 'R'; break;
        case 'R': nextLetter = 'S'; break;
        case 'S': nextLetter = 'T'; break;
        case 'T': nextLetter = 'U'; break;
        case 'U': nextLetter = 'V'; break;
        case 'V': nextLetter = 'W'; break;
        case 'W': nextLetter = 'X'; break;
        case 'X': nextLetter = 'Y'; break;
        case 'Y': nextLetter = 'Z'; break;
        case 'Z': nextLetter = '-'; break;
        case '-': nextLetter = 'A'; break;

    default:
        nextLetter = '-'; break;
    }

    return nextLetter;
}

bool isLettreTapeeValid(char lettre) {
    
	bool isLettreValid = false;
	lettre = toupper(lettre);

	if (lettre == 'A' ||
		lettre == 'B' ||
		lettre == 'C' ||
		lettre == 'D' ||
		lettre == 'E' ||
		lettre == 'F' ||
		lettre == 'G' ||
		lettre == 'H' ||
		lettre == 'I' ||
		lettre == 'J' ||
		lettre == 'K' ||
		lettre == 'L' ||
		lettre == 'M' ||
		lettre == 'N' ||
		lettre == 'O' ||
		lettre == 'P' ||
		lettre == 'Q' ||
		lettre == 'R' ||
		lettre == 'S' ||
		lettre == 'T' ||
		lettre == 'U' ||
		lettre == 'V' ||
		lettre == 'W' ||
		lettre == 'X' ||
		lettre == 'Y' ||
		lettre == 'Z' ||
		lettre == '-' ) {

			isLettreValid = true;
	}

	return isLettreValid;
}

#endif // ALPHABET_H
