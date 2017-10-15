Hola, para poder ocupar esta pieza es necesario compilar desde línea de comandos 
lo siguiente:

1.- g++ -o Alfil.exe main.cpp

Una vez realizado generará un EXE que abriremos con el siguiente comando,
insertando en él las coordenadas de la pieza donde se guiera colocar.

2.- Alfil.exe 4 4

El resultado será el tablero generado en blanco para demostrar que no hay ninguna
pieza y la siguiente serán los posibles movimientos del alfil marcando con 1's
los posibles espacios donde pueda ya sea avanzar o atacar.