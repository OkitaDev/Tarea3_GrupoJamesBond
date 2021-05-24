#ifndef ENTREGAS_H
#define ENTREGAS_H

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

tipoEntrega * crearTipoEntrega();
tipoCamino * crearTipoCamino();
tipoRuta * crearTipoRuta(int);
void cambioEntrega(tipoRuta *, int, int);


#endif