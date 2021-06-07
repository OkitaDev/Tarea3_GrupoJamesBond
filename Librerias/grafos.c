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
tipoRuta* copia(tipoRuta* nuevaRuta)
{
	tipoRuta* posicionAux = crearTipoRuta(nuevaRuta->largo);
	for(int c = 0 ; c < nuevaRuta->largo ; c++)
		posicionAux->arreglo[c] = nuevaRuta->arreglo[c];

	posicionAux->distanciaTotal = nuevaRuta->distanciaTotal;
	return posicionAux;
}

//Funcion para obtener las entregas, con sus respectivas distancias
List * get_adj_nodes(HashMap * mapaIdentificacion, tipoRuta * nuevaRuta)
{
	List* list = createList(); //Se crea la lista
	tipoCoordenadas * aux = firstMap(mapaIdentificacion); 
	int largoRuta = nuevaRuta->largo;//Se guarda el largo de la ruta

	while(aux != NULL)
	{
		//Se copia la información
		tipoRuta * rutaAux = copia(nuevaRuta);
		
		rutaAux->arreglo[largoRuta]->posicion = aux;//Se guarda la nueva posicion
		rutaAux->largo = largoRuta + 1;//Se aumenta el largo

		//Se calcula distancia entre puntos
		rutaAux->arreglo[largoRuta]->distancia = distanciaDosPuntos(aux->coordenadaX,rutaAux->arreglo[largoRuta-1]->posicion->coordenadaX,aux->coordenadaY,rutaAux->arreglo[largoRuta-1]->posicion->coordenadaY);

		//Y se aumenta el valor de distancia total
		rutaAux->distanciaTotal += rutaAux->arreglo[largoRuta]->distancia;
		
		//Si es una ruta valida, se almacena en la lista
		if(is_valid(rutaAux,rutaAux->largo) == 1) pushBack(list,rutaAux);
		aux = nextMap(mapaIdentificacion);
	}
	return list;
}
