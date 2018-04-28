#include <iostream>
#include "SharedPointer.h"
#include <memory>
#include <string>

class animal
{
private:
	std::string mName = "";

public:
	animal() = default;

	void SetName(const std::string& s) { mName = s; };
	const std::string& GetName() const { return mName; };
};


using namespace smrt_ptr;
int main()
{
	SharedPointer<int> sharedInt = smrt_ptr::MakeShared(new int(5));
	SharedPointer<int> sharedInt3;

	SharedPointer<animal> sharedAnimal = smrt_ptr::MakeShared(new animal());
	sharedAnimal->SetName("Lexa");
	std::cout << "SHARED ANIMAL'S NAME IS: " << sharedAnimal->GetName() << std::endl;

	{
		SharedPointer<int> sharedInt2 = sharedInt;
		sharedInt3 = sharedInt2;

		std::cout << *sharedInt << std::endl;
		std::cout << *sharedInt2 << std::endl;
		*sharedInt = 10;
		std::cout << *sharedInt3 << std::endl;
	}

	std::shared_ptr<int> a = std::make_shared<int>(5);

	system("pause");
	return 0;
}