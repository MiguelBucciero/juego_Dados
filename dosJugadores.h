#pragma once
void modo_Dos_Jugador();

void modo_Simulacion();

int tirarDado();

int contarDadosIguales(int vDados[], const int cantDados, bool &sonIguales);

void verificarSexteto(int vDados[], const int cantDados, bool &haySexteto, bool &sonIguales, int &puntajeParcial);

void verificarEscalera(int vDados[], bool &hayEscalera, int &puntajeParcial);

void verificarSumaDados(int vDados[], const int cantDados, int &puntajeParcial);

void lanzarDados(int vDados[]);

void dibujardado(int vDados[], int posicion);

void ingresarDadosManuales(int vDados[]);

void puntuacionMasAlta(int vPuntaje[], std::string vNombre[]);

void subMenuRanking();

void imprimirDados(int dados[],int posicion, int posx, int posy);
void mostrarDados2(int dados[], int numDados);
void realizarTirada(int dados[], int numDados, int posx, int posy);
