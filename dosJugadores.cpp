#include <iostream>
#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "rlutil.h"

using namespace std;

void modo_Dos_Jugador(int vPuntajes[],string vNombre[],int& nPartida)
{

    const int cantDados = 6;
    int vDados[cantDados];
    int numeroRonda = 0, numeroLanzamiento = 0, puntajeTotal = 0, puntajeTotal2=0,numeroPartida = 0;
    string nombre, nombre2;


    cout << "Ingrese el nombre del jugador 1: " << endl;
    cin >> nombre;
    cout<< "ingrese el nombre del jugador 2: " <<endl;
    cin>>nombre2;


    //PARTIDA JUGADOR 1
    do
    {
        int puntajeRonda = 0;
        //CONTADOR DE RONDAS
        numeroRonda++;

        cout << "\t" "               Ronda #" << numeroRonda << endl << endl;
        cout << "\t" "---------------------------------------" << endl << endl;

        //FOR PARA REALIZAR LOS TRES LANZAMIENTOS Y CONTAR LOS PUNTOS
        for(int j=0; j<3; j++)
        {
            system("cls");

            //BANDERA QUE INFORMA SI HAY SEXTETO, ESTA DENTRO DEL FOR DE LOS LANZAMIENTOS PARA QUE SE REINICIE CON CADA TIRADA NUEVA
            bool haySexteto = false;
            bool hayEscalera = false;
            bool sonIguales = false;

            //CONTADOR DE CANTIDAD DE LANZAMIENTOS
            numeroLanzamiento++;

            //VARIABLE DE PUNTAJE PARCIAL QUE SE REINICIA CON CADA LANZAMIENTO
            int puntajeParcial = 0;

            //ASIGNACION DE VALORES ALEATORIOS A LOS 6 DADOS

            realizarTirada(vDados, 6, 5, 2);


            //CONDICIONES DE PUNTOS
            verificarSexteto(vDados, cantDados, haySexteto, sonIguales, puntajeParcial);

            verificarEscalera(vDados, hayEscalera, puntajeParcial);

            if(haySexteto == false && hayEscalera == false)
            {
                verificarSumaDados(vDados, cantDados, puntajeParcial);
            }
            //CORTE DEL LANZAMIENTO CUANDO SE TIRA SEXTETO6 O ESCALERA

            //VECTOR PARA ACUMULAR LOS PUNTOS DE CADA LANZAMIENTO
            //LE ASIGNO AL VECTOR EN LA POSICION j EL PUNTAJE PARCIAL QUE RESULTO DE EL PROCESAMIENTO DE LAS CONDICIONES

            if ((haySexteto == true) && (puntajeParcial == 0))
            {
                puntajeTotal = 0;
                puntajeRonda = 0;
                j = 3;
            }
            if(hayEscalera)
            {
                puntajeRonda = 100;
                j = 3;
            }
            if(puntajeParcial > puntajeRonda)
            {
                puntajeRonda = puntajeParcial;
            }
            cout <<endl;
            cout <<endl;
            cout << "\t" "TURNO DE " << nombre << " | RONDA #" << numeroRonda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
            cout << "\t" "--------------------------------------------------------------------------" << endl;
            if(puntajeRonda > 0)
            {
                cout << "\t" "MAXIMO PUNTAJE DE LA RONDA: " << puntajeRonda << " PUNTOS" << endl;
            }
            else
            {
                cout << "\t" "SEXTETO DE 6 -- EL PUNTAJE SE REINICIA A 0 :(" << endl << endl;
                cout << "\t" "--------------------------------------------------------------------------" << endl;
            }
            cout << "\t" "LANZAMIENTO #" << numeroLanzamiento << endl;
            cout << "\t" "--------------------------------------------------------------------------" << endl;
            cout << "\t"<<vDados[0] << " " << vDados[1]<< " " << vDados[2] << " " << vDados[3] << " " << vDados[4] << " " << vDados[5];
            cout << "\t" " = " << puntajeParcial << " PUNTOS" << endl << endl;

            if(hayEscalera)
            {
                cout << "\t" "   �ESCALERA!   �GANASTE LA PARTIDA!" << endl;
            }
            system("pause");
        }
        //TERMINA EL CICLO FOR DE LANZAMIENTOS

        //REINICIA EL CONTADOR DE LANZAMIENTOS POR FUERA DEL FOR
        numeroLanzamiento = 0;

        //EN puntajeRonda SE LE ASIGNA EL VALOR QUE RETORNA DE LA FUNCION. EN LA FUNCION SE BUSCA EL MAYOR PUNTAJE DE LOS 3 LANZAMIENTOS. SI SALE
        //SEXTETO6, SE REINICIA EL PUNTAJE TOTAL.
        puntajeTotal += puntajeRonda; ///cambiar variable a mayor puntaje

        system("cls");
        cout << "\t" "RONDA #" << numeroRonda << endl;
        cout << "\t" "NOMBRE: " << nombre << endl << endl;
        cout << "\t" "PUNTAJE TOTAL: " << puntajeTotal << endl << endl;

        system("pause");
    }
    while(puntajeTotal < 100 );  //TOTAL PARTIDA

    // ACUMULA LOS PUNTAJES Y SUS NOMBRES DE CADA JUGADOR
    for (int v = 0; v < nPartida; v++)
    {
        if (vPuntajes[v] == 0)
        {
            vPuntajes[v] = puntajeTotal;
            vNombre[v] = nombre;
        }
    }
    system("cls");
    cout << "\t" "---------------------------------------" << endl << endl;
    cout << "\t" "   El puntaje total es: " << puntajeTotal << " puntos" << endl << endl;
    cout << "\t" "       Cantidad de rondas: " << numeroRonda << endl << endl;
    cout << "\t" "       Nombre del ganador: " << nombre << endl << endl;
    cout << "\t" "---------------------------------------" << endl << endl;
}


