#pragma once
class Laces
{
private:
	bool mTied = false;
public:
	Laces();
	~Laces();

	bool getTied();
	void setTied(bool tied);
};