#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura que almacena los valores leidos del .txt
typedef struct tipoCoordenadas
{
	int identificacion; 
	short validacion; //Validar si ya se uso durante la creacion de las rutas
	long long coordenadaX;
	long long coordenadaY;
}tipoCoordenadas;

//Estructura que se almacena como posiciones de la ruta
typedef struct tipoEntrega
{
	tipoCoordenadas * posicion; //Almacenar los valores de posicion y el identificador
	double distancia; //Almacenar la distancia entre el punto actual de la persona y este
}tipoEntrega;

//Estructura que sirve para almacenar la ruta completa
typedef struct tipoRuta
{
	tipoEntrega ** arreglo; //Almacenar las posiciones de entregas
	double distanciaTotal; //Almacenar la distancia total recorrida
	char nombreRuta[20]; //Almacenar el nombre de la ruta
	int largo; //Almacenar la cantidad de entregas de la ruta
}tipoRuta;

tipoEntrega * crearTipoCoordenadas()
{
    tipoEntrega * nuevo = malloc (sizeof(tipoCoordenadas));
    return nuevo;
}

tipoEntrega * crearTipoEntregas()
{
	tipoEntrega * nuevo = malloc(sizeof(tipoEntrega));
	nuevo->posicion = malloc(sizeof(tipoCoordenadas));
    return nuevo;
}

tipoRuta * crearTipoRuta(int capacidad)
{
    tipoRuta * nuevaRuta = malloc(sizeof(tipoRuta));
	nuevaRuta->arreglo = malloc(sizeof(tipoEntrega) * capacidad + 1);
    nuevaRuta->distanciaTotal = 0;
    nuevaRuta->largo = capacidad + 1;
    return nuevaRuta;
}

void cambioEntrega(tipoRuta * aux, int posicion1, int posicion2)
{
	tipoEntrega * temp = aux->arreglo[posicion1];
	aux->arreglo[posicion1] = aux->arreglo[posicion2];
	aux->arreglo[posicion2] = temp;
}