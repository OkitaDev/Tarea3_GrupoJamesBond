#include <stdlib.h>
#include <stdio.h>

#include "Estructuras/structs.h"
#include "Interfaz/interfaz.h"
#include "TDAs/TDA_Lista/list.h"
#include "TDAs/TDA_Mapa/hashmap.h"

//Funcion para validar que sea un nodo correcto, en este caso, que no se repitan identificadores
short is_valid(tipoRuta * nodo,int tamano)
{	
	for(int i = 0; i < tamano; i++)
	{
		for(int k = 0; k < tamano; k++)
		{
			if(i != k && nodo->arreglo[i]->posicion->identificacion == nodo->arreglo[k]->posicion->identificacion) return 0;
		}
	}

	return 1;
}

//Funcion para copiar informacion entre rutas
tipoRuta* copia(tipoRuta* nuevaPosicion)
{
	tipoRuta* posicionAux = crearTipoRuta(nuevaPosicion->largo);
	for(int c = 0 ; c < nuevaPosicion->largo ; c++)
		posicionAux->arreglo[c] = nuevaPosicion->arreglo[c];

	posicionAux->distanciaTotal = nuevaPosicion->distanciaTotal;
	return posicionAux;
}

//Funcion para obtener las entregas, con sus respectivas distancias
List * get_adj_nodes(HashMap * mapaIdentificacion, tipoRuta * nuevaPosicion)
{
	List* list = createList(); //Se crea la lista
	tipoCoordenadas * aux = firstMap(mapaIdentificacion); 
	int largoRuta = nuevaPosicion->largo;//Se guarda el largo de la ruta

	while(aux != NULL)
	{
		//Se copia la información
		tipoRuta * posicionAux = copia(nuevaPosicion);
		
		posicionAux->arreglo[largoRuta]->posicion = aux;//Se guarda la nueva posicion
		posicionAux->largo = largoRuta + 1;//Se aumenta el largo

		//Se calcula distancia entre puntos
		posicionAux->arreglo[largoRuta]->distancia = distanciaDosPuntos(aux->coordenadaX,posicionAux->arreglo[largoRuta-1]->posicion->coordenadaX,aux->coordenadaY,posicionAux->arreglo[largoRuta-1]->posicion->coordenadaY);
		
		//Y se aumenta el valor de distancia total
		posicionAux->distanciaTotal += posicionAux->arreglo[largoRuta-1]->distancia;

		//Si es una ruta valida, se almacena en la lista
		if(is_valid(posicionAux,largoRuta + 1)) pushBack(list,posicionAux);
		aux = nextMap(mapaIdentificacion);
	}

	return list;
}
