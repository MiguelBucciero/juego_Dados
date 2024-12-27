#include <iostream>
#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "rlutil.h"

using namespace std;

//FUNCION QUE ASIGNA VALORES ALEATORIOS A LOS DADOS
int tirarDado()
{
    return rand() % 6 + 1;
}
//FUNCION QUE IMPRIME LOS DADOS POR PANTALLA
void imprimirDados(int vDados[],int posicion, int posx, int posy)
{
    for(int i=0; i<15; i++)
    {
        dibujarDado(vDados,posicion,posx, posy, rand()%16,15);
        rlutil::msleep(10);
    }
    dibujarDado(vDados,posicion, posx, posy,15,0);
}

// FUNCION PARA TIRAR DADOS DE FORMA ALEATORIA E IMPRIMIRLO POR PANTALLA
void realizarTirada(int vDados[], int numDados, int posx, int posy)
{
    for (int i = 0; i < numDados; i++)
    {
        vDados[i] = tirarDado();
        imprimirDados(vDados,i,(i+1)*10,posy);
    }
}

//CUENTA LA CANTIDAD DE DADOS IGUALES Y RETORNA EL VALOR DEL DADO SI HAY 6 IGUALES
int contarDadosIguales(int vDados[], const int cantDados, bool &sonIguales)
{
    int x;
    int nroDado = 0;
    int dados_iguales = 1;

    for(x=0; x<6; x++)
    {
        if(nroDado == 0)
        {
            nroDado = vDados[x];
        }
        else if(vDados[x] == nroDado)
        {
            dados_iguales++;
        }
    }

    if(dados_iguales == 6)
    {
        sonIguales = true;
        return nroDado;
    }
    return 0;
}

//VERIFICA QUE TIPO DE SEXTETO ES Y MODIFICA EL PUNTAJE SEGUN LAS REGLAS
void verificarSexteto(int vDados[], const int cantDados, bool &haySexteto, bool &sonIguales, int &puntajeParcial)
{
    int dadoRepetido;
    dadoRepetido = contarDadosIguales(vDados, cantDados, sonIguales);

    if(sonIguales == true)
    {
        haySexteto = true;
        if(dadoRepetido != 6)
        {
            //cout << "SEXTETO X - EL VALOR DE LOS DADOS SE MULTIPLICA X 10" << endl << endl;
            puntajeParcial = dadoRepetido * 10;
        }
    }
}

//ESCALERA
void verificarEscalera(int vDados[], bool &hayEscalera, int &puntajeParcial)
{

    int vDados2[6];

    for(int n=0; n<6; n++)
    {
        vDados2[n] = vDados[n];
    }
    //METODO BURBUJA

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6-1; j++)
        {
            if(vDados[j] > vDados[j+1])
            {
                int aux = vDados[j+1];
                vDados[j+1] = vDados[j];
                vDados[j] = aux;
            }
        }
    }
    if(vDados2[0] == 1 && vDados2[1] == 2 && vDados2[2] == 3 && vDados2[3] == 4 && vDados2[4] == 5 && vDados2[5] == 6)
    {
        hayEscalera=true;
        //cout << "ESCALERA - GANASTE LA PARTIDA" << endl << endl;
        puntajeParcial = 100;
    }
}

//SUMA DE DADOS
void verificarSumaDados(int vDados[], const int cantDados, int &puntajeParcial)
{
    //cout << "SUMA DE DADOS" << endl << endl;
    puntajeParcial += vDados[0] + vDados[1] + vDados[2] + vDados[3] + vDados[4] + vDados[5];

}


//MODO UN JUGADOR
void modo_Un_Jugador(int vPuntajes[],string vNombre[],int& nPartida)
{

    const int cantDados = 6;
    int vDados[cantDados];
    int numeroRonda = 0, numeroLanzamiento = 0, puntajeTotal = 0;
    string nombre;
    bool bandera2=true;

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

            realizarTirada(vDados, 6, 5, 2);


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

//SUB MENU PUNTUACION MAS ALTA
void subMenuRanking(int vPuntajes[],string vNombre[],int nPartida)
{
    int opcion;
    do
    {

        cout << "\t" "---------------------------------------" << endl << endl;
        cout << "\t" "       REGISTROS DE PUNTUACIONES MAS ALTAS " << endl << endl;
        cout << "\t" "       INGRESE:    " << endl << endl;
        cout << "\t" "       1- PARA ENTRAR  "  << endl << endl;
        cout << "\t" "       0- PARA SALIR  "  << endl << endl;
        cout << "\t" "---------------------------------------" << endl << endl;
        cout << "\t" "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            puntuacionMasAlta(vPuntajes, vNombre, nPartida);
            break;
        case 0:
            cout <<" VOLVIENDO AL MENU PRINCIPAL " << endl;
            break;

        default:
            cout << "OPCION NO VALIDA..." << endl;
            break;
        }
    }
    while(opcion != 0);
}

//FUNCION PARA ORDENAR LAS PUNTUACIONES DE MAYOR A MENOR
//CON EL METODO BURBUJA Y LUEGO IMPRIMIRLO POR PANTALLA
void puntuacionMasAlta(int vPuntajes[], string vNombre[], int nPartida)
{
    int auxPuntaje;
    string auxNombre;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(vPuntajes[j] < vPuntajes[j+1])
            {
                auxPuntaje = vPuntajes[j];
                vPuntajes[j] = vPuntajes[j+1];
                vPuntajes[j+1] = auxPuntaje;
                auxNombre = vNombre[j];
                vNombre[j] = vNombre[j+1];
                vNombre[j+1 ]= auxNombre;
            }
        }
    }

    // MUESTRA LOS VECTORES
    cout <<  "\t" "\t" "**************** RANKING  **************" << endl << endl;
    cout <<  "\t" "\t" "********** PUNTAJES MAS ALTOS **********" << endl;
    cout << "\t" "\t"  "****************************************" << endl << endl;
    for(int x=0; x<nPartida-1; x++)
    {
        cout << "\t" "\t" "El puntaje es: " << vPuntajes[x] << " nombre del jugador: " << vNombre[x] << endl;
        cout<<endl;
    }
    cout<<endl;
    system("pause");
    system("cls");
}

