# include<iostream>
# include "menu.h"
# include "juego.h"


using namespace std;

//FUNCION MOSTRAR MENU
int seleccionarOpcion(){
    int opcion;
    cout <<  "\t" "\t" "*********** BIENVENIDOS A ***********" << endl << endl;
    cout <<  "\t" "\t" "********** CIEN O ESCALERA **********" << endl;
    cout <<  "\t" "\t" "*       SELECCIONE UNA OPCION:      *" << endl;
    cout <<  "\t" "\t" "*       1 - UN JUGADOR              *" << endl;
    cout <<  "\t" "\t" "*       2 - DOS JUGADORES           *" << endl;
    cout <<  "\t" "\t" "*       3 - PUNTUACION MAS ALTA     *" << endl;
    cout <<  "\t" "\t" "*       0 - SALIR                   *" << endl;
    cout << "\t" "\t"  "*************************************" << endl << endl;

    cin >> opcion;

    return opcion;
}

//FUNCION SWITCH MENU
void ejecutarOpcion(int opcion, int vPuntajes[],string vNombre[],int& nPartida){


    switch(opcion){
        case 1:
            system("cls");
            modo_Un_Jugador(vPuntajes, vNombre,nPartida);
            break;
        case 2:
            system("cls");
            modo_Dos_Jugador(vPuntajes,vNombre,nPartida);
            break;
        case 3:
            system("cls");
            subMenuRanking(vPuntajes, vNombre, nPartida);
            break;
        case 4:
            system("cls");
            cout << "\t" "\t" "*******************************************************************" << endl << endl;
            cout << "\t" "\t" "--------- ENTRASTE EN EL MODO SECRETO SIMULADO! --------- " << endl << endl;
            cout << "\t" "\t" "*******************************************************************" << endl << endl;
            system("pause");
            system("cls");
            modo_Simulacion(vPuntajes, vNombre, nPartida);
            break;
        case 0:
            cout << "GRACIAS POR JUGAR" << endl;
            break;
        default:
            cout << "OPCION NO VALIDA..." << endl;
        }
}
