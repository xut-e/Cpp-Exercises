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
     un 1% la seguridad */

#include <iostream>
#include <time.h>
#include <Windows.h>

void main() {
    int capitalActual = 500000, contadorDias = 0, capitalUsuarioRondaActual = 0, fondoOficinas = 0, dineroInversionOficinas = 0, dineroInversionRiesgo = 0, fondoRiesgo = 0, seguridadMaxima = 100, riesgoMaximo = 100, fondoSeguridad = 0, dineroInversionSeguridad = 0, penalizacion = 20000;
    float seguridadActual = 0.75, posibilidadTriplicar = 0.15, posibilidadMantener = 0.5, posibilidadPerder = 0.35, porcentajePenalizacion = 0.05;
    char opcionElegida;
    bool gastado1 = false, gastado2 = false, gastado3 = false;

    srand(time(0));

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
        
        std::cout << "El capital actual del banco es de " << capitalActual << " euros." << std::endl;

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

        fondoRiesgo = 0;
        fondoSeguridad = 0;
        fondoOficinas = 0;

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
                    if (fondoRiesgo > 0)
                    {
                        std::cout << "Tu fondo de riesgo para esta ronda es de: " << fondoRiesgo << " euros." << std::endl;
                    }

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

                do
                {
                    if (fondoSeguridad > 0)
                    {
                        std::cout << "Tu fondo de seguridad para esta ronda es de: " << fondoSeguridad << " euros." << std::endl;
                    }

                    std::cout << "Elija la cantidad de dinero que desea depositar en la inversion de seguridad: ";
                    std::cin >> dineroInversionSeguridad;

                    if (dineroInversionSeguridad <= 0)
                    {
                        std::cout << "No puedes introducir valores negativos o nulos." << std::endl;
                    }
                    else if (dineroInversionSeguridad > capitalUsuarioRondaActual)
                    {
                        std::cout << "No puedes invertir tanto dinero en seguridad, solo dispones de " << capitalUsuarioRondaActual << " euros." << std::endl;
                    }
                    if (seguridadActual + dineroInversionSeguridad / 10000 * 0.01 > 1)
                    {
                        std::cout << "No puedes invertir tanto dinero en seguridad esta ronda, el maximo es: " << (1 - seguridadActual) * 1000000 << " euros." << std::endl;
                    }

                } while (dineroInversionSeguridad <= 0 || dineroInversionSeguridad > capitalUsuarioRondaActual || (seguridadActual + (dineroInversionSeguridad / 10000 * 0.01)) > 1);

                capitalUsuarioRondaActual -= dineroInversionSeguridad;

                fondoSeguridad += dineroInversionSeguridad;

                gastado2 = true;

                break;
            case '3':

                do
                {
                    if (fondoOficinas > 0)
                    {
                        std::cout << "Tu fondo de oficinas para esta ronda es de: " << fondoOficinas << " euros." << std::endl;
                    }

                    std::cout << "Elija la cantidad de dinero que desea depositar en la inversion de oficinas: ";
                    std::cin >> dineroInversionOficinas;

                    if (dineroInversionOficinas <= 0)
                    {
                        std::cout << "No puedes introducir valores negativos o nulos." << std::endl;
                    }
                    else if (dineroInversionOficinas > capitalUsuarioRondaActual)
                    {
                        std::cout << "No puedes invertir tanto dinero en riesgo, solo dispones de " << capitalUsuarioRondaActual << " euros." << std::endl;
                    }

                } while (dineroInversionOficinas <= 0 || dineroInversionOficinas > capitalUsuarioRondaActual);

                capitalUsuarioRondaActual -= dineroInversionOficinas;

                fondoOficinas += dineroInversionOficinas;

                gastado3 = true;

                break;
            default:
                if (gastado1 || gastado2 || gastado3)
                {
                    std::cout << "Procediendo..." << std::endl;
                    Sleep(1000);
                }
                
                break;
            }

            // Control para que el usuario gaste al menos en alguna opcion.
        } while (!(gastado1 || gastado2 || gastado3) || (opcionElegida == '1' || opcionElegida == '2' || opcionElegida == '3') && capitalUsuarioRondaActual > 0);

        if (capitalUsuarioRondaActual <= 0)
        {
            std::cout << "Esta ronda ya no tienes dinero. Procediendo..." << std::endl;
            Sleep(1000);
        }
        // Lo que pasa en cada caso que se haya gastado dinero.
        if (gastado1)
        {
            int numeroAleatorioRiesgo = rand() % (100 - 1 + 1) + 1;
            //std::cout << std::endl << numeroAleatorioRiesgo << std::endl;

            if (numeroAleatorioRiesgo <= riesgoMaximo * posibilidadTriplicar)
            {
                std::cout << "Has triplicado tu inversion de riesgo de " << fondoRiesgo << " euros. Obtienes " << fondoRiesgo * 3 << " euros." << std::endl;
                capitalUsuarioRondaActual += fondoRiesgo * 3;
            }
            else if (numeroAleatorioRiesgo > (riesgoMaximo * posibilidadTriplicar) && numeroAleatorioRiesgo <= (riesgoMaximo * (posibilidadPerder + posibilidadTriplicar)))
            {
                std::cout << "Has perdido tu dinero en la inversion de riesgo, pierdes " << fondoRiesgo << " euros." << std::endl;
                fondoRiesgo = 0;
            }
            else if (numeroAleatorioRiesgo > (riesgoMaximo * (posibilidadPerder + posibilidadTriplicar)) && numeroAleatorioRiesgo <= (riesgoMaximo * (posibilidadMantener + posibilidadPerder + posibilidadTriplicar)))
            {
                std::cout << "Tu inversion se ha mantenido, recuperas tus " << fondoRiesgo << " euros." << std::endl;
                capitalUsuarioRondaActual += fondoRiesgo;
            }

        }
        if (gastado2)
        {
            seguridadActual += (fondoSeguridad / 10000) * 0.01;
        }

        std::cout << "La seguridad actual es del " << seguridadActual * 100 << "%." << std::endl;

        int numeroAleatorioSeguridad = rand() % (100 - 1 + 1) + 1;
        //std::cout << std::endl << numeroAleatorioSeguridad;

        if (numeroAleatorioSeguridad <= seguridadMaxima * seguridadActual)
        {
            std::cout << "No ha habido fallos de seguridad." << std::endl;
        }
        else
        {
            std::cout << "Ha ocurrido un fallo de seguridad, se retiraran de los fondos " << (1.0f - seguridadActual) * capitalActual << " euros." << std::endl;
            capitalActual -= capitalActual * (1.0f - seguridadActual);
        }

        int numeroAleatorioOficinas = rand() % (100 - 20 + 1) + 20;
        //std::cout << std::endl << numeroAleatorioOficinas;

        if (fondoOficinas >= numeroAleatorioOficinas * 1000)
        {
            fondoOficinas -= numeroAleatorioOficinas * 1000;
            capitalUsuarioRondaActual += fondoOficinas;
            std::cout << "Has tenido suficiente dinero para cubrir los gastos de oficinas, se te devuelven " << fondoOficinas << " euros." << std::endl;
        }
        else if (fondoOficinas < numeroAleatorioOficinas * 1000 && fondoOficinas > 0)
        {
            std::cout << "No has tenido suficiente dinero para cubrir los gastos de oficinas, se te quitan esos fondos mas " << ((penalizacion - fondoOficinas) + capitalActual * porcentajePenalizacion) << " euros." << std::endl;

            capitalActual -= ((penalizacion - fondoOficinas) + capitalActual * porcentajePenalizacion);
        }
        else
        {
            std::cout << "No has tenido suficiente dinero para cubrir los gastos de oficinas, se te quitan " << (penalizacion - capitalActual * porcentajePenalizacion) << " euros." << std::endl;
            capitalActual -= (penalizacion - capitalActual * porcentajePenalizacion);
        }

        capitalActual += capitalUsuarioRondaActual;

        capitalUsuarioRondaActual = 0;

        contadorDias++;

        if ( seguridadActual > 0.5)
        {
            seguridadActual -= 0.05;
        }
        else
        {
            seguridadActual = 0;
        }
    }

    if (capitalActual >= 1500000)
    {
        std::cout << std::endl << "Enhorabuena, has ganado el juego!" << std::endl;
    }
    else if (capitalActual <= 0)
    {
        std::cout << std::endl << "Has perdido todo el dinero." << std::endl;
    }
    else
    {
        std::cout << std::endl << "Han pasado 10 dias y no has sido capaz de recaudar el capital necesario. Has perdido." << std::endl;
    }
}