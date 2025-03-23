/* 2 - Crea un juego de carreras por texto para dos jugadores:------
 Los jugadores deben recorrer 50 casillas.
 Cada turno lanzan un dado aleatorio entre 1 y 6.
 Las casillas múltiplos de 5 permiten volver a lanzar el dado.
 Las casillas 7 y 12, 19 y 24, 31 y 40 intercambiarán la posición del jugador
 con la casilla que conectan de forma bidireccional.
 Las casillas 3, 13, 23, 33 y 43 otorgaran un objeto aleatorio al jugador. Si lo
 tiene antes de lanzar el dado aparecerá un menú preguntando de usarlo (no
 se puede obtener un objeto si ya se tiene uno).
 Los objetos aleatorios son:
 ○ Dadoadicional: Tira 2 dados en vez de uno esa ronda.
 ○ Retrocede al enemigo: tira un dado que hará retroceder al rival (no
 aplica efecto de casilla).
 ○ Avanzar1-3 casilla: El jugador elige manualmente avanzar entre 1 y 3
 casillas y aplica el efecto de casilla si existe. */

 #define MIN_CASILLAS 1
 #define MAX_CASILLAS 50
 #define JUGADORES 2
 #define JUGADOR_1 0
 #define JUGADOR_2 1
 
 #include <iostream>
 #include <time.h>
 #include <vector>
 
 struct CasillasConectadas {
     const int casilla1;
     const int casilla2;
 };
 
 struct Jugadores {
     const int identificador;
     int posicion;
     bool tieneObjeto;
 };
 
 struct ObjetosAleatorios {
     int identificadorObjeto;
     std::string breveDescripcion;
 };
 
 std::vector<CasillasConectadas> inicializarListaCasillasTeletransporte() {
     return {
         {1, 12},
         {19, 24},
         {31, 40}
     };
 }
 
 void mostrarTablero(std::vector<Jugadores>& jugadores) {
 
     std::vector<std::string> tablero;
 
     for (int i = 0; i < JUGADORES; i++)
     {
         for (int j = 1; j <= MAX_CASILLAS; j++)
         {
             if (jugadores[i].posicion == j)
             {
                 std::cout << "[" << jugadores[i].identificador << "]";
 
             }
             else
             {
                 std::cout << "[ ]";
             }
         }
 
         std::cout << std::endl;
         
     }
 }
 
 std::vector<Jugadores> inicializarJugadores() {
     return {
         {1, 1, false},
         {2, 1, false}
     };
 }
 
 std::vector<ObjetosAleatorios> inicializarObjetosAleatorios() {
     return {
         {1, "Dado adicional: Tira dos dados esta ronda."},
         {2, "Retrocede enemigo: Tira un dado para ello (no aplican casillas especiales)"},
         {3, "Avance manual: Avanza entre 1 y 3 casillas."}
     };
 }
 
 void objetoAleatorio(int idJugador, std::vector<Jugadores>& jugadores) {
     if (jugadores[idJugador].tieneObjeto)
     {
         std::cout << "Posees un objeto, deseas utilizarlo?";
     }
 }
 
 void jugar() {
     srand(time(0));
 
     std::vector<Jugadores> datosJugadores = inicializarJugadores();
 
     std::vector<CasillasConectadas> casillasTeletransporte = inicializarListaCasillasTeletransporte();
 
     inicializarObjetosAleatorios();
 
     while (!( datosJugadores[JUGADOR_1].posicion == MAX_CASILLAS || datosJugadores[JUGADOR_2].posicion == MAX_CASILLAS))
     {
         for (int i = 0; i < JUGADORES; i++)
         {
             std::cout << "TURNO DEL JUGADOR " << i + 1;
 
             mostrarTablero(datosJugadores);
 
             objetoAleatorio(i, datosJugadores);
         }
     }
 
     if (datosJugadores[JUGADOR_1].posicion == MAX_CASILLAS)
     {
         std::cout << "El jugador 1 gana!" << std::endl;
     }
     else if (datosJugadores[JUGADOR_2].posicion == MAX_CASILLAS)
     {
         std::cout << "El jugador 2 gana!" << std::endl;
     }
 }
 
 int main() {
     jugar();
     return 0;
 }