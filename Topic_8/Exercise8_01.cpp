/* 1.         ------Crear un juego de preguntas:------
 Hará 10 preguntas. Para cada pregunta se mostraran 4 posibles respuestas.
 Si responde incorrectamente se le indicará la respuesta correcta.
 Una respuesta correcta suma +1, una incorrecta resta-1.
 Hay rachas de correcto e incorrecto. Ejemplo, si responde 2 preguntas
 seguidas bien la primera da +1 y la segunda +2. Llegando a una puntuación
 máxima.
 Al finalizar si la nota es inferior a 20 se le hará una última pregunta para
 aprobar.
 Al final se le informa de que preguntas ha hecho bien, cuales mal y mayor
 racha de respuestas. */

 #include <iostream>
 #include <string>
 #include <vector>
 
 struct Pregunta {
     std::string enunciado;
 
     std::vector<std::string> opciones;
 
     int respuestaCorrecta;
 };
 
 std::vector<Pregunta> inicializarPreguntas() {
     return {
         {"Cual es la capital de Japon?", {"1) Pekin", "2) Tokio", "3) Seul", "4) Bangkok"}, 2},
         {"Cuantos planetas hay en el Sistema Solar?", {"1) Ocho", "2) Nueve", "3) Siete", "4) Diez"}, 1},
         {"Quien pinto la Mona Lisa?", {"1) Pablo Picasso", "2) Vincent van Gogh", "3) Leonardo da Vinci", "4) Rembrandt"}, 3},
         {"Cual es el oceano mas grande del mundo?", {"1) Atlantico", "2) Indico", "3) Pacifico", "4) Artico"}, 3},
         {"En que continente se encuentra Egipto?", {"1) Europa", "2) Asia", "3) Africa", "4) America"}, 3},
         {"Cuanto es 5 x 6?", {"1) Treinta", "2) Veinticinco", "3) Treinta y cinco", "4) Cuarenta"}, 1},
         {"Que pais tiene forma de bota?", {"1) Espanya", "2) Italia", "3) Francia", "4) Alemania"}, 2},
         {"Cual es el elemento quimico representado por 'O'?", {"1) Oxigeno", "2) Oro", "3) Osmio", "4) Oxalato"}, 1},
         {"Cual es el animal terrestre mas rapido?", {"1) Tigre", "2) Leon", "3) Leopardo", "4) Guepardo"}, 4},
         {"Cual es la moneda oficial de China?", {"1) Yen", "2) Yuan", "3) Won", "4) Peso"}, 2}
     };
 }
 
 int hacerPregunta(Pregunta p, int& racha) {
     std::cout << p.enunciado << std::endl;
     int respuestaUsuario;
 
     for (std::string opcion : p.opciones)
     {
         std::cout << opcion << std::endl;
     }
 
     std::cout << "Tu respuesta: ";
     std::cin >> respuestaUsuario;
 
     system("cls");
 
     if (respuestaUsuario == p.respuestaCorrecta)
     {
         racha++;
         std::cout << "Correcto!" << std::endl;
         return racha;
     }
     else
     {
         std::cout << "Incorrecto! La respuesta correcta era: " << p.opciones[p.respuestaCorrecta - 1]  << std::endl;
         racha = 0;
         return -1;
     }
 }
 
 bool preguntaExtra() {
     Pregunta extra = { "Cuantos continentes hay en el mundo?", {"1) Cinco", "2) Seis", "3) Siete", "4) Ocho"}, 3 };
     int rachaExtra = 0;
 
     std::cout << "Ultima oportunidad para aprobar!" << std::endl;
     
     return hacerPregunta(extra, rachaExtra) > 0;
 }
 
 void jugar() {
     std::vector<Pregunta> preguntas = inicializarPreguntas();
     std::vector<bool> resultados;
 
     int puntuacion = 0, racha = 0, maxRacha = 0;
     
     std::cout << "Bienvenido al juego de las preguntas!" << std::endl << std::endl;
 
     for (Pregunta p : preguntas)
     {
         int puntos = hacerPregunta(p, racha);
         puntuacion += puntos;
 
         resultados.push_back(puntos > 0);
 
         if (racha > maxRacha)
         {
             maxRacha = racha;
         }
 
         std::cout << "Puntuacion actual: " << puntuacion << std::endl;
     }
 
     if (puntuacion < 20 && preguntaExtra())
     {
         puntuacion += 5;
     }
 
     system("cls");
 
     std::cout << "------------RESUMEN DE LA PARTIDA------------" << std::endl;
 
     std::cout << "Correctas: " << std::count(resultados.begin(), resultados.end(), true) << std::endl;
     std::cout << "Erroneas: " << std::count(resultados.begin(), resultados.end(), false) << std::endl;
     std::cout << "Mayor racha: " << maxRacha << std::endl;
     std::cout << "Puntuacion final: " << puntuacion << std::endl;
 
     if (puntuacion > 20)
     {
         std::cout << "Enhorabuena! Has aprobado." << std::endl;
     }
     else
     {
         std::cout << "Que pena! Has suspendido." << std::endl;
     }
 }
 
 int main() {
     jugar();
 
     return 0;
 }