// 30. Crea un programa que pedirá al usuario una cantidad de dinero, el interés anual, cuántos años debe de realizar la simulación y un valor mínimo y máximo que hará variar anualmente el interés de forma aleatoria.El programa debe de mostrar para cada año los beneficios anuales, el beneficio total desde que inició la inversión y el interés anual aplicado junto a la variación respecto al año anterior aplicada.

#include <iostream>
#include <cmath>
#include <time.h>

void main() {
    srand(time(0));
    float cantidad, interes, dineroGenerado, interesTotalGenerado = 0, minInteres, maxInteres, nuevoInteres, antiguoInteres;
    int anyos;

    std::cout << "Introduce la cantidad de dinero que quieres invertir: ";
    std::cin >> cantidad;
    std::cout << "Introduce el interes generado por tu dinero (en porcentaje): ";
    std::cin >> interes;
    std::cout << "Introduce la cantidad de anyos durante la que quieres invertir: ";
    std::cin >> anyos;
    std::cout << "Introduce el minimo de la posible fluctuacion del interes: ";
    std::cin >> minInteres;
    std::cout << "Introduce el maximo de la posible fluctuacion del interes: ";
    std::cin >> maxInteres;

    for (int i = 0; i < anyos; i++) {
        dineroGenerado = cantidad * std::pow(1 + interes / 100, 1) - cantidad;
        interesTotalGenerado += dineroGenerado;

        std::cout << "El beneficio obtenido durante el anyo " << i + 1 << " sera: " << dineroGenerado << " euros." << std::endl;
        std::cout << "El beneficio total desde el comienzo es de " << interesTotalGenerado << " euros." << std::endl;
        if (i != 0)
        {
            nuevoInteres = rand() % ((int)(maxInteres - minInteres + 1)) + minInteres;
        }

        if (i == 0) {
            std::cout << "El interes anual actual es: " << interes << "%." << std::endl;
            antiguoInteres = interes;
        }
        else {
            std::cout << "El interes anual actual es: " << nuevoInteres << "% y la variacion respecto al anyo pasado es de : ";

            if (nuevoInteres > antiguoInteres) {
                std::cout << "+" << nuevoInteres - antiguoInteres << "%." << std::endl;
            }
            else if (nuevoInteres < antiguoInteres) {
                std::cout << "-" << antiguoInteres - nuevoInteres << "%." << std::endl;
            }
            else {
                std::cout << "+0%." << std::endl;
            }
        }

        cantidad += dineroGenerado;

        if (i != 0)
        {
            antiguoInteres = nuevoInteres;
        }
    }
}
