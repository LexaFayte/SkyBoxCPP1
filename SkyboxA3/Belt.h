#pragma once

class Belt
{
private:
	int mSize = 0;
public:
	Belt();
	Belt(int size);
	~Belt();

	int getSize();
	void setSize(int size);
};