#pragma once

class Punkt
{
public:
	Punkt(int x, int y);
	Punkt();
	~Punkt();

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);

	bool operator==(const Punkt& other);

protected:
	int x; 
	int y;
};