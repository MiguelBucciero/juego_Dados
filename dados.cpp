#include <iostream>
#include "rlutil.h"
#include "dados.h"

using namespace std;


void dibujarDado(int dados[],int posicion, int posx, int posy, int color, int colorPoint)
{

    rlutil::setColor(color);
    dibujarCuadrado(posx,posy);

    rlutil::setColor(colorPoint);
    rlutil::setBackgroundColor(color);
    dibujarPuntos(dados, posicion, posx, posy);

    rlutil::setColor(rlutil::DARKGREY);
    rlutil::setBackgroundColor(rlutil::BLACK);
    dibujarSombra(posx, posy);
}

void dibujarPuntos(int dados[],int posicion, int posx,int posy)
{

    switch(dados[posicion])
    {
    case 1:
        rlutil::locate(posx+3,posy+1);
        cout<<(char)254;
        break;
    case 2:
        if(rand()%2)
        {
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
        }
        else
        {
            rlutil::locate(posx+1,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+5,posy);
            cout<<(char) 220;
        }
        break;
    case 3:
        rlutil::locate(posx+3,posy+1);
        cout<<(char)254;
        if(rand()%2)
        {
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
        }
        else
        {
            rlutil::locate(posx+1,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+5,posy);
            cout<<(char) 220;
        }
        break;
    case 4:
        rlutil::locate(posx+1,posy);
        cout<<(char) 220;
        rlutil::locate(posx+5,posy);
        cout<<(char) 220;
        rlutil::locate(posx+5,posy+2);
        cout<<(char) 223;
        rlutil::locate(posx+1,posy+2);
        cout<<(char) 223;
        break;
    case 5:
        rlutil::locate(posx+3,posy+1);
        cout<<(char)254;
        rlutil::locate(posx+1,posy);
        cout<<(char) 220;
        rlutil::locate(posx+5,posy);
        cout<<(char) 220;
        rlutil::locate(posx+5,posy+2);
        cout<<(char) 223;
        rlutil::locate(posx+1,posy+2);
        cout<<(char) 223;
        break;
    case 6:
        rlutil::locate(posx+1,posy);
        cout<<(char) 220;
        rlutil::locate(posx+5,posy);
        cout<<(char) 220;
        rlutil::locate(posx+1,posy+2);
        cout<<(char) 223;
        rlutil::locate(posx+5,posy+2);
        cout<<(char) 223;
        if(rand()%2)
        {
            rlutil::locate(posx+3,posy);
            cout<<(char) 220;
            rlutil::locate(posx+3,posy+2);
            cout<<(char) 223;

        }
        else
        {
            rlutil::locate(posx+1,posy+1);
            cout<<(char)254;
            rlutil::locate(posx+5,posy+1);
            cout<<(char)254;
        }
        break;
    }
}

void dibujarSombra(int posx, int posy)
{
    for(int y=posy; y<=posy+2; y++)
    {
        rlutil::locate(posx+7,y);
        if(y==posy)
        {
            cout<< (char) 220;
        }
        else
        {
            cout<< (char) 219;
        }
    }
    for(int x=posx+1; x<=posx+7; x++)
    {
        rlutil::locate(x,posy+3);
        cout<< (char) 223;
    }
}

void dibujarCuadrado(int posx, int posy)
{
    for(int x=posx; x<=posx+6; x++)
    {
        for(int y=posy; y<=posy+2; y++)
        {
            rlutil::locate(x,y);
            cout<< (char) 219;
        }
    }
}
