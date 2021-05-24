#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura que almacena los valores leidos del .txt
typedef struct tipoEntrega
{
	int identificacion; 
	short validacion; //Validar si ya se uso durante la creacion de las rutas
	long long coordenadaX;
	long long coordenadaY;
}tipoEntrega;

//Estructura que se almacena como posiciones de la ruta
typedef struct tipoCamino
{
	tipoEntrega * posicion; //Almacenar los valores de posicion y el identificador
	double distancia; //Almacenar la distancia entre el punto actual de la persona y este
}tipoCamino;

//Estructura que sirve para almacenar la ruta completa
typedef struct tipoRuta
{
	tipoCamino ** arreglo; //Almacenar las posiciones de entregas
	double distanciaTotal; //Almacenar la distancia total recorrida
	char nombreRuta[20]; //Almacenar el nombre de la ruta
	int largo; //Almacenar la cantidad de entregas de la ruta
}tipoRuta;

tipoEntrega * crearTipoEntrega()
{
    tipoEntrega * nuevo = malloc (sizeof(tipoEntrega));
    return nuevo;
}

tipoCamino * crearTipoCamino()
{
	tipoCamino * nuevo = malloc(sizeof(tipoCamino));
	nuevo->posicion = malloc(sizeof(tipoEntrega));
    return nuevo;
}

tipoRuta * crearTipoRuta(int capacidad)
{
    tipoRuta * nuevaRuta = malloc(sizeof(tipoRuta));
	nuevaRuta->arreglo = malloc(sizeof(tipoCamino) * capacidad + 1);
    nuevaRuta->distanciaTotal = 0;
    nuevaRuta->largo = capacidad + 1;
    return nuevaRuta;
}

void cambioEntrega(tipoRuta * aux, int posicion1, int posicion2)
{
	tipoCamino * temp = aux->arreglo[posicion1];
	aux->arreglo[posicion1] = aux->arreglo[posicion2];
	aux->arreglo[posicion2] = temp;
}