#pragma once
int tirarDado();
void imprimirDados(int dados[],int posicion, int posx, int posy);
void realizarTirada(int dados[], int numDados, int posx, int posy);
int contarDadosIguales(int vDados[], const int cantDados, bool &sonIguales);
void verificarSexteto(int vDados[], const int cantDados, bool &haySexteto, bool &sonIguales, int &puntajeParcial);
void verificarEscalera(int vDados[], bool &hayEscalera, int &puntajeParcial);
void verificarSumaDados(int vDados[], const int cantDados, int &puntajeParcial);
void modo_Un_Jugador(int vPuntajes[],std::string vNombre[],int& nPartida);
void subMenuRanking(int vPuntajes[],std::string vNombre[], int nPartida);
void puntuacionMasAlta(int vPuntajes[], std::string vNombre[],int nPartida);
void modo_Dos_Jugador(int vPuntajes[],std::string vNombre[],int& nPartida);
void modo_Simulacion(int vPuntajes[],std::string vNombre[],int& nPartida);
void ingresarDadosManuales(int vDados[]);
