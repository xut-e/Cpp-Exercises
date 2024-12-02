#include <iostream>

void main() {
#pragma region variablesYBienvenida
	short contador = 0;
	char respuestaUno;
	short racha = 0;
	short contadorBien = 0;
	short contadorMal = 0;
	short aciertosMaximos = 0;
	short fallosMaximos = 0;
	short contadorRachaAciertos = 0;
	short contadorRachaFallos = 0;

	std::cout << "Bienvenido al juego de las preguntas ;). Escriba como respuesta solo la letra de la respuesta que cree correcta. Comienza el desafio:" << std::endl << std::endl;
#pragma endregion

#pragma region pregunta1
	std::cout << std::endl << "1. Cual es la capital de Japon?:" << std::endl;
	std::cout << "\t" << "a) Pekin" << std::endl << "\t" << "b) Tokio" << std::endl << "\t" << "c) Seul" << std::endl << "\t" << "d) Bangkok" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la b) Tokio." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else{
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'b': case 'B':
		if (racha < 0) {
			racha = 1;
		}
		else{
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la b) Tokio." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta2
	std::cout << std::endl << "2. Cuantos planetas hay en el sistema solar?:" << std::endl;
	std::cout << "\t" << "a) Ocho" << std::endl << "\t" << "b) Nueve" << std::endl << "\t" << "c) Siete" << std::endl << "\t" << "d) Diez" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'b': case 'B': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la a) Ocho." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'a': case 'A':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la a) Ocho." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta3
	std::cout << std::endl << "3. Quien pinto la Mona Lisa?:" << std::endl;
	std::cout << "\t" << "a) Pablo Picasso" << std::endl << "\t" << "b) Vincent van Gogh" << std::endl << "\t" << "c) Leonardo da Vinci" << std::endl << "\t" << "d) Rembrandt" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'b': case 'B': case 'd': case 'D':
		std::cout << "La respuesta correcta era la c) Leonardo da Vinci." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'c': case 'C':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la c) Leonardo da Vinci." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta4
	std::cout << std::endl << "4. Cual es el oceano mas grande del mundo?:" << std::endl;
	std::cout << "\t" << "a) Atlantico" << std::endl << "\t" << "b) Indico" << std::endl << "\t" << "c) Pacifico" << std::endl << "\t" << "d) Artico" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'b': case 'B': case 'd': case 'D':
		std::cout << "La respuesta correcta era la c) Pacifico." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'c': case 'C':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la c) Pacifico." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta5
	std::cout << std::endl << "5. En que continente se encuentra Egipto?:" << std::endl;
	std::cout << "\t" << "a) Europa" << std::endl << "\t" << "b) Asia" << std::endl << "\t" << "c) Africa" << std::endl << "\t" << "d) America" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'b': case 'B': case 'd': case 'D':
		std::cout << "La respuesta correcta era la c) Africa." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'c': case 'C':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la c) Africa." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta6
	std::cout << std::endl << "6. Cuanto es 5 x 6?:" << std::endl;
	std::cout << "\t" << "a) Treinta" << std::endl << "\t" << "b) Veinticinco" << std::endl << "\t" << "c) Treinta y cinco" << std::endl << "\t" << "d) Cuarenta" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'b': case 'B': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la a) Treinta." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'a': case 'A':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la a) Treinta." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta7
	std::cout << std::endl << "7. Que pais tiene forma de bota?:" << std::endl;
	std::cout << "\t" << "a) España" << std::endl << "\t" << "b) Italia" << std::endl << "\t" << "c) Francia" << std::endl << "\t" << "d) Alemania" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la b) Italia." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'b': case 'B':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la b) Italia." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta8
	std::cout << std::endl << "8. Cual es el elemento quimico representado por 'O'?:" << std::endl;
	std::cout << "\t" << "a) Oxigeno" << std::endl << "\t" << "b) Oro" << std::endl << "\t" << "c) Osmio" << std::endl << "\t" << "d) Oxalato" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'b': case 'B': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la a) Oxigeno." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'a': case 'A':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la a) Oxigeno." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta9
	std::cout << std::endl << "9. Cual es el animal terrestre mas rapido?:" << std::endl;
	std::cout << "\t" << "a) Tigre" << std::endl << "\t" << "b) Leon" << std::endl << "\t" << "c) Leopardo" << std::endl << "\t" << "d) Guepardo" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'c': case 'C': case 'b': case 'B':
		std::cout << "La respuesta correcta era la d) Guepardo." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'd': case 'D':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la d) Guepardo." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region pregunta10
	std::cout << std::endl << "10. Cual es la moneda oficial de China?:" << std::endl;
	std::cout << "\t" << "a) Yen" << std::endl << "\t" << "b) Yuan" << std::endl << "\t" << "c) Won" << std::endl << "\t" << "d) Peso" << std::endl;
	std::cin >> respuestaUno;
	switch (respuestaUno) {
	case 'a': case 'A': case 'c': case 'C': case 'd': case 'D':
		std::cout << "La respuesta correcta era la b) Yuan." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos += 1;
		contadorRachaAciertos = 0;
		break;
	case 'b': case 'B':
		if (racha < 0) {
			racha = 1;
		}
		else {
			racha += 1;
		}
		contador = contador + racha;
		contadorBien += 1;
		contadorRachaAciertos += 1;
		contadorRachaFallos = 0;
		break;
	default:
		std::cout << "No has dado una respuesta valida y la pregunta ha sido contada como erronea." << std::endl;
		std::cout << "La respuesta correcta era la b) Yuan." << std::endl << std::endl;
		if (racha < 0) {
			racha -= 1;
		}
		else {
			racha = -1;
		}
		contador = contador + racha;
		contadorMal += 1;
		contadorRachaFallos -= 1;
		contadorRachaAciertos = 0;
		break;
	}
	if (fallosMaximos < contadorRachaFallos) {
		fallosMaximos = contadorRachaFallos;
	}
	if (aciertosMaximos < contadorRachaAciertos) {
		aciertosMaximos = contadorRachaAciertos;
	}
#pragma endregion

#pragma region resultadoFinal
	std::cout << std::endl;
	std::cout << "\t" << "======================" << std::endl;
	std::cout << "\t" << "  Resultados Finales  " << std::endl;
	std::cout << "\t" << "======================" << std::endl;
	std::cout << std::endl;

	if (contador != 1) {
		std::cout << "-  Tu puntuacion final ha sido de: " << contador << " puntos." << std::endl;
	}
	else {
		std::cout << "-  Tu puntuacion final ha sido de: " << contador << " punto." << std::endl;
	}
	
	std::cout << "-  Las respuestas correctas eran:" << std::endl;
	std::cout << "\t" << "b) Tokio" << std::endl << "\t" << "a) Ocho" << std::endl << "\t" << "c) Leonardo da Vinci" << std::endl << "\t" << "c) Pacifico" << std::endl << "\t" << "c) Africa" << std::endl << "\t" << "a) 30" << std::endl << "\t" << "b) Italia" << std::endl << "\t" << "a) Oxigeno" << std::endl << "\t" << "b) Guepardo" << std::endl << "\t" << "b) Yuan" << std::endl;
	if (contadorBien != 1) {
		std::cout << "-  Tuviste un total de " << contadorBien << " respuestas bien." << std::endl;
	}
	else {
		std::cout << "-  Tuviste un total de " << contadorBien << " respuesta bien." << std::endl;
	}
	if (contadorMal != 1) {
		std::cout << "-  Tuviste un total de " << contadorMal << " respuestas mal." << std::endl;
	}
	else {
		std::cout << "-  Tuviste un total de " << contadorMal << " respuesta mal." << std::endl;
	}
	if (aciertosMaximos != 1) {
		std::cout << "-  Tu racha de aciertos maxima fue de " << aciertosMaximos << " aciertos." << std::endl;
	}
	else {
		std::cout << "-  Tu racha de aciertos maxima fue de " << aciertosMaximos << " acierto." << std::endl;
	}
	if (fallosMaximos != 1) {
		std::cout << "-  Tu racha de fallos maxima fue de " << fallosMaximos << " fallos." << std::endl;
	}
	else {
		std::cout << "-  Tu racha de fallos maxima fue de " << fallosMaximos << " fallo." << std::endl;
	}
	
#pragma endregion
}
