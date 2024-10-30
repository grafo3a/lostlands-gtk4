#include <stdio.h>
#include <stdlib.h>
#include "utility_functions.h"


char* genererMotSecret(char* p_motSecret){
	
	int nombreMaxPays = 196;
	int nombreAleatoire = getNombreAleatoireMin1Max(nombreMaxPays);
	
	//printf("-> nombre aleatoire: %d\n", nombreAleatoire);
	
	switch(nombreAleatoire) {
		
		//case 1: p_motSecret = "Matthieu"; break;
		//case 2: p_motSecret = "Marc"; break;
		//case 3: p_motSecret = "Luc"; break;
		//case 4: p_motSecret = "Jean"; break;
		//default: p_motSecret = "None";
		
		case 1: p_motSecret = "Afghanistan"; break;
        case 2: p_motSecret = "Albania"; break;
        case 3: p_motSecret = "Algeria"; break;
        case 4: p_motSecret = "Andorra"; break;
        case 5: p_motSecret = "Angola"; break;
        case 6: p_motSecret = "Antigua-and-Barbuda"; break;
        case 7: p_motSecret = "Argentina"; break;
        case 8: p_motSecret = "Armenia"; break;
        case 9: p_motSecret = "Australia"; break;
        case 10: p_motSecret = "Austria"; break;
        case 11: p_motSecret = "Azerbaijan"; break;
        case 12: p_motSecret = "Bahamas"; break;
        case 13: p_motSecret = "Bahrain"; break;
        case 14: p_motSecret = "Bangladesh"; break;
        case 15: p_motSecret = "Barbados"; break;
        case 16: p_motSecret = "Belarus"; break;
        case 17: p_motSecret = "Belgium"; break;
        case 18: p_motSecret = "Belize"; break;
        case 19: p_motSecret = "Benin"; break;
        case 20: p_motSecret = "Bhutan"; break;
        case 21: p_motSecret = "Bolivia"; break;
        case 22: p_motSecret = "Bosnia-and-Herzegovina"; break;
        case 23: p_motSecret = "Botswana"; break;
        case 24: p_motSecret = "Brazil"; break;
        case 25: p_motSecret = "Brunei"; break;
        case 26: p_motSecret = "Bulgaria"; break;
        case 27: p_motSecret = "Burkina-Faso"; break;
        case 28: p_motSecret = "Burundi"; break;
        case 29: p_motSecret = "Cabo-Verde"; break;
        case 30: p_motSecret = "Cambodia"; break;
        case 31: p_motSecret = "Cameroon"; break;
        case 32: p_motSecret = "Canada"; break;
        case 33: p_motSecret = "Central-African-Republic"; break;
        case 34: p_motSecret = "Chad"; break;
        case 35: p_motSecret = "Chile"; break;
        case 36: p_motSecret = "China"; break;
        case 37: p_motSecret = "Colombia"; break;
        case 38: p_motSecret = "Comoros"; break;
        case 39: p_motSecret = "Congo-Kinshasa"; break;
        case 40: p_motSecret = "Congo-Brazzaville"; break;
        case 41: p_motSecret = "Costa-Rica"; break;
        case 42: p_motSecret = "Cote-d'Ivoire"; break;
        case 43: p_motSecret = "Croatia"; break;
        case 44: p_motSecret = "Cuba"; break;
        case 45: p_motSecret = "Cyprus"; break;
        case 46: p_motSecret = "Czech-Republic"; break;
        case 47: p_motSecret = "Denmark"; break;
        case 48: p_motSecret = "Djibouti"; break;
        case 49: p_motSecret = "Dominica"; break;
        case 50: p_motSecret = "Dominican-Republic"; break;
        case 51: p_motSecret = "East-Timor"; break;
        case 52: p_motSecret = "Ecuador"; break;
        case 53: p_motSecret = "Egypt"; break;
        case 54: p_motSecret = "El-Salvador"; break;
        case 55: p_motSecret = "Equatorial-Guinea"; break;
        case 56: p_motSecret = "Eritrea"; break;
        case 57: p_motSecret = "Estonia"; break;
        case 58: p_motSecret = "Eswatini"; break;
        case 59: p_motSecret = "Ethiopia"; break;
        case 60: p_motSecret = "Fiji"; break;
        case 61: p_motSecret = "Finland"; break;
        case 62: p_motSecret = "France"; break;
        case 63: p_motSecret = "Gabon"; break;
        case 64: p_motSecret = "Gambia"; break;
        case 65: p_motSecret = "Georgia"; break;
        case 66: p_motSecret = "Germany"; break;
        case 67: p_motSecret = "Ghana"; break;
        case 68: p_motSecret = "Greece"; break;
        case 69: p_motSecret = "Grenada"; break;
        case 70: p_motSecret = "Guatemala"; break;
        case 71: p_motSecret = "Guinea"; break;
        case 72: p_motSecret = "Guinea-Bissau"; break;
        case 73: p_motSecret = "Guyana"; break;
        case 74: p_motSecret = "Haiti"; break;
        case 75: p_motSecret = "Honduras"; break;
        case 76: p_motSecret = "Hungary"; break;
        case 77: p_motSecret = "Iceland"; break;
        case 78: p_motSecret = "India"; break;
        case 79: p_motSecret = "Indonesia"; break;
        case 80: p_motSecret = "Iran"; break;
        case 81: p_motSecret = "Iraq"; break;
        case 82: p_motSecret = "Ireland"; break;
        case 83: p_motSecret = "Israel"; break;
        case 84: p_motSecret = "Italy"; break;
        case 85: p_motSecret = "Jamaica"; break;
        case 86: p_motSecret = "Japan"; break;
        case 87: p_motSecret = "Jordan"; break;
        case 88: p_motSecret = "Kazakhstan"; break;
        case 89: p_motSecret = "Kenya"; break;
        case 90: p_motSecret = "Kiribati"; break;
        case 91: p_motSecret = "North-Korea"; break;
        case 92: p_motSecret = "South-Korea"; break;
        case 93: p_motSecret = "Kosovo"; break;
        case 94: p_motSecret = "Kuwait"; break;
        case 95: p_motSecret = "Kyrgyzstan"; break;
        case 96: p_motSecret = "Laos"; break;
        case 97: p_motSecret = "Latvia"; break;
        case 98: p_motSecret = "Lebanon"; break;
        case 99: p_motSecret = "Lesotho"; break;
        case 100: p_motSecret = "Liberia"; break;
        case 101: p_motSecret = "Libya"; break;
        case 102: p_motSecret = "Liechtenstein"; break;
        case 103: p_motSecret = "Lithuania"; break;
        case 104: p_motSecret = "Luxembourg"; break;
        case 105: p_motSecret = "Madagascar"; break;
        case 106: p_motSecret = "Malawi"; break;
        case 107: p_motSecret = "Malaysia"; break;
        case 108: p_motSecret = "Maldives"; break;
        case 109: p_motSecret = "Mali"; break;
        case 110: p_motSecret = "Malta"; break;
        case 111: p_motSecret = "Marshall-Islands"; break;
        case 112: p_motSecret = "Mauritania"; break;
        case 113: p_motSecret = "Mauritius"; break;
        case 114: p_motSecret = "Mexico"; break;
        case 115: p_motSecret = "Micronesia"; break;
        case 116: p_motSecret = "Moldova"; break;
        case 117: p_motSecret = "Monaco"; break;
        case 118: p_motSecret = "Mongolia"; break;
        case 119: p_motSecret = "Montenegro"; break;
        case 120: p_motSecret = "Morocco"; break;
        case 121: p_motSecret = "Mozambique"; break;
        case 122: p_motSecret = "Myanmar"; break;
        case 123: p_motSecret = "Namibia"; break;
        case 124: p_motSecret = "Nauru"; break;
        case 125: p_motSecret = "Nepal"; break;
        case 126: p_motSecret = "Netherlands"; break;
        case 127: p_motSecret = "New-Zealand"; break;
        case 128: p_motSecret = "Nicaragua"; break;
        case 129: p_motSecret = "Niger"; break;
        case 130: p_motSecret = "Nigeria"; break;
        case 131: p_motSecret = "North-Macedonia"; break;
        case 132: p_motSecret = "Norway"; break;
        case 133: p_motSecret = "Oman"; break;
        case 134: p_motSecret = "Pakistan"; break;
        case 135: p_motSecret = "Palau"; break;
        case 136: p_motSecret = "Panama"; break;
        case 137: p_motSecret = "Papua-New-Guinea"; break;
        case 138: p_motSecret = "Paraguay"; break;
        case 139: p_motSecret = "Peru"; break;
        case 140: p_motSecret = "Philippines"; break;
        case 141: p_motSecret = "Poland"; break;
        case 142: p_motSecret = "Portugal"; break;
        case 143: p_motSecret = "Qatar"; break;
        case 144: p_motSecret = "Romania"; break;
        case 145: p_motSecret = "Russia"; break;
        case 146: p_motSecret = "Rwanda"; break;
        case 147: p_motSecret = "Saint-Kitts-and-Nevis"; break;
        case 148: p_motSecret = "Saint-Lucia"; break;
        case 149: p_motSecret = "Saint-Vincent-and-Grenadines"; break;
        case 150: p_motSecret = "Samoa"; break;
        case 151: p_motSecret = "San-Marino"; break;
        case 152: p_motSecret = "Sao-Tome-and-Principe"; break;
        case 153: p_motSecret = "Saudi-Arabia"; break;
        case 154: p_motSecret = "Senegal"; break;
        case 155: p_motSecret = "Serbia"; break;
        case 156: p_motSecret = "Seychelles"; break;
        case 157: p_motSecret = "Sierra-Leone"; break;
        case 158: p_motSecret = "Singapore"; break;
        case 159: p_motSecret = "Slovakia"; break;
        case 160: p_motSecret = "Slovenia"; break;
        case 161: p_motSecret = "Solomon-Islands"; break;
        case 162: p_motSecret = "Somalia"; break;
        case 163: p_motSecret = "South-Africa"; break;
        case 164: p_motSecret = "Spain"; break;
        case 165: p_motSecret = "Sri-Lanka"; break;
        case 166: p_motSecret = "Sudan"; break;
        case 167: p_motSecret = "South-Sudan"; break;
        case 168: p_motSecret = "Suriname"; break;
        case 169: p_motSecret = "Sweden"; break;
        case 170: p_motSecret = "Switzerland"; break;
        case 171: p_motSecret = "Syria"; break;
        case 172: p_motSecret = "Taiwan"; break;
        case 173: p_motSecret = "Tajikistan"; break;
        case 174: p_motSecret = "Tanzania"; break;
        case 175: p_motSecret = "Thailand"; break;
        case 176: p_motSecret = "Togo"; break;
        case 177: p_motSecret = "Tonga"; break;
        case 178: p_motSecret = "Trinidad-and-Tobago"; break;
        case 179: p_motSecret = "Tunisia"; break;
        case 180: p_motSecret = "Turkey"; break;
        case 181: p_motSecret = "Turkmenistan"; break;
        case 182: p_motSecret = "Tuvalu"; break;
        case 183: p_motSecret = "Uganda"; break;
        case 184: p_motSecret = "Ukraine"; break;
        case 185: p_motSecret = "United-Arab-Emirates"; break;
        case 186: p_motSecret = "United-Kingdom"; break;
        case 187: p_motSecret = "United-States-Of-America"; break;
        case 188: p_motSecret = "Uruguay"; break;
        case 189: p_motSecret = "Uzbekistan"; break;
        case 190: p_motSecret = "Vanuatu"; break;
        case 191: p_motSecret = "Vatican-City"; break;
        case 192: p_motSecret = "Venezuela"; break;
        case 193: p_motSecret = "Vietnam"; break;
        case 194: p_motSecret = "Yemen"; break;
        case 195: p_motSecret = "Zambia"; break;
        case 196: p_motSecret = "Zimbabwe"; break;
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
