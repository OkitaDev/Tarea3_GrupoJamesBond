#ifndef ENTREGAS_H
#define ENTREGAS_H

//Funcion para importar la informacion desde un .txt
void importarArchivo(HashMap *);

//Funcion para calcular la distancia entre dos entregas
void distanciaEntregas(HashMap *);

//Funcion para entregar las 5 ubicaciones mas cercanas a la entregeda
void entregasCercanas(HashMap *);

//Funcion para crear una ruta hecha por el usuario
void crearRuta(HashMap *, HashMap *);

//Funcion para crear una ruta aleatoria
void crearRutaAleatoria(HashMap *, HashMap *);

//Funcion para mejorar la ruta ingresada de forma manual o automatica
void mejorarRuta(HashMap *);

//Funcion para mostrar todas las rutas creadas
void mostrarRutas(HashMap *);

//Funcion para calcular y mostrar la mejor ruta
void mejorRuta(HashMap *, HashMap *);

#endif