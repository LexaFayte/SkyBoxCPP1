#include <iostream>
#include "BitArray64.h"
#include <bitset>

int main()
{
	BitArray64 ba;
	//ba.Print();
	
	int index1 = ba.Get();
	int index2 = ba.Get();
	int index3 = ba.Get();
	int index4 = ba.Get();
	ba.Set(index1, true);
	ba.Set(index2, true);
	ba.Set(index3, true);
	ba.Set(index4, true);

	//ba.Print();

	ba.Set(index3, false);
	ba.Set(index1, false);

	ba.Return(index1);
	index1 = ba.Get();
	int index5 = ba.Get();

	//ba.Print();

	system("pause");

	return 0;
}