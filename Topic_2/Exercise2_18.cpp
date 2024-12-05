//18. Crea un programa en el que se introducen 3 cifras que representan lo que aportan 3 personas al pagar una cuenta y haz que el programa muestre que % hanaportado cada uno sobre el total.

#include <iostream>

void main() {
	float cifraUno;
	float cifraDos;
	float cifraTres;

	std::cout << "Introduce la primera cifra: " << std::endl;
	std::cin >> cifraUno;
	std::cout << "Introduce la segunda cifra: " << std::endl;
	std::cin >> cifraDos;
	std::cout << "Introduce la tercera cifra: " << std::endl;
	std::cin >> cifraTres;

	std::cout << "Las personas aportaron el siguiente capital sobre el total:" << std::endl << "\t" << "- Primera persona: Aporto el " << cifraUno * 100 / (cifraUno + cifraDos + cifraTres) << "% del total." << std::endl;
	std::cout << "\t" << "- Segunda persona: Aporto el " << cifraDos * 100 / (cifraUno + cifraDos + cifraTres) << "% del total." << std::endl;
	std::cout << "\t" << "- Tercera persona: Aporto el " << cifraTres * 100 / (cifraUno + cifraDos + cifraTres) << "% del total." << std::endl;
}