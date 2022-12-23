#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 16
#define VIDA 5
main() {
	//INICIALIZACION
	setlocale(LC_CTYPE, "Spanish");
	char pc_cadena[TAM] = "", user_cadena[TAM] = "", car = ' ';
	short intentos = 0,	i = 0, j = 0, completado = 0, longitud = 0, encontrado = 0;
	
	
	//CODE
	
	strcpy(pc_cadena, "ALEJANDRO");
	longitud = strlen(pc_cadena);
	
	for (i = 0; i < longitud ; i++)
		user_cadena[i] = '_';

	user_cadena[i] = '\0'; //NO SE SI SE DESPLAZA AL ASIGNAR UN CARACTER
	intentos = VIDA; completado = 0;
	do {
		printf("Numero de intentos: %hd\n", intentos);
		printf("Caracter :");
		car = getchar();
		fflush(stdin);
		system("cls");
		encontrado = 0;
		for ( i = 0; i < longitud; i++)
			if (car == pc_cadena[i]) {
				user_cadena[i] = car;
				encontrado = 1;
			}
		if (encontrado) {
			printf("\a");
			if (!strcmp(user_cadena, pc_cadena))
				completado = 1;
		}
		else
			intentos--;
		puts(user_cadena);
	} while (intentos > 0 && !completado);
	return 0;
}
