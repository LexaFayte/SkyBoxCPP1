#include <iostream>
#include <string>

#include"Shapes.h"

void PrintName(std::string name);

int main()
{
	Circle circle("Circle", 5.0f);
	Rectangle rectangle("Rectangle", 69.2f, 7.2f);
	Sphere sphere("Sphere", 2.0f);
	Cube cube("Cube", 5.0f);

	PrintName(circle.GetName());
	circle.Print();

	PrintName(rectangle.GetName());
	rectangle.Print();

	PrintName(sphere.GetName());
	sphere.Print();

	PrintName(cube.GetName());
	cube.Print();

	system("pause");
	return 0;
}

void PrintName(std::string name)
{
	std::cout << "Name: " << name << std::endl;
}