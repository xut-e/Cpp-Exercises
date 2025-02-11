/* 16. Crea un programa que reciba dos fechas en el formato yyyy-mm-dd e
 indique cuántos días hay entre ambas fechas teniendo en cuenta los años
 bisiestos. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string fecha1, fecha2, anyo1, mes1, dia1, anyo2, mes2, dia2;
     bool fechaValida;
 
     std::cout << "Introduce fechas en el siguiente formato: YYYY-MM-DD" << std::endl;
     
     do
     {
         fechaValida = true;
         std::cout << "Introduce una fecha: ";
         std::getline(std::cin, fecha1);
 
         if (fecha1[4] == '-' && fecha1[7] == '-' && fecha1.length() == 10)
         {
             for (int i = 0; i < fecha1.length(); i++)
             {
                 if (i <= 3)
                 {
                     anyo1 += fecha1[i];
                 }
                 else if (i > 4 && i < 7)
                 {
                     mes1 += fecha1[i];
                 }
                 else if (i > 7)
                 {
                     dia1 += fecha1[i];
                 }
             }
         }
         else
         {
             fechaValida = false;
         }
 
         
 
         if (!fechaValida)
         {
             std::cout << "Formato incorrecto." << std::endl;
         }
 
     } while (!fechaValida);
 
     do
     {
         fechaValida = true;
         std::cout << "Introduce otra fecha: ";
         std::getline(std::cin, fecha2);
 
         if (fecha2[4] == '-' && fecha2[7] == '-' && fecha2.length() == 10)
         {
             for (int i = 0; i < fecha2.length(); i++)
             {
                 if (i <= 3)
                 {
                     anyo2 += fecha2[i];
                 }
                 else if (i > 4 && i < 7)
                 {
                     mes2 += fecha2[i];
                 }
                 else if (i > 7)
                 {
                     dia2 += fecha2[i];
                 }
             }
         }
         else
         {
             fechaValida = false;
         }
 
 
 
         if (!fechaValida)
         {
             std::cout << "Formato incorrecto." << std::endl;
         }
 
     } while (!fechaValida);
 
     int anyo1int = std::stoi(anyo1), anyo2int = std::stoi(anyo2), mes1int = std::stoi(mes1), mes2int = std::stoi(mes2), dia1int = std::stoi(dia1), dia2int = std::stoi(dia2);
     int anyoMenor = anyo1int < anyo2int ? anyo1int : anyo2int;
     int anyoMayor = anyo1int > anyo2int ? anyo1int : anyo2int;
     int mesMenor = anyoMenor == anyo1int ? mesMenor = mes1int : mesMenor = mes2int;
     int mesMayor = anyoMayor == anyo1int ? mesMayor = mes1int : mesMayor = mes2int;
     int diaMenor = anyoMenor == anyo1int ? diaMenor = dia1int : diaMenor = dia2int;
     int diaMayor = anyoMayor == anyo1int ? diaMayor = dia1int : diaMayor = dia2int;
 
     
     /*
     
     if (anyo1 > anyo2)
     {
 
     }
     else if (anyo1 < anyo2)
     {
 
     }
     else
     {
         if (mes1 > mes2)
         {
 
         }
         else if (mes1 < mes2)
         {
 
         }
         else
         {
             if (dia1 > dia2)
             {
 
             }
             else if (dia1 < dia2)
             {
 
             }
             else
             {
                 std::cout << "Hay 0 dias de diferencia entre las fechas." << std::endl;
             }
         }
     }
 
     */
 
     for (int i = anyoMenor; i < anyoMayor; i++)
     {
         for (int j = mesMenor; j < mesMayor; j++)
         {
             for (int k = diaMenor; k < diaMayor; k++)
             {
 
             }
         }
     }
 
     return 0;
     
 }