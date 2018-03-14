#ifndef FLOAT_ARRAY_H
#define FLOAT_ARRAY_H

class FloatArray
{
public:
	FloatArray();
	~FloatArray();

	void Add(float value);
	void Remove(int index);
	void Resize(const int size);

	const float* GetRawArray() const { return mpFloats; };
	int GetNumberOfFloats() const { return mNumberOfFloats; }

private:
	float* mpFloats = nullptr;
	int mNumberOfFloats = 0;
	int mCapacity = 20;

	void Shift(float* begin, int range);
	void Expand();
};

#endif // #ifndef FLOAT_ARRAY_H
