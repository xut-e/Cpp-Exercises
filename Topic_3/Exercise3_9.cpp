//  9. Crea un programa que contendrá los ingredientes para hacer una tortilla de patatas (incluyendo la cebolla).Seguidamente el usuario debe de mencionar tantos ingredientes como ingredientes contenga la tortilla.Si se equivoca o repite uno ya mencionado se le informará del error correspondiente.

#include <iostream>

void main() {
	std::string ing1 = "cebolla", ing2 = "patata", ing3 = "huevo", ing4 = "aceite", ing5 = "sal";
	std::string respuesta;
	std::cout << "Introduce tantos ingredientes como puedas: ";
	std::cin >> respuesta;
	
	bool mencionado1 = false, mencionado2 = false, mencionado3 = false, mencionado4 = false, mencionado5 = false;

	if (mencionado1 == true && mencionado2 == true && mencionado3 == true && mencionado4 == true && mencionado5 == true) 
	{
		std::cout << "Enorabuena! Has mencionado todos los ingredientes" << std::endl;
	}
	else 
	{

	}
}