#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura que almacena los valores leidos del .txt
typedef struct tipoCoordenadas
{
	int identificacion;
	long long coordenadaX;
	long long coordenadaY;
}tipoCoordenadas;

//Estructura que se almacena como posiciones de la ruta
typedef struct tipoEntregas
{
	tipoCoordenadas * posicion; //Almacenar los valores de posicion y el identificador
	double distancia; //Almacenar la distancia entre el punto actual de la persona y este
}tipoEntregas;

//Estructura que sirve para almacenar la ruta completa
typedef struct tipoRuta
{
	tipoEntregas ** arreglo; //Almacenar las posiciones de entregas
	double distanciaTotal; //Almacenar la distancia total recorrida
	char nombreRuta[20]; //Almacenar el nombre de la ruta
	int largo; //Almacenar la cantidad de entregas de la ruta
}tipoRuta;

tipoCoordenadas * crearTipoCoordenadas()
{
    tipoCoordenadas * nuevo = malloc (sizeof(tipoCoordenadas));
    return nuevo;
}

tipoEntregas * crearTipoEntregas()
{
	tipoEntregas * nuevo = malloc(sizeof(tipoEntregas));
	nuevo->posicion = malloc(sizeof(tipoCoordenadas));
    return nuevo;
}

tipoRuta * crearTipoRuta(int capacidad)
{
    tipoRuta * nuevaRuta = malloc(sizeof(tipoRuta));
	nuevaRuta->arreglo = malloc(sizeof(tipoEntregas) * capacidad + 1);
    nuevaRuta->distanciaTotal = 0;
    nuevaRuta->largo = 1;
	for(int i = 0 ; i < capacidad + 1 ; i++)
	{
		nuevaRuta->arreglo[i] = crearTipoEntregas();
	}
    return nuevaRuta;
}

void cambioEntrega(tipoRuta * aux, int posicion1, int posicion2)
{
	tipoEntregas * temp = aux->arreglo[posicion1];
	aux->arreglo[posicion1] = aux->arreglo[posicion2];
	aux->arreglo[posicion2] = temp;
}