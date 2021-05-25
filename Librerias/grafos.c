#include <stdlib.h>

#include "Estructuras\structs.h"
#include "Interfaz\interfaz.h"
#include "TDAs\TDA_Lista\list.h"
#include "TDAs\TDA_Mapa\hashmap.h"

//Funcion para obtener las entregas, con sus respectivas distancias
List * get_adj_nodes(HashMap * mapaIdentificacion, tipoEntregas * nuevaPosicion)
{
	List * list = createList();
	tipoCoordenadas * aux = firstMap(mapaIdentificacion);

	while(aux != NULL)
	{ 
		if(aux->validacion == 0) //Se ingresan unicamente los valores que no se hayan usado
		{
			tipoEntregas * posiciones = creartipoEntregas();
			posiciones->distancia = distanciaDosPuntos(nuevaPosicion->posicion->coordenadaX, aux->coordenadaX, nuevaPosicion->posicion->coordenadaY, aux->coordenadaY);
			posiciones->posicion = aux;
			pushBack(list, posiciones);
		}
		aux = nextMap(mapaIdentificacion);
	}

	return list;
}