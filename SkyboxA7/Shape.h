#include <string>

using namespace std;

class Shape
{
public:
	Shape(string name);

	string& GetName() { return mName; }
	void SetName(string name) { mName = name; }

	virtual void Print();
	float BelowZeroCheck(float number);

private:
	string mName;
};