#include "../naglowkowe/Punkt.h"

Punkt::Punkt(int x, int y)
{
	this->x = x;
	this->y = y;
}
Punkt::Punkt() 
{
	x = 0;
	y = 0;
}
Punkt::~Punkt() {}
void Punkt::SetX(int x)
{
	this->x = x;
}
void Punkt::SetY(int y)
{
	this->y = y;
}
int Punkt::GetX()
{
	return x;
}
int Punkt::GetY()
{
	return y;
}
bool Punkt::operator==(const Punkt& other) 
{
	return (x == other.x && y == other.y);
}