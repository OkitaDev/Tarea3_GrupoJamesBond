//Librerias de C
#include <stdio.h>
#include <stdlib.h>

//Librerias creadas por nosotros
#include "Librerias\TDAs\TDA_Mapa\hashmap.h"
#include "Librerias\Interfaz\interfaz.h"
#include "Librerias\entregas.h"

int main()
{
	short opcion;
	//Creacion de mapas para guardar informacion
	HashMap * mapaIdentificacion = createMap(10);
	HashMap * mapaRutas = createMap(10);
	//Funciones para almacenar el tamaño del mapa despues de cada operacion
	int tamanoIdentificacion, tamanoRutas;

	do
	{
		mostrarMenu();

		//Eleccion de la opcion del menu
		printf("\nElija una opcion: ");
		scanf("%i", &opcion);
		if(opcion == 0) break;
		
		//Calculo del tamaño del mapa
		tamanoIdentificacion = size(mapaIdentificacion);
		tamanoRutas = size(mapaRutas);

		switch(opcion)
		{
			case 1:
				importarArchivo(mapaIdentificacion);
				break;
			case 2:
				if(tamanoIdentificacion != 0) distanciaEntregas(mapaIdentificacion);
				else printf(red"\nNo ha recibido entregas\n"reset);
				break;
			case 3:
				if(tamanoIdentificacion != 0) entregasCercanas(mapaIdentificacion);
				else printf(red"\nNo ha recibido entregas\n"reset);
				break;
			case 4:
				if(tamanoIdentificacion != 0) crearRuta(mapaIdentificacion,mapaRutas);
				else printf(red"\nNo ha recibido entregas\n"reset);
				break;
			case 5:
				if(tamanoIdentificacion != 0) crearRutaAleatoria(mapaIdentificacion,mapaRutas);
				else printf(red"\nNo ha recibido entregas\n"reset);
				break;
			case 6:
				if(tamanoRutas != 0) mejorarRuta(mapaRutas);
				else printf(red"\nNo ha creado rutas\n"reset);
				break;
			case 7:
				if(tamanoRutas != 0) mostrarRutas(mapaRutas);
				else printf(red"\nNo ha creado rutas\n"reset);
				break;
			case 8:
				break;
			default:
				printf(red "\nNo existe tal opcion\n" reset);
				break;
		}
	}while(opcion != 0);

	//Liberacion de Memoria
	free(mapaIdentificacion);
	free(mapaRutas);

	printf("\nFin del Programa\n\n");
	return 0;
}