/*
Código por: Miguel Ángel Vargas Espinosa
para la materia de Sistemas Expertos 
*/

#include <stdio.h>
#include <stdlib.h>
#include "Tablero.h"
#include "Algoritmo3.h"

int main(){
    char a;
    fflush(stdin);
	printf("Hola usuario, las 40,340 soluciones posibles han sido exportadas a un TXT deseas hacer 8(factorial)?\n Y/N\n");
	scanf("%c", &a);
    printf("%c", a);

    // Iniciamos el juego
    Tablero tablero;
    tablero.iniciaTablas(); // Se inicializan el tablero y tabla temporal en ceros.

    printf("Tablero Vacio:");
    tablero.imprimeTabla();
    

    if(a=='Y' || a=='y'){
        //Funcion que imprime 8!
        Torres(tablero.tabla,0,0);    
    }else if(a=='N'|| a=='n');{
        printf("92 posibles soluciones:");
        Reinas(tablero.tabla, 0, 0);
    }

  	//tablero.movimientoReina(5,5);
  	//tablero.movimientoReina(3,4);
  	//tablero.imprimeTabla();

    return 0;
}








