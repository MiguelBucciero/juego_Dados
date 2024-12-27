#include <iostream>
#include <ctime>
#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "rlutil.h"


using namespace std;

int main()
{
    int opcion, nPartida=1;
    int vPuntajes[100]={};
    string vNombre[100]={};
    srand(time(0));

    do{
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion, vPuntajes, vNombre,nPartida);
        system("pause");
    }
    while(opcion != 0);
    return 0;
}

