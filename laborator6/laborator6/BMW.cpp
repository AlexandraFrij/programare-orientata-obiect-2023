#include "BMW.h"
BMW::BMW()
{
	FuelCapacity = 65;
	FuelConsumption = 20;
	AverageSpeed[Rain] = 65;
	AverageSpeed[Sunny] = 70;
	AverageSpeed[Snow] = 50;
}

float BMW::GetFuelConsumption()
{
	return FuelConsumption;
}

float BMW::GetTotalFuel()
{
	return FuelCapacity;
}

float BMW::GetSpeed(Weather w)
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
void BMW::SetOutOfFuel(bool b)
{
	this->IsOutofFuel = b;
}

bool BMW::GetOutOfFuel()
{
	return IsOutofFuel;
}

void BMW::SetFinishTime(float time)
{
	this->FinishTime = time;
}

float BMW::GetFinishTime()
{
	return FinishTime;
}

char* BMW::GetName()
{
	char* name = new char[15];
	strcpy(name, "BMW");
	name[3] = '\0';
	return name;
}
