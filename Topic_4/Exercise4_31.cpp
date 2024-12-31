/* 31. Crea un programa que simule el funcionamiento de una caja registradora que inicia con 150€.Cuando se inicie el programa aparecerá un menú que ofrece al usuario las opciones de : Reiniciar caja, iniciar venta, retirar dinero y finalizar.
    - Reiniciar caja : Hará que la caja vuelva a sus valores de origen.
    - Iniciar venta : Iniciará un sub menu en el que podrá añadir cantidad de productos y precio unidad tantas veces como quiera o seleccionar finalizar venta.Al finalizar la venta el programa pedirá al usuario que le indique cuánto dinero va a depositar y seguidamente indicar el cambio.Si tras una venta la caja registra que tiene más de 300€ debe informar al usuario.
    - Retirar dinero : Preguntará el pin de desbloqueo(hardcodeado en la aplicación) y luego la cantidad a retirar.
    - Al finalizar la caja indicará el total de productos vendidos, los ingresos totales, la cantidad de dinero retirado y la cantidad de dinero que permanece en ella. */


#include <iostream>
#include <Windows.h>

void main() {
    char menu, submenu;
    float dineroInicial = 150, dineroActual, precioUnidad, dineroVenta = 0, efectivo, efectivoMaximoCaja = 300, importeRetirar, totalRetirado = 0, ingresado = 0;
    int cantidadProductos, PINIntroducido, PIN = 1312321, intentos = 1, maxIntentos = 3, claveJefe = 13579, claveJefeIntroducida, productosVendidos = 0, productosVentaActual = 0, ingresadoVentaActual = 0, contador = 0;

    std::cout << "CAJA REGISTRADORA" << std::endl << std::endl;

    dineroActual = dineroInicial;

    do
    {
        std::cout << "Elija una de las siguientes opciones:" << std::endl << "\t" << "a) Reiniciar caja." << std::endl << "\t" << "b) Iniciar venta." << std::endl << "\t" << "c) Retirar dinero." << std::endl << "\t" << "d) Finalizar." << std::endl;
        std::cin >> menu;

        switch (menu)
        {
        case 'a': case 'A':
            dineroActual = dineroInicial;
            intentos = 1;
            ingresado = 0;
            productosVendidos = 0;
            productosVentaActual = 0;
            ingresadoVentaActual = 0;
            totalRetirado = 0;
            contador = 0;

            break;
        case 'b': case 'B':
            do
            {
                std::cout << std::endl << std::endl;
                std::cout << "VENTA INICIADA" << std::endl << "Seleccione una de las siguientes opciones:" << std::endl << "\t" << "a) Anyadir producto." << std::endl << "\t" << "b) Finalizar venta." << std::endl << "\t" << "- Cualquier otra tecla para cancelar venta y volver al menu principal." << std::endl;
                std::cin >> submenu;

                    switch (submenu)
                    {
                    case 'a': case 'A':

                        std::cout << "Indique la cantidad de productos: ";
                        std::cin >> cantidadProductos;
                        std::cout << "Indique el precio por unidad: ";
                        std::cin >> precioUnidad;

                        dineroVenta += cantidadProductos * precioUnidad;
                        productosVentaActual += cantidadProductos;
                        ingresadoVentaActual += dineroVenta;

                        break;
                    case 'b': case 'B':

                        std::cout << "El coste total de los articulos vendidos es: " << dineroVenta << " euros." << std::endl;
                        do
                        {
                            if (contador != 0)
                            {
                                std::cout << "El dinero a pagar no puede ser inferior al dinero que se debe." << std::endl;
                            }

                            std::cout << "Indique el dinero que va a depositar: ";
                            std::cin >> efectivo;

                            contador++;

                        } while (efectivo < dineroVenta);

                        std::cout << "El cambio a devolver son: " << efectivo - dineroVenta << " euros." << std::endl;

                        ingresado += ingresadoVentaActual;
                        productosVendidos += productosVentaActual;
                        
                        dineroActual += dineroVenta;

                        if (dineroActual > efectivoMaximoCaja)
                        {
                            std::cout << "El efectivo en caja supera los " << efectivoMaximoCaja << " euros." << std::endl;
                        }

                        contador = 0;

                        break;
                    default:

                        std::cout << "Venta cancelada. Saliendo al menu principal..." << std::endl;
                        dineroVenta = 0;
                        Sleep(1000);
                        submenu = 'b';
                        contador = 0;

                        break;
                    }
            } while (submenu != 'b' && submenu!= 'B');
            
            break;
        case 'c': case 'C':

            std::cout << std::endl << std::endl;
            std::cout << "RETIRADA DE DINERO" << std::endl;

            while (intentos <= maxIntentos)
            {
                std::cout << "Introduzca el PIN: ";
                std::cin >> PINIntroducido;

                if (intentos == maxIntentos)
                {
                    std::cout << "Intentos maximos alcanzados. La caja ha sido bloqueada. Pongase en contacto con su jefe para desbloquearla." << std::endl;
                    std::cin >> claveJefeIntroducida;

                    while (claveJefeIntroducida != claveJefe)
                    {
                        std::cout << std::endl;
                        std::cin >> claveJefeIntroducida;
                    }
                    intentos = 1;
                    break;
                }

                if (PINIntroducido == PIN)
                {
                    std::cout << "Introduzca el importe a retirar: ";
                    std::cin >> importeRetirar;

                    if (importeRetirar > dineroActual)
                    {
                        std::cout << "ERROR 02: No es posible retirar tanto efectivo. Actualmente en caja hay: " << dineroActual << " euros." << std::endl;

                        break;
                    }
                    else
                    {
                        std::cout << "Dinero retirado con exito." << std::endl;
                        dineroActual -= importeRetirar;
                        totalRetirado += importeRetirar;

                        break;
                    }
                }
                intentos++;
            }

            break;
        case 'd': case 'D':

            std::cout << std::endl << std::endl;
            std::cout << "FINALIZANDO" << std::endl;

            std::cout << "El total de productos vendidos fue: " << productosVendidos << " productos." << std::endl;
            std::cout << "El total de ingresos fue: " << ingresado << " euros." << std::endl;
            std::cout << "El total de dinero retirado fue: " << totalRetirado << " euros." << std::endl;
            std::cout << "El total de dinero en caja es: " << dineroActual << " euros." << std::endl;

            break;
        default:
            std::cout << "ERROR 01: Opcion no valida identificada. Por favor pruebe de nuevo." << std::endl;
            
            break;
        }
    } while (menu != 'd' && menu != 'D');
    
}