#include <stdlib.h>
#include <stdio.h>

#include "Estructuras/structs.h"
#include "Interfaz/interfaz.h"
#include "TDAs/TDA_Lista/list.h"
#include "TDAs/TDA_Mapa/hashmap.h"

short is_valid(tipoRuta * nodo,int tamano){
	
	int i,k;
	int * arregloIdentificacion = calloc(tamano,sizeof(int));

	for(i=0 ; i<tamano ; i++){
		if(arregloIdentificacion[nodo->arreglo[i]->posicion->identificacion] == 0) arregloIdentificacion[nodo->arreglo[i]->posicion->identificacion] = 1;
		else return 0;
	}

	return 1;
}

tipoRuta* copia(tipoRuta* nuevaPosicion){
	tipoRuta* posicionAux = crearTipoRuta(nuevaPosicion->largo);
	int c;
	for(c=0 ; c<nuevaPosicion->largo ; c++){
		if(nuevaPosicion->arreglo[c]->posicion->identificacion == -1) break;
		posicionAux->arreglo[c] = nuevaPosicion->arreglo[c];
	}
	
	posicionAux->distanciaTotal = nuevaPosicion->distanciaTotal;
	return posicionAux;
}

//Funcion para obtener las entregas, con sus respectivas distancias
List * get_adj_nodes(HashMap * mapaIdentificacion, tipoRuta * nuevaPosicion)
{
	List* list = createList();
	tipoCoordenadas * aux = firstMap(mapaIdentificacion);
	int largoRuta = nuevaPosicion->largo;

	tipoRuta* posicionAux = crearTipoRuta(nuevaPosicion->largo);

	aux = firstMap(mapaIdentificacion);
	while(aux != NULL){
		posicionAux = copia(nuevaPosicion);
		
		posicionAux->arreglo[largoRuta]->posicion = aux;
		posicionAux->largo = largoRuta + 1;
		posicionAux->arreglo[largoRuta]->distancia = distanciaDosPuntos(aux->coordenadaX,posicionAux->arreglo[largoRuta-1]->posicion->coordenadaX,aux->coordenadaY,posicionAux->arreglo[largoRuta-1]->posicion->coordenadaY);
		posicionAux->distanciaTotal += posicionAux->arreglo[largoRuta-1]->distancia;

		if(is_valid(posicionAux,posicionAux->largo)) pushBack(list,posicionAux);
		aux=nextMap(mapaIdentificacion);
	}

	return list;
}
