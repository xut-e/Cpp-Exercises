/*  26.Usando de ejemplo el caso anterior esta vez el programa generará visualmente un árbol de estrellas con tantas filas como haya indicado el usuario donde en cada fila habrá un * más que en el anterior. Por ejemplo si introduce 5 el resultado debe de ser:
       *
      * *
     * * *
    * * * *
   * * * * *    */

#include <iostream>


void main() {
	int numero;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	for (int i = 0; i < numero + 1; i++)
	{
		for (int k = 1; k <= (numero - i); k++)
		{
			std::cout << " ";
		}
		for (int j = 1; j < i + 1; j++)
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}