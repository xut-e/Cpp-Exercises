/* 4- Crear juego ahorcado:----
El programa selecciona aleatoriamente una palabra de una lista predefinida.
 Muestra al jugador la longitud de la palabra.
 El jugador intenta adivinar una letra por turno.
 El jugador tiene un límite de intentos por palabra.
 Cuando le quedan 2 intentos se le revela una letra no mostrada. */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <time.h>
 
 
 std::vector<std::string> inicializarDiccionario() {
     return {"gato", "perro", "casa", "árbol", "sol", "luna", "montaña", "río", "coche", "avión", "computadora", "libro", "silla", "mesa", "ventana", "puerta", "jardín", "flor", "pelota", "camisa", "zapato", "reloj", "botella", "lámpara", "teléfono", "guitarra", "piano", "televisión", "espejo", "cuchara", "tenedor", "cuchillo", "plato", "vaso", "sombrero", "bufanda", "abrigo", "pantalón", "falda", "vestido", "calcetín", "bolsillo", "maleta", "billete", "moneda", "llave", "martillo", "tornillo", "clavo", "destornillador"};
 }
 
 std::string seleccionarPalabra(std::vector<std::string> listaPalabras) {
     int numeroAleatorio = rand() % (listaPalabras.size() + 1);
 
         std::string palabraSeleccionada = listaPalabras[numeroAleatorio];
 
         return palabraSeleccionada;
 }
 
 std::string palabraAAdivinarForma(std::string palabraAAdivinar) {
 
 }
 
 bool palabraAdivinada() {
     std::vector<char> formaPalabraAAdivinar;
     
 }
 
 void jugar(std::string palabraAAdivinar) {
     int intentos = 0;
 
     palabraAAdivinarForma(palabraAAdivinar);
 
     while (intentos < palabraAAdivinar.size() || !palabraAdivinada())
     {
         palabraAAdivinarForma(palabraAAdivinar);
         intentos++;
     }
     
 }
 
 int main() {
     srand(time(0));
 
     std::vector<std::string> palabras = inicializarDiccionario();
 
     std::string palabraSeleccionada = seleccionarPalabra(palabras);
 
     jugar(palabraSeleccionada);
 
     return 0;
 }