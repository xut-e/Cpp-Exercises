/* 16. Crea un programa que reciba dos fechas en el formato yyyy-mm-dd e
 indique cuántos días hay entre ambas fechas teniendo en cuenta los años
 bisiestos. */

/* 16. Crea un programa que reciba dos fechas en el formato yyyy-mm-dd e
 indique cuántos días hay entre ambas fechas teniendo en cuenta los años
 bisiestos. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string fecha1, fecha2;
     int anyo1, mes1, dia1, anyo2, mes2, dia2;
     bool fechaValida;
 
     std::cout << "Introduce fechas en el siguiente formato: YYYY-MM-DD" << std::endl;
 
     auto esBisiesto = [](int anyo) {
         return (anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0));
         };
 
     int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
     do {
         fechaValida = true;
         std::cout << "Introduce una fecha: ";
         std::getline(std::cin, fecha1);
 
         if (fecha1.length() == 10 && fecha1[4] == '-' && fecha1[7] == '-') {
             anyo1 = std::stoi(fecha1.substr(0, 4));
             mes1 = std::stoi(fecha1.substr(5, 2));
             dia1 = std::stoi(fecha1.substr(8, 2));
 
             if (mes1 < 1 || mes1 > 12 || dia1 < 1 || dia1 >(mes1 == 2 && esBisiesto(anyo1) ? 29 : diasPorMes[mes1 - 1])) {
                 fechaValida = false;
                 std::cout << "Fecha no valida." << std::endl;
             }
         }
         else {
             fechaValida = false;
             std::cout << "Formato incorrecto." << std::endl;
         }
     } while (!fechaValida);
 
     do {
         fechaValida = true;
         std::cout << "Introduce otra fecha: ";
         std::getline(std::cin, fecha2);
 
         if (fecha2.length() == 10 && fecha2[4] == '-' && fecha2[7] == '-') {
             anyo2 = std::stoi(fecha2.substr(0, 4));
             mes2 = std::stoi(fecha2.substr(5, 2));
             dia2 = std::stoi(fecha2.substr(8, 2));
 
             if (mes2 < 1 || mes2 > 12 || dia2 < 1 || dia2 >(mes2 == 2 && esBisiesto(anyo2) ? 29 : diasPorMes[mes2 - 1])) {
                 fechaValida = false;
                 std::cout << "Fecha no valida." << std::endl;
             }
         }
         else {
             fechaValida = false;
             std::cout << "Formato incorrecto." << std::endl;
         }
     } while (!fechaValida);
 
     if (esBisiesto(anyo1)) diasPorMes[1] = 29;
     if (esBisiesto(anyo2)) diasPorMes[1] = 29;
 
     int diasPasados = 0;
     while (anyo1 < anyo2 || (anyo1 == anyo2 && mes1 < mes2) || (anyo1 == anyo2 && mes1 == mes2 && dia1 < dia2)) {
         dia1++;
         diasPasados++;
         if (dia1 > diasPorMes[mes1 - 1]) {
             dia1 = 1;
             mes1++;
         }
         if (mes1 > 12) {
             mes1 = 1;
             anyo1++;
             if (esBisiesto(anyo1)) {
                 diasPorMes[1] = 29;
             }
             else {
                 diasPorMes[1] = 28;
             }
         }
     }
 
     std::cout << "La cantidad total de dias es de " << diasPasados << std::endl;
     return 0;
 }