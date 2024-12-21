//  9. Crea un programa que contendrá los ingredientes para hacer una tortilla de patatas (incluyendo la cebolla).Seguidamente el usuario debe de mencionar tantos ingredientes como ingredientes contenga la tortilla.Si se equivoca o repite uno ya mencionado se le informará del error correspondiente.

#include <iostream>

void main() {
	std::string ing1 = "cebolla", ing2 = "patata", ing3 = "huevo", ing4 = "aceite", ing5 = "sal";
	std::string respuesta;
	std::cout << "Introduce tantos ingredientes como puedas: ";
	std::cin >> respuesta;
	
	bool mencionado1 = false, mencionado2 = false, mencionado3 = false, mencionado4 = false, mencionado5 = false;

	if (respuesta == ing1 && !mencionado1)
	{
		mencionado1 = true;
	}
	else if (respuesta == ing2 && !mencionado2) 
	{
		mencionado2 = true;
	}
	else if (respuesta == ing3 && !mencionado3)
	{
		mencionado3 = true;
	}
	else if (respuesta == ing4 && !mencionado4)
	{
		mencionado4 = true;
	}
	else if (respuesta == ing5 && !mencionado5)
	{
		mencionado5 = true;
	}
	else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || )
	{

	}
} 