//  9. Crea un programa que contendrá los ingredientes para hacer una tortilla de patatas (incluyendo la cebolla).Seguidamente el usuario debe de mencionar tantos ingredientes como ingredientes contenga la tortilla.Si se equivoca o repite uno ya mencionado se le informará del error correspondiente.

#include <iostream>

void main() {
	std::string ing1 = "cebolla", ing2 = "patata", ing3 = "huevo", ing4 = "aceite", ing5 = "sal";
	std::string respuesta;

	std::cout << "Introduce tantos ingredientes como puedas, en minusculas y en singular (hay 5)." << std::endl;

	std::cout << "Primer ingrediente: ";
	std::cin >> respuesta;
	
	bool mencionado1 = false, mencionado2 = false, mencionado3 = false, mencionado4 = false, mencionado5 = false;

	#pragma region condicional1
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
		else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || respuesta == ing4 && mencionado4 || respuesta == ing5 && mencionado5)
		{
			std::cout << "ERROR 01: Ingrediente repetido." << std::endl;
		}
		else
		{
			std::cout << "ERROR 02: Ingrediente no contenido en la tortilla de patatas." << std::endl;
		}

	#pragma endregion

	std::cout << "Segundo ingrediente: ";
	std::cin >> respuesta;

	#pragma region condicional2
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
		else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || respuesta == ing4 && mencionado4 || respuesta == ing5 && mencionado5)
		{
			std::cout << "ERROR 01: Ingrediente repetido." << std::endl;
		}
		else
		{
			std::cout << "ERROR 02: Ingrediente no contenido en la tortilla de patatas." << std::endl;
		}
	#pragma endregion

	std::cout << "Tercer ingrediente: ";
	std::cin >> respuesta;

	#pragma region condicional3
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
		else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || respuesta == ing4 && mencionado4 || respuesta == ing5 && mencionado5)
		{
			std::cout << "ERROR 01: Ingrediente repetido." << std::endl;
		}
		else
		{
			std::cout << "ERROR 02: Ingrediente no contenido en la tortilla de patatas." << std::endl;
		}
	#pragma endregion

	std::cout << "Cuarto ingrediente: ";
	std::cin >> respuesta;

	#pragma region condicional4
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
		else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || respuesta == ing4 && mencionado4 || respuesta == ing5 && mencionado5)
		{
			std::cout << "ERROR 01: Ingrediente repetido." << std::endl;
		}
		else
		{
			std::cout << "ERROR 02: Ingrediente no contenido en la tortilla de patatas." << std::endl;
		}
	#pragma endregion

	std::cout << "Quinto ingrediente: ";
	std::cin >> respuesta;

	#pragma region condicional5
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
		else if (respuesta == ing1 && mencionado1 || respuesta == ing2 && mencionado2 || respuesta == ing3 && mencionado3 || respuesta == ing4 && mencionado4 || respuesta == ing5 && mencionado5)
		{
			std::cout << "ERROR 01: Ingrediente repetido." << std::endl;
		}
		else
		{
			std::cout << "ERROR 02: Ingrediente no contenido en la tortilla de patatas." << std::endl;
		}
	#pragma endregion
		
	if (mencionado1 && mencionado2 && mencionado3 && mencionado4 && mencionado5)
	{
		std::cout << "Enhorabuena, has respondido correctamente todos los ingredientes" << std::endl;
	}
	else 
	{
		std::cout << "Te han faltado " << 5 - (mencionado1 + mencionado2 + mencionado3 + mencionado4 + mencionado5) << " ingredientes." << std::endl;
	}
}