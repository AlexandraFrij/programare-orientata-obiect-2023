#include "Seat.h"
#include "Fiat.h"

Seat::Seat()
{
	FuelCapacity = 58.9;
	FuelConsumption = 13.5;
	AverageSpeed[Rain] = 65;
	AverageSpeed[Sunny] = 90;
	AverageSpeed[Snow] = 50;
}

float Seat::GetFuelConsumption()
{
	return FuelConsumption;
}

float Seat::GetTotalFuel()
{
	return FuelCapacity;
}

float Seat::GetSpeed(Weather w)
{
	switch (w)
	{
	case Rain:
		return AverageSpeed[Rain];
		break;
	case Sunny:
		return AverageSpeed[Sunny];
		break;
	case Snow:
		return AverageSpeed[Snow];
		break;
	default:
		return 0;
	}
}
void Seat::SetOutOfFuel(bool b)
{
	this->IsOutofFuel = b;
}

bool Seat::GetOutOfFuel()
{
	return IsOutofFuel;
}

void Seat::SetFinishTime(float time)
{
	this->FinishTime = time;
}

char* Seat::GetName()
{
	char* name = new char[15];
	strcpy(name, "Seat");
	name[4] = '\0';
	return name;
}

float Seat::GetFinishTime()
{
	return FinishTime;
}
