#include <iostream>
#include "DMV.h"
#include "Wolf.h"
#include "Fox.h"
#include "Dragon.h"
#include "Lynx.h"

int main()
{
	
	//Create Animals
	Wolf Lexa(5.4, "Lexa");
	Lynx Skittles(5.7, "Skittles");
	Fox Calyver(6.2, "Calyver");
	Dragon Kalurian(5.7, "Kalurian");

	//create DMV
	DMV dmv;

	dmv.EnterQueue(Lexa);
	dmv.EnterQueue(Skittles);
	dmv.EnterQueue(Calyver);
	dmv.EnterQueue(Kalurian);

	dmv.PrintServiceCounterInfo();

	system("pause");
	return 0;
}