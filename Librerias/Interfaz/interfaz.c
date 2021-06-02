#include <stdio.h>
#include <math.h>

#define green "\e[1;92m" 
#define red "\e[1;91m"
#define blue "\e[1;94m"
#define reset "\e[0m"

void mostrarMenu()
{
	printf(green"\n1. Importar Archivo\n");
	printf("2. Distancia entre entregas\n");
	printf("3. Mostrar 5 entregas mas cercanas\n");
	printf("4. Crear Ruta de entregas\n");
	printf("5. Generar Ruta aleatoria\n");
	printf("6. Mejorar Ruta de entregas\n");
	printf("7. Mostrar Rutas de entregas\n");
	printf("8. Ruta Optima de entregas\n");
	printf("0. Salir del Programa\n"reset);
}

//Funcion para calcular la distancia entre dos puntos
double distanciaDosPuntos(long long coordenadaX1, long long coordenadaX2, long long coordenadaY1, long long coordenadaY2)
{
	double distancia = sqrt(pow(coordenadaX1 - coordenadaX2, 2) + pow(coordenadaY1 - coordenadaY2, 2));
	return distancia;
}
