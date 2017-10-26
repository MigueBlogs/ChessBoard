#ifndef ALGORITMO3_H
#define ALGORITMO3_H
//#include "Tablero.h"

FILE *file = NULL;

void imprimeTabla (char tabla[8][8]){
    int i, j;
    printf("\n\n");

    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            printf("%c\t", tabla[i][j]);
            //cout << tabla[i][j];
        }
        printf("\n");
        puts("");
    }
}

void ExportaTabla (char tabla[8][8]){
	file = fopen("8_factorial.txt" ,"a");
    int i, j;
    fprintf(file,"\n\n");
    
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            fprintf(file,"%c\t", tabla[i][j]);
            //cout << tabla[i][j];
        }
        fprintf(file,"\n");
        fprintf(file,"");
    }
    fclose(file);
}

void movimientoReina (int i, int j, char tabla[8][8]){
      tabla[i][j]='Q';
}

void movimientoTorre (int i, int j, char tabla[8][8]){
      tabla[i][j]='Q';
}

bool aSalvo (char tablero[][8], int renglon, int columna)
{
	// falso: Si 2 reinas están en el mismo Renglón
	for (int i = 0; i < renglon; i++)
		if (tablero[i][columna] == 'Q')
			return false;

	// return false if two queens share the same \ diagonal
	for (int i = renglon, j = columna; i >= 0 && j >= 0; i--, j--)
		if (tablero[i][j] == 'Q')
			return false;

	// return false if two queens share the same / diagonal
	for (int i = renglon, j = columna; i >= 0 && j < 8; i--, j++)
		if (tablero[i][j] == 'Q')
			return false;

	return true;
}

bool aSalvo2 (char tablero[][8], int renglon, int columna)
{
	// falso: Si 2 torres están en el mismo Renglón
	for (int i = 0; i < renglon; i++)
		if (tablero[i][columna] == 'Q')
			return false;
	return true;
}


void Reinas(char tabla[8][8], int renglon, int columna)
{
	//Si se ha encontrado solución imprime tablero
	if(columna==0 && renglon==8){
	    imprimeTabla(tabla);
	    //return;
	}
	

	//Ahora colocamos una Reina en cada casilla de la fila actual
	//y la volvemos recursiva para cada moimiento válido
	for(int i=0; i<8; i++){
		//Si 2 reinas no se atacan entre si mismas...
		if(aSalvo(tabla, renglon, i)){
			//colocamos una reina en esa posisión
		    movimientoReina(renglon,i,tabla);
			//Recusrivamente invocamos de nuevo a la función pero ahora en el siguiente renglón
			Reinas(tabla, renglon+1, 0);
			//backtrak y removemos la reina de su actual posición
			tabla[renglon][i]='-';
		}
	}
}

void Torres(char tabla[8][8], int renglon, int columna)
{
	//Si se ha encontrado solución exporta tablero al .txt
	if(columna==0 && renglon==8){
	    ExportaTabla(tabla);
	    //return;
	}
	

	//Ahora colocamos una Torre en cada casilla de la fila actual
	//y la volvemos recursiva para cada movimiento válido
	for(int i=0; i<8; i++){
		//Si 2 torres no se atacan entre si mismas...
		if(aSalvo2(tabla, renglon, i)){
			//colocamos una torre en esa posisión
		    movimientoTorre(renglon,i,tabla);
			//Recusrivamente invocamos de nuevo a la función pero ahora en el siguiente renglón
			Torres(tabla, renglon+1, 0);
			//backtrak y removemos la torre de su actual posición
			tabla[renglon][i]='-';
		}
	}
}



#endif // ALGORITMO3_H
