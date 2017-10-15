#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Tablero.h"

int main(int argc, char** argv){
	//Datos de entrada por linea de comandos
    int i,j;
    i= atoi(argv[1]);
    j= atoi(argv[2]);
 
    // Iniciamos el juego
    Tablero tablero;
    tablero.iniciaTablas(); // Se inicializan el tablero y tabla temporal en ceros.

    printf("Iniciamos a jugar! Estado actual del tablero:\n");
    tablero.imprimeTabla(); //imprimimos el primer estado de la tabla

    std::cout << "movimiento del Alfil en la posicion ("<<i<<", "<<j<<")" << std::endl;
    tablero.movimientoAlfil(i,j);
    tablero.imprimeTabla();

    return 0;
}
