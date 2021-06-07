#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define red "\e[1;91m"
#define green "\e[1;92m" 
#define yellow "\e[1;93m"
#define blue "\e[1;94m"
#define reset "\e[0m"

void mostrarMenu()
{
	printf(blue"\n ______________________________\n");
	printf("| EL EMPRENDIMIENTO DE JAVIERA |\n");
	printf(" ------------------------------\n");
	printf(yellow"\n1. Importar Archivo\n");
	printf("2. Distancia entre entregas\n");
	printf("3. Mostrar 3 entregas mas cercanas\n");
	printf("4. Crear Ruta de entregas\n");
	printf("5. Generar Ruta aleatoria\n");
	printf("6. Mejorar Ruta de entregas\n");
	printf("7. Mostrar Rutas de entregas\n");
	printf("8. Ruta Optima de entregas\n");
	printf("9. Mostrar Coordenadas de Entregas\n");
	printf("0. Salir del Programa\n"reset);
}

//Funcion para calcular la distancia entre dos puntos
double distanciaDosPuntos(long long coordenadaX1, long long coordenadaX2, long long coordenadaY1, long long coordenadaY2)
{
	double distancia = sqrt(pow(coordenadaX1 - coordenadaX2, 2) + pow(coordenadaY1 - coordenadaY2, 2));
	return distancia;
}

void convertirEstandar(char * cadena)
{
	cadena[0] = toupper(cadena[0]);
	for(int i = 1; i < cadena[i] != '\0';i++)
	{
		cadena[i] = tolower(cadena[i]);
	} 
}