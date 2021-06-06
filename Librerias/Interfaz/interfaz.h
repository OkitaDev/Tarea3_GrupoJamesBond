#ifndef INTERFAZ_H
#define INTERFAZ_H

//Macros para texto de colores
#define red "\e[1;91m"
#define green "\e[1;92m" 
#define yellow "\e[1;93m"
#define blue "\e[1;94m"
#define reset "\e[0m"

//Funcion para mostrar el menu
void mostrarMenu();

//Funcion para calcular la distancia entre dos puntos
double distanciaDosPuntos(long long coordenadaX1, long long coordenadaX2, long long coordenadaY1, long long coordenadaY2);

//Funcion para convertir las cadenas a nuestro estandar, primera letra mayuscula, demas en minusculas
void convertirEstandar(char *);

int permutacion(int);
#endif