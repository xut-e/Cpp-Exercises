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
     int idObjeto; // -1 es sin objeto
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
 
 std::vector<int> inicializarCasillasObjetos() {
     return {3, 13, 23, 33, 43};
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
         {1, 1, false, -1},
         {2, 1, false, -1}
     };
 }
 
 std::vector<ObjetosAleatorios> inicializarObjetosAleatorios() {
     return {
         {1, "Dado adicional: Tira dos dados esta ronda."},
         {2, "Retrocede enemigo: Tira un dado para ello (no aplican casillas especiales)"},
         {3, "Avance manual: Avanza entre 1 y 3 casillas."}
     };
 }
 
 bool objetoAleatorio(int idJugador, std::vector<Jugadores>& jugadores, std::vector<ObjetosAleatorios> listaObjetos) {
     int opcion;
 
     if (jugadores[idJugador].tieneObjeto)
     {
         if (jugadores[idJugador].idObjeto == -1)
         {
             return false;
         }
 
         std::cout << "Posees un objeto: " << listaObjetos[jugadores[idJugador].idObjeto].breveDescripcion << std::endl;
         std::cout << "Deseas utilizarlo?" << std::endl;
         std::cout << "\t" << "1) Si." << std::endl;
         std::cout << "\t" << "2) No." << std::endl;
         std::cout << "Elige una opcion: " << std::endl;
         do
         {
             std::cin >> opcion;
         } while (opcion != 1 && opcion != 2);
 
         if (opcion == 1)
         {
             return true;
         }
     }
 
     return false;
 }
 
 int tirarDado() {
 
 }
 
 int objetoUno() {
     int sumaTotal;
 
     sumaTotal += tirarDado();
     sumaTotal += tirarDado();
 
     return sumaTotal;
 }
 
 int objetoDos(int idJugadorActual) {
 
     return tirarDado();
 }
 
 int objetoTres() {
     int opcion;
 
     std::cout << "Puedes decidir si avanzar, de manera manual un total de 1, 2 o 3 casillas: ";
     do
     {
         std::cin >> opcion;
     } while (opcion < 1 || opcion > 3);
     
     return opcion;
 }
 
 
 
 void jugar() {
     srand(time(0));
 
     bool utilizarObjeto;
 
     std::vector<Jugadores> datosJugadores = inicializarJugadores();
 
     std::vector<CasillasConectadas> casillasTeletransporte = inicializarListaCasillasTeletransporte();
 
     std::vector<ObjetosAleatorios> listaObjetos =  inicializarObjetosAleatorios();
 
     std::vector<int> liscaCasillasObjetos = inicializarCasillasObjetos();
 
     while (!( datosJugadores[JUGADOR_1].posicion == MAX_CASILLAS || datosJugadores[JUGADOR_2].posicion == MAX_CASILLAS))
     {
         for (int i = 0; i < JUGADORES; i++)
         {
             int avanzar;
 
             std::cout << "TURNO DEL JUGADOR " << i + 1;
 
             mostrarTablero(datosJugadores);
 
             utilizarObjeto = objetoAleatorio(i, datosJugadores, listaObjetos);
 
             if (utilizarObjeto)
             {
                 if (datosJugadores[i].idObjeto == 1)
                 {
                     avanzar = objetoUno();
                 }
                 else if (datosJugadores[i].idObjeto == 2)
                 {
                     int enemigo;
 
                     if (datosJugadores[i].identificador == JUGADOR_1)
                     {
                         enemigo = JUGADOR_2;
                     }
                     else if (datosJugadores[i].identificador == JUGADOR_2)
                     {
                         enemigo = JUGADOR_1;
                     }
 
                     int retrocederEnemigo = objetoDos(datosJugadores[enemigo].identificador);
 
                     avanzar = tirarDado();
                 }
                 else if (datosJugadores[i].idObjeto == 3)
                 {
                     avanzar = objetoTres();
                 }
             }
 
             avanzar = tirarDado();
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