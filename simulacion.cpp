# include <iostream>
# include "juego.h"

using namespace std;

//IMPRIME LOS DADOS POR PANTALLA QUE EL USUARIO INGRESO
void realizarTiradaSimulacion(int vDados[], int numDados, int posx, int posy) {
    for (int i = 0; i < numDados; i++) {
        imprimirDados(vDados,i,(i+1)*10,posy);
    }
}

//INGRESO MANUAL DE LOS DADOS
void ingresarDadosManuales(int vDados[])
{
    int valor_dado;
    cout << "*******************************************************************" << endl << endl;
    cout << "INGRESE LOS NUMEROS DE LOS DADOS: " << endl<< endl;
    cout << "*******************************************************************" << endl << endl;
    for(int x=0; x<6; x++)
    {
        cout<<"DADO NUMERO "<<x+1<<" :";
        cin >> valor_dado;
        vDados[x] = valor_dado;
    }
    cout<<endl;
    system("pause");
    system("cls");
}

//MODO SIMULACION

void modo_Simulacion(int vPuntajes[],string vNombre[],int& nPartida){

    const int cantDados = 6;
    int vDados[cantDados];
    int numeroRonda = 0, numeroLanzamiento = 0, puntajeTotal = 0;
    string nombre;
    cout << "*******************************************************************" << endl << endl;
    cout << "INGRESE SU NOMBRE: "<<endl<<endl;
   cout << "*******************************************************************" << endl << endl;
    cin >> nombre;

    //PARTIDA
    do
    {
        int puntajeRonda = 0;
        //CONTADOR DE RONDAS
        numeroRonda++;

        cout << "\t" "               Ronda #" << numeroRonda << endl << endl;
        cout << "\t" "---------------------------------------" << endl << endl;

        //FOR PARA REALIZAR LOS 3 LANZAMIENTOS Y CALCULAR LOS PUNTOS
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

            //REALIZA LA TIRADA DE DADOS Y ASIGNA VALORES ALEATORIOS A LOS 6 DADOS

            ingresarDadosManuales(vDados);

            realizarTiradaSimulacion(vDados, 6, 5, 6);


            //CONDICIONES DE PUNTOS
            verificarSexteto(vDados, cantDados, haySexteto, sonIguales, puntajeParcial);

            verificarEscalera(vDados, hayEscalera, puntajeParcial);

            //CORTE DEL LANZAMIENTO CUANDO SE TIRA SEXTETO6 O ESCALERA
            if(haySexteto == false && hayEscalera == false)
            {
                verificarSumaDados(vDados, cantDados, puntajeParcial);
            }

            //ACUMULAR LOS PUNTOS DE CADA LANZAMIENTO Y LE ASIGNO A LA VARIABLE EN LA POSICION j
            //EL PUNTAJE PARCIAL QUE RESULTO DE EL PROCESAMIENTO DE LAS CONDICIONES
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

        //REINICIA EL CONTADOR DE LANZAMIENTOS POR FUERA DEL FOR PARA LA PRIXIMA RONDA
        numeroLanzamiento = 0;

        //EN puntajeRonda SE LE ASIGNA EL VALOR QUE RETORNA DE LA FUNCION. EN LA FUNCION SE BUSCA EL MAYOR PUNTAJE DE LOS 3 LANZAMIENTOS. SI SALE
        //SEXTETO6, SE REINICIA EL PUNTAJE TOTAL.
        puntajeTotal += puntajeRonda; ///cambiar variable a mayor puntaje

        system("cls");
        cout<<endl;
        cout<<endl;
        cout << "\t" "---------------------------------------" << endl << endl;
        cout << "\t" "RONDA #" << numeroRonda << endl;
        cout << "\t" "NOMBRE: " << nombre << endl << endl;
        cout << "\t" "PUNTAJE TOTAL: " << puntajeTotal << endl << endl;
        cout << "\t" "---------------------------------------" << endl << endl;
        system("pause");

    }
    while(puntajeTotal < 100);  //TOTAL PARTIDA

    // ACUMULA LOS PUNTAJES Y SUS NOMBRES DE CADA JUGADOR
    for (int v = 0; v < nPartida; v++)
    {
        if (vPuntajes[v] == 0)
        {
            vPuntajes[v] = puntajeTotal;
            vNombre[v] = nombre;
        }
    }
    nPartida++;
    system("cls");
    cout << "\t" "---------------------------------------" << endl << endl;
    cout << "\t" "   El puntaje total es: " << puntajeTotal << " puntos" << endl << endl;
    cout << "\t" "       Cantidad de rondas: " << numeroRonda << endl << endl;
    cout << "\t" "       Nombre del ganador: " << nombre << endl << endl;
    cout << "\t" "---------------------------------------" << endl << endl;
    system("pause");
    system("cls");
}


