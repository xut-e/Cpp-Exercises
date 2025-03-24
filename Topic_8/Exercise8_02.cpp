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
 #define ESPERA_DESPUES_DE_DADO 500
 #define ESPERA_DESPUES_DE_TELETRANSPORTE 2000
 
 #include <iostream>
 #include <time.h>
 #include <vector>
 #include <Windows.h>
 
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
         {7, 12},
         {19, 24},
         {31, 40}
     };
 }
 
 std::vector<int> inicializarCasillasObjetos() {
     return {3, 13, 23, 33, 43};
 }
 
 void mostrarTablero(std::vector<Jugadores>& jugadores, time_t idTurno) {
 
     system("cls");
 
     std::vector<std::string> tablero;
 
     std::cout << "TURNO DEL JUGADOR " << idTurno + 1 << std::endl;
 
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
         {0, "Dado adicional: Tira dos dados esta ronda."},
         {1, "Retrocede enemigo: Tira un dado para ello (no aplican casillas especiales)"},
         {2, "Avance manual: Avanza entre 1 y 3 casillas."}
     };
 }
 
 bool objetoAleatorio(int idJugador, std::vector<Jugadores>& jugadores, std::vector<ObjetosAleatorios> listaObjetos) {
     int opcion;
 
     if (jugadores[idJugador].tieneObjeto && jugadores[idJugador].idObjeto >= 0)
     {
         std::cout << "Posees un objeto: " << listaObjetos[jugadores[idJugador].idObjeto].breveDescripcion << std::endl;
         std::cout << "Deseas utilizarlo?" << std::endl;
         std::cout << "\t" << "1) Si." << std::endl;
         std::cout << "\t" << "2) No." << std::endl;
         std::cout << "Elige una opcion: ";
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
     return rand() % 6 + 1;
 }
 
 int objetoUno() {
     int dadoExtra;
 
     dadoExtra = tirarDado();
 
     return dadoExtra;
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
 
 std::vector<Jugadores> avanzar(int idJugador, std::vector<Jugadores>& datosJugadores) {
 
     std::cout << "Tira el dado!" << std::endl;
     system("pause");
 
     int numeroAvanzar = tirarDado();
 
     std::cout << "Ha salido un " << numeroAvanzar << "!" << std::endl;
     Sleep(ESPERA_DESPUES_DE_DADO);
 
     datosJugadores[idJugador].posicion += numeroAvanzar;
 
     return datosJugadores;
 }
 
 std::vector<Jugadores> retrocederEnemigo(int idEnemigo, std::vector<Jugadores>& datosJugadores) {
 
     std::cout << "Tira el dado!" << std::endl;
     system("pause");
 
     int numeroRetrocederEnemigo = tirarDado();
     
     datosJugadores[idEnemigo].posicion -= numeroRetrocederEnemigo;
 
     if (datosJugadores[idEnemigo].posicion < 1)
     {
         datosJugadores[idEnemigo].posicion = 1;
     }
 
     std::cout << "Ha salido un " << numeroRetrocederEnemigo << ". Tu enemigo retrocede hasta la casilla: " << datosJugadores[idEnemigo].posicion << std::endl;
 
     return datosJugadores;
 }
 
 bool comprobarGanador(std::vector<Jugadores> datosJugadores) {
     if (datosJugadores[JUGADOR_1].posicion >= MAX_CASILLAS || datosJugadores[JUGADOR_2].posicion >= MAX_CASILLAS)
     {
         return true;
     }
     else
     {
         return false;
     }
     
 }
 
 void jugar() {
     srand(time(0));
 
     bool utilizarObjeto;
 
     std::vector<Jugadores> datosJugadores = inicializarJugadores();
 
     std::vector<CasillasConectadas> casillasTeletransporte = inicializarListaCasillasTeletransporte();
 
     std::vector<ObjetosAleatorios> listaObjetos =  inicializarObjetosAleatorios();
 
     std::vector<int> liscaCasillasObjetos = inicializarCasillasObjetos();
 
     while (!(datosJugadores[JUGADOR_1].posicion >= MAX_CASILLAS || datosJugadores[JUGADOR_2].posicion >= MAX_CASILLAS))
     {
         for (int i = 0; i < JUGADORES; i++)
         {
             int numeroAvanzar;
 
             std::cout << "TURNO DEL JUGADOR " << i + 1 << std::endl;
 
             mostrarTablero(datosJugadores, i);
 
             utilizarObjeto = objetoAleatorio(i, datosJugadores, listaObjetos);
 
             if (utilizarObjeto)
             {
                 if (datosJugadores[i].idObjeto == 0)
                 {
                     numeroAvanzar = objetoUno();
                     
                     std::cout << "Tu objeto te avanza " << numeroAvanzar << " casillas." << std::endl;
                     datosJugadores[i].posicion += numeroAvanzar; 
                     Sleep(ESPERA_DESPUES_DE_TELETRANSPORTE);
                     mostrarTablero(datosJugadores, i);
                 }
                 else if (datosJugadores[i].idObjeto == 1)
                 {
                     int enemigo = (i == JUGADOR_1) ? JUGADOR_2 : JUGADOR_1;
 
                     retrocederEnemigo(enemigo, datosJugadores);
 
                     Sleep(ESPERA_DESPUES_DE_TELETRANSPORTE);
                     mostrarTablero(datosJugadores, i);
 
                     avanzar(i, datosJugadores);
 
                 }
                 else if (datosJugadores[i].idObjeto == 2)
                 {
                     numeroAvanzar = objetoTres();
 
                     std::cout << "Has avanzado " << numeroAvanzar << " casillas." << std::endl;
                     datosJugadores[i].posicion += numeroAvanzar;
 
                     Sleep(ESPERA_DESPUES_DE_TELETRANSPORTE);
                     mostrarTablero(datosJugadores, i);
                 }
 
                 datosJugadores[i].tieneObjeto = false;
                 datosJugadores[i].idObjeto = -1;
             }
             std::cout << "Tira el dado!" << std::endl;
             system("pause");
             numeroAvanzar = tirarDado();
 
             std::cout << "Ha salido un " << numeroAvanzar << "!" << std::endl;
             Sleep(ESPERA_DESPUES_DE_DADO);
             datosJugadores[i].posicion += numeroAvanzar;
             mostrarTablero(datosJugadores, i);
 
             if (datosJugadores[i].posicion % 5 == 0 && datosJugadores[i].posicion != MAX_CASILLAS)
             {
                 std::cout << "Tienes un turno extra." << std::endl;
                 std::cout << "Tira el dado!" << std::endl;
                 system("pause");
 
                 numeroAvanzar = tirarDado();
 
                 std::cout << "Ha salido un " << numeroAvanzar << "!" << std::endl;
                 Sleep(ESPERA_DESPUES_DE_DADO);
                 datosJugadores[i].posicion += numeroAvanzar;
                 mostrarTablero(datosJugadores, i);
             }
 
             for (size_t j = 0; j < liscaCasillasObjetos.size(); j++)
             {
                 if (datosJugadores[i].posicion == liscaCasillasObjetos[j] && (!datosJugadores[i].tieneObjeto && datosJugadores[i].idObjeto == -1))
                 {
                     int objetoEscogido = rand() % listaObjetos.size();
 
                     std::cout << "Te has encontrado con un objeto random, te ha tocado: " << listaObjetos[objetoEscogido].breveDescripcion << std::endl;
 
                     datosJugadores[i].tieneObjeto = true;
                     datosJugadores[i].idObjeto = objetoEscogido;
                     break;
                 }
             }
             
             for (size_t j = 0; j < casillasTeletransporte.size(); j++)
             {
                 if (datosJugadores[i].posicion == casillasTeletransporte[j].casilla1)
                 {
                     std::cout << "Has caido en la casilla " << casillasTeletransporte[j].casilla1 << ". Avanzas hasta la casilla " << casillasTeletransporte[j].casilla2 << std::endl;
                     Sleep(ESPERA_DESPUES_DE_TELETRANSPORTE);
                     datosJugadores[i].posicion = casillasTeletransporte[j].casilla2;
                     mostrarTablero(datosJugadores, i);
                     break;
                 }
                 else if (datosJugadores[i].posicion == casillasTeletransporte[j].casilla2)
                 {
                     std::cout << "Has caido en la casilla " << casillasTeletransporte[j].casilla2 << ". Retrocedes hasta la casilla " << casillasTeletransporte[j].casilla1 << std::endl;
                     Sleep(ESPERA_DESPUES_DE_TELETRANSPORTE);
                     datosJugadores[i].posicion = casillasTeletransporte[j].casilla1;
                     mostrarTablero(datosJugadores, i);
                     break;
                 }
             }
 
             if (comprobarGanador(datosJugadores))
             {
                 break;
             }
 
             std::cout << "Presiona cualquier tecla para avanzar de turno." << std::endl;
             system("pause");
             system("cls");
 
             
         }
     }
 
     if (datosJugadores[JUGADOR_1].posicion >= MAX_CASILLAS)
     {
         std::cout << "El jugador 1 gana!" << std::endl;
     }
     else if (datosJugadores[JUGADOR_2].posicion >= MAX_CASILLAS)
     {
         std::cout << "El jugador 2 gana!" << std::endl;
     }
 }
 
 int main() {
     jugar();
     return 0;
 }