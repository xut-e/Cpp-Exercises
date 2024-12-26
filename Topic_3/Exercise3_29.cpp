// 29. Crea un programa que pida al usuario su renta anual y de acuerdo a los tramos del IRPF que se muestran a continuación muestre al usuario su sueldo neto mensual y que retención se le ha realizado.

#include <iostream>

void main() {
	int rentaAnual;
	float retencion = 0;

	std::cout << "Introduzca su renta bruta anual: ";
	std::cin >> rentaAnual;

	if (rentaAnual < 0)
	{
		std::cout << "Si no tiene renta esta calculadora no tiene sentido." << std::endl;
	}
	else if (rentaAnual > 0 && rentaAnual <= 6000)
	{
		retencion = 0.0;
	}
	else if (rentaAnual > 6000 && rentaAnual <= 12000)
	{
		retencion = 0.15;
	}
	else if (rentaAnual > 12000 && rentaAnual <= 21000)
	{
		retencion = 0.25;
	}
	else if (rentaAnual > 21000 && rentaAnual <= 32200)
	{
		retencion = 0.34;
	}
	else if (rentaAnual > 32200 && rentaAnual <= 50000)
	{
		retencion = 0.45;
	}
	else if (rentaAnual > 50000 && rentaAnual <= 300000)
	{
		retencion = 0.52;
	}
	else if (rentaAnual > 300000)
	{
		retencion = 0.55;
	}

	std::cout << "Su sueldo neto mensual se reduce a la cantidad de: " << rentaAnual * retencion / 12 << " euros y la retencion aplicada es del " << retencion * 100 << " %." << std::endl;
}