/* 35.Crea un programa que gestiona el capital físico de un banco. El banco
 partirá con un capital de 500,000€. A cada ronda se le otorga al jugador
 200,000€ o si el capital es menor, el que haya actualmente. Al inicio de cada
 ronda el jugador obtendrá 100,000€ de forma pasiva. Dispone de 10 días
 para alcanzar un capital de 1,500,000€.

 El jugador deberá de repartir ese dinero entre seguridad, distribución a
 oficinas e inversión de riesgo pudiendo no gastar dinero en alguna de ellas:
 
    - El dinero de inversión de riesgo al final de la ronda tiene un 15% de
     probabilidades de triplicarse, un 50% de mantenerse y un 35% de
     perderse.

     - El banco debe disponer de suficiente efectivo en cada ronda para
     distribuirlo en sus oficinas. La cantidad necesaria a cada ronda es
     aleatoria pero se encontrara limitado en un rango de (20,000€
    100,000€). El dinero final real necesario se perderá, pero se
     devolverá al capital total el restante. Si la distribución en oficinas no
     tiene para cubrir las necesidades de la ronda el banco perderá
     20,000€ + un 5% de lo que disponga en sus arcas.

     - Inicialmente el banco tiene un 75% de evitar un fallo de seguridad,
     tras cada ronda este % se reduce en un 5%, si sucede un fallo de
     seguridad el capital físico del banco recibirá una penalización en sus
     arcas del mismo % que falte para alcanzar el 100% de seguridad. Es
     decir, si el jugador empieza la ronda con un 70% de seguridad y falla
     perderá un 30% de su capital total. Cada 10.000€ se incrementa en
     un 1%la seguridad */

#include <iostream>
#include <time.h>
#include <Windows.h>

void main() {
    int capitalActual = 500000, contadorDias = 0, capitalUsuarioRondaActual = 0, fondosReservados = 0, dineroInversionRiesgo = 0, fondoRiesgo = 0, seguridadMaxima = 100;
    float seguridadActual = 0.75;
    char opcionElegida;
    bool gastado1 = false, gastado2 = false, gastado3 = false;

    std::cout << "Bienvenido al juego de la direccion de banca." << std::endl;
    std::cout << "En este juego se te dara un dinero, 200000 euros en caso de que se dispongan al principio de cada ronda o el dinero disponible en caso de que sea menor." << std::endl;
    std::cout << "Ademas, se te daran 100000 euros de manera pasiva al inicio de cada ronda." << std::endl;
    std::cout << "Debes usar este dinero para varios propositos:" << std::endl;
    std::cout << "\t" << "Invertir ese dinero en riesgo (lo que puede hacer que ganes dinero mas rapido o que lo pierdas)." << std::endl;
    std::cout << "\t" << "Mejorar la seguridad del banco, de esta manera evitaras perder mucho capital (el mismo porcentaje que tengas de tener un fallo de seguridad). Por cada 10000 euros invertidos mejoraras en un 1% la seguridad de tu banco. Cuidado porque cada ronda perderas un 5% de seguridad." << std::endl;
    std::cout << "\t" << "Distrubuir dinero entre las oficinas. Para evitar las penalizaciones debes invertir en la reserva de fondos para pagar los gastos de oficinas que variaran aleatoriamente entre 20000 y 100000 euros. Ten en cuenta que el hecho de no poder pagar esta cantidad implicara la perdida de 20000 euros mas el 5% del capital actual del banco." << std::endl;

    while (capitalActual < 1500000 && contadorDias < 10)
    {

        std::cout << std::endl << "COMIENZA LA RONDA: " << contadorDias + 1 << std::endl;
        
        if (capitalActual <= 0)
        {
            break;
        }
        gastado1 = false;
        gastado2 = false;
        gastado3 = false;

        // Le damos al usuario el capital que le corresponde por ronda del banco.
        if (capitalActual >= 200000)
        {
            capitalUsuarioRondaActual += 200000;
            capitalActual -= 200000;
        }
        else
        {
            capitalUsuarioRondaActual += capitalActual;
            capitalActual -= capitalActual;
        }

        // Le damos el capital pasivo al usuario.
        capitalUsuarioRondaActual += 100000;

        do
        {
            std::cout << "Con el dinero actual que tienes (" << capitalUsuarioRondaActual << " euros) puedes repartirlo entre (puedes no gastar en alguna):" << std::endl;
            std::cout << "\t" << "1) Inversion de riesgo." << std::endl;
            std::cout << "\t" << "2) Seguridad." << std::endl;
            std::cout << "\t" << "3) Distribucion a oficinas." << std::endl;
            std::cout << "\t" << "Cualquier otra tecla) No hacer nada mas." << std::endl;
            std::cout << "\t" << "Elija una opcion: ";
            std::cin >> opcionElegida;

            // Mensaje imprimido en caso de que el usuario no gaste en ninguna opcion.
            if ((!gastado1 && !gastado2 && !gastado3) && (opcionElegida != '1' && opcionElegida != '2' && opcionElegida != '3'))
            {
                std::cout << "No puedes no gastar en ninguna." << std::endl;
            }

            // Determinamos los casos posibles con un switch.
            switch (opcionElegida)
            {
            case '1':

                do
                {
                    std::cout << "Elija la cantidad de dinero que desea depositar en la inversion de riesgo: ";
                    std::cin >> dineroInversionRiesgo;

                    if (dineroInversionRiesgo <= 0) 
                    {
                        std::cout << "No puedes introducir valores negativos o nulos." << std::endl;
                    }
                    else if (dineroInversionRiesgo > capitalUsuarioRondaActual)
                    {
                        std::cout << "No puedes invertir tanto dinero en riesgo, solo dispones de " << capitalUsuarioRondaActual << " euros." << std::endl;
                    }
                    
                } while (dineroInversionRiesgo <= 0 || dineroInversionRiesgo > capitalUsuarioRondaActual);
                
                capitalUsuarioRondaActual -= dineroInversionRiesgo;

                fondoRiesgo += dineroInversionRiesgo;

                gastado1 = true;
                break;
            case '2':



                break;
            case '3':



                break;
            default:
                if (gastado1 || gastado2 || gastado3)
                {
                    std::cout << "Saliendo..." << std::endl;
                    Sleep(1000);
                }
                
                break;
            }

            // Control para que el usuario gaste al menos en alguna opcion.
        } while (!(gastado1 || gastado2 || gastado3) || (opcionElegida == '1' || opcionElegida == '2' || opcionElegida == '3'));

        contadorDias++;
    }

    if (capitalActual >= 1500000)
    {
        std::cout << "Enhorabuena, has ganado el juego!" << std::endl;
    }
    else if (capitalActual <= 0)
    {
        std::cout << "Has perdido todo el dinero." << std::endl;
    }
    else
    {
        std::cout << "Han pasado 10 dias y no has sido capaz de recaudar el capital necesario. Has perdido." << std::endl;
    }
}