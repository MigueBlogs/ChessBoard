#ifndef TABLERO_H
#define TABLERO_H

class Tablero{
    public:
    	int solucion[8];
        char tabla[8][8];
        int tablaTempo[8][8];
         Tablero() {
            char tabla[8][8];
            int tablaTempo[8][8];
        }
        void iniciaTablas();
        void imprimeTabla ();
        void Array();
        void TableroEnArray(int i, int j);
        void imprimeArray ();
        void movimientoAlfil (int i, int j);
        void movimientoReina (int i, int j);
        void pintaMovimientosPosibles(int *X, int *Y, int tam, char pieza);
        bool isInCoord(int i, int j, int *coordR, int *coordC, int tam);
        void muevePieza(int beforeX, int beforeY, int afterX, int afterY, char pieza);
        bool movimientoValido(int beforeX, int beforeY, int afterX, int afterY, char pieza);
};


/* Inicializa el tablero vacío */
void Tablero::iniciaTablas(){
    int i,j;
    for (i=0;i<8;i++)
        for(j=0;j<8;j++)
            tabla[i][j]='-';
}

/* Imprime el estado actual del tablero */
void Tablero::imprimeTabla (){
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

void Tablero::Array(){ //genera array de 8 lleno de -1
	for (int a=0;a<8;a++)
            solucion[a]=-1;
}

/* Imprime el estado actual del Array*/
void Tablero::imprimeArray (){
    int i;
    printf("\n\n");
    printf("[");
    for (i=0; i<8; i++) {
            printf("%i,", solucion[i]);
    }
    printf("]\n");
}

void Tablero::TableroEnArray(int i, int j){
	solucion[i]=j;
}

/*movimiento Alfil*/
//esta funcion recibe 2 parámetros que es la posición el Alfil
void Tablero::movimientoAlfil (int i, int j){
    int temp1, temp2, x, y;
    temp1=i;
    temp2=j;
    x=0;
    y=0;
    //////////////////diagonal principal
    for (i=temp1; i<8; i++) {
    	y=0;
    	for (j=temp2; j<8; j++) {
        	if(x==y){
        		tabla[i][j]=1;    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    x=0;
    for (i=temp1; i>=0; i--) {
    	y=0;
    	for (j=temp2; j>=0; j--) {
        	if(x==y){
        		tabla[i][j]=1;    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }


    //////////// anti-diagonal
    x=0;
    for (i=temp1; i>=0; i--) {
    	y=0;
    	for (j=temp2; j<8; j++) {
        	if(x==y){
        		tabla[j][i]=1;    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    x=0;
    for (i=temp1; i<8; i++) {
    	y=0;
    	for (j=temp2; j>=0; j--) {
        	if(x==y){
        		tabla[j][i]=1;    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    //tabla[temp1][temp2]= "A";
    /*	imprime coordenadas
     for (i=temp1; i<8; i++) {
        for (j=temp2; j<8; j++) {
            tabla[i][j]=1;
            printf("%i,%i\t", i, j);
        }
         printf("\n");
        puts("");
    }	*/

}

/*movimiento en Reina*/
//esta funcion recibe 2 parámetros que es la posición de la Dama
void Tablero::movimientoReina (int i, int j){
    int temp1, temp2, x, y;
    temp1=i;
    temp2=j;
    x=0;
    y=0;
    //////////////////diagonal principal
    for (i=temp1; i<8; i++) {
    	y=0;
    	for (j=temp2; j<8; j++) {
        	if(x==y){
        		tabla[i][j]='-';    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    x=0;
    for (i=temp1; i>=0; i--) {
    	y=0;
    	for (j=temp2; j>=0; j--) {
        	if(x==y){
        		tabla[i][j]='-';    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }


    //////////// anti-diagonal
    x=0;
    for (i=temp1; i>=0; i--) {
    	y=0;
    	for (j=temp2; j<8; j++) {
        	if(x==y){
        		tabla[j][i]='-';    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    x=0;
    for (i=temp1; i<8; i++) {
    	y=0;
    	for (j=temp2; j>=0; j--) {
        	if(x==y){
        		tabla[j][i]='-';    
        	}else{
        		//nada
        	}
        	y++;
        }
        x++;
    }

    //Columna Superior
	for (i=temp1; i>=0; i--) {
        		tabla[i][temp2]='-';
    }


    //Columna Inferior
	for (i=temp1; i<8; i++) {
        		tabla[i][temp2]='-';
    }

    //Renglon Superior
	for (j=temp2; j>=0; j--) {
        		tabla[temp1][j]='-';
    }

	//Renglon Inferior
	for (j=temp2; j<8; j++) {
        		tabla[temp1][j]='-';
    }
//tabla[temp1][temp2]='♛';
  tabla[temp1][temp2]='Q';
}




/* Muestra los movimientos posibles dada una pieza. La muestra en tabla temporal, y no modifica
el estado de la tabla. Imprime la tabla temporal. El numero corresponde a:
    Rey     1
    Dama    2
    Alfil   3
    Caballo 4
    Torre   5
    Peon    6
*/
void Tablero::pintaMovimientosPosibles(int col[], int fila[], int tam, char pieza){
    int i, j;
    printf("\n\n");

    // Sea el tamanio del array a pintar (col o fila), se pinta la coordenada en la tabla.
    for (i=0;i<tam;i++)
            switch(pieza){
                case 'R'://rey
                case 'r':
                    tablaTempo[fila[i]][col[i]]=1;
                    break;                    
                case 'D'://dama
                case 'd':
                    tablaTempo[fila[i]][col[i]]=2;
                    break;
                case 'A'://alfil
                case 'a':
                    tablaTempo[fila[i]][col[i]]=3;
                    break;
                case 'C'://caballo
                case 'c':
                    tablaTempo[fila[i]][col[i]]=4;
                    break;
                case 'T'://torre
                case 't':    
                    tablaTempo[fila[i]][col[i]]=5;
                    break;
                case 'P'://peon
                case 'p':
                    tablaTempo[fila[i]][col[i]]=6;
            }

    // Imprime movimientos posibles
    printf("\n\n");
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            printf("%i\t", tablaTempo[i][j]);
        }
        printf("\n");
        puts("");
    }

}

void Tablero::muevePieza(int beforeX, int beforeY, int afterX, int afterY, char pieza){
    // Vacia la casilla donde se encontraba la pieza 
    // Si las coordenadas anteriores son negativas, significa que la pieza es nueva
    // y apenas se esta agregando al tablero.

    // Solo si es un movimiento valido, movera la pieza
    if(Tablero::movimientoValido(beforeX, beforeY, afterX, afterY, pieza)){
        if(!(beforeX == -1) && !(beforeY == -1)){
            tabla[beforeX][beforeY]=0; 
        }   

        // Asigna la pieza a su nueva posicion
        switch(pieza){
            case 'R'://rey
            case 'r':
                tabla[afterX][afterY]=1;
                break;                    
            case 'D'://dama
            case 'd':
                tabla[afterX][afterY]=2;
                break;
            case 'A'://alfil
            case 'a':
                tabla[afterX][afterY]=3;
                break;
            case 'C'://caballo
            case 'c':
                tabla[afterX][afterY]=4;
                break;
            case 'T'://torre
            case 't':    
                tabla[afterX][afterY]=5;
                break;
            case 'P'://peon
            case 'p':
                tablaTempo[afterX][afterY]=6;
        }
    }
}

bool Tablero::isInCoord(int i, int j, int coordR[], int coordC[], int tam){
    for(int pos = 0; pos < tam; pos++){
        if( (j == coordR[pos]) && ( i == coordC[pos])){
            return true;
        }
    }

    return false;
}

/* Aqui se realizan las reglas caracteristicas de cada pieza, para saber si el nuevo movimiento es permitido */
bool Tablero::movimientoValido(int beforeX, int beforeY, int afterX, int afterY, char pieza){
    switch(pieza){
        case 'R'://rey
        case 'r':
            return true;
            break;                    
        case 'D'://dama
        case 'd':
            return true;
            break;
        case 'A'://alfil
        case 'a':
            return true;
            break;
        case 'C'://caballo
        case 'c':
            return true;
            break;
        case 'T'://torre
        case 't':   
            return true; 
            break;
        case 'P'://peon
        case 'p':
            return true;
    }
    return false;
}

#endif // TABLERO_H
