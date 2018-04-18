#include <iostream>
#include "List.inl"

int main()
{
	{
		Storage::List<int> listOfInts;
		listOfInts.Add(1);
		listOfInts.Add(5);
		listOfInts.Add(28);
		std::cout << "LIST OF INTS:" << std::endl;
		listOfInts.Print();

		std::cout << "\n\n";
		Storage::List<int> anotherListOfInts;
		anotherListOfInts.Add(7);
		anotherListOfInts.Add(42);
		anotherListOfInts.Add(67);
		std::cout << "ANOTHER LIST OF INTS:" << std::endl;
		anotherListOfInts.Print();

		std::cout << "\n\n";
		std::cout << "MOVING \"LIST OF INTS\" INTO A NEW LIST:" << std::endl;
		Storage::List<int> moveListInts = std::move(listOfInts);
		moveListInts.Print();

		std::cout << "\n\n";
		std::cout << "COPYING \"ANOTHER LIST OF INTS\" INTO A NEW LIST:" << std::endl;
		Storage::List<int> copyListInts(anotherListOfInts);
		copyListInts.Print();
	}

	system("pause");

	return 0;
}