#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void ispis(char* polje);
int pobjednik(char* polje);
int main (){
	int pobjed = -1;
	int unos = -1;
	char polje[9]="---------";
	int flag = -1;
	int upper = 9;
	int lower = 1;
	int temp = 0;
	while (pobjednik != 0) {
		unos = -1;
		printf("Unesite broj od 1-9 koji oznacava broj polja na koji unosite'X'\n");
		do {
			do {
				scanf(" %d", &unos);
				if (unos > 9 || unos < 1) {
					printf("Krivi unos probajte ponovno.\n");
				}
			} while (unos > 9 || unos < 1);
			if (( polje[unos - 1] != 'X' && polje[unos - 1] != 'O')) {
				polje[unos - 1] = 'X';
				break;
			}
			printf("Ponovite unos\n");
			
		} while (1);
		temp++;

		pobjed = pobjednik(polje);
		if (pobjed == (-1) && temp == 9) {
			ispis(polje);
			printf("Nema pobjednika izjednacen rezultat\n");
			return 0;
		}
		if (pobjed == 1) {
			ispis(polje);
			printf("Pobjedio je igrac.\n");
			return 0;
		}
		do
		{
			unos = (rand() % (upper - lower + 1)) + lower;
			if (polje[unos - 1] != 'X' && polje[unos - 1] != 'O') {
				polje[unos - 1] = 'O';
				break;
			}
		} while (1);
		temp++;
		
		ispis(polje);
		pobjed = pobjednik(polje);
		if (pobjed == 2) {
			printf("Pobjedilo je racunalo\n");
			return 0;
		}
	}
	return 0;
}
void ispis(char* polje) {
	for (int i = 0; i < 9; i++) {
		printf("%c ", *(polje + i));
		if ((i+1) % 3 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");
}
int pobjednik(char* polje) {

	//horizontalno O
	if (*(polje + 0) == 'O' && *(polje + 1) == 'O' && *(polje + 2) == 'O') {
		return 2;
	}
	if (*(polje + 3) == 'O' && *(polje + 4) == 'O' && *(polje + 5) == 'O') {
		return 2;
	}
	if (*(polje + 6) == 'O' && *(polje + 7) == 'O' && *(polje + 8) == 'O') {
		return 2;
	}
	//horizontalno x
	if (*(polje + 0) == 'X' && *(polje + 1) == 'X' && *(polje + 2) == 'X') {
		return 1;
	}
	if (*(polje + 3) == 'X' && *(polje + 4) == 'X' && *(polje + 5) == 'X') {
		return 1;
	}
	if (*(polje + 6) == 'X' && *(polje + 7) == 'X' && *(polje + 8) == 'X') {
		return 1;
	}
	//vertikalno O
	if (*(polje + 0) == 'O' && *(polje + 3) == 'O' && *(polje + 6) == 'O') {
		return 2;
	}
	if (*(polje + 1) == 'O' && *(polje + 4) == 'O' && *(polje + 7) == 'O') {
		return 2;
	}
	if (*(polje + 2) == 'O' && *(polje + 5) == 'O' && *(polje + 8) == 'O') {
		return 2;
	}
	//vertikalno X
	if (*(polje + 0) == 'X' && *(polje + 3) == 'X' && *(polje + 6) == 'X') {
		return 1;
	}
	if (*(polje + 1) == 'X' && *(polje + 4) == 'X' && *(polje + 7) == 'X') {
		return 1;
	}
	if (*(polje + 2) == 'X' && *(polje + 5) == 'X' && *(polje + 8) == 'X') {
		return 1;
	}
	//koso x
	if (*(polje + 0) == 'X' && *(polje + 4) == 'X' && *(polje + 8) == 'X') {
		return 1;
	}
	if (*(polje + 2) == 'X' && *(polje + 4) == 'X' && *(polje + 6) == 'X') {
		return 1;
	}

	//koso O
	if (*(polje + 0) == 'O' && *(polje + 4) == 'O' && *(polje + 8) == 'O') {
		return 2;
	}
	if (*(polje + 2) == 'O' && *(polje + 4) == 'O' && *(polje + 6) == 'O') {
		return 2;
	}

	return -1;
}