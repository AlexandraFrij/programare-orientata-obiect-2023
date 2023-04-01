#include "Volvo.h"


Volvo::Volvo()
{
	FuelCapacity = 60;
	FuelConsumption = 15.5;
	AverageSpeed[Rain] = 60;
	AverageSpeed[Sunny] = 85;
	AverageSpeed[Snow] = 60;
}

float Volvo::GetFuelConsumption()
{
	return FuelConsumption;
}

float Volvo::GetTotalFuel()
{
	return FuelCapacity;
}

float Volvo::GetSpeed(Weather w)
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
void Volvo::SetOutOfFuel(bool b)
{
	this->IsOutofFuel = b;
}

bool Volvo::GetOutOfFuel()
{
	return IsOutofFuel;
}

void Volvo::SetFinishTime(float time)
{
	this->FinishTime = time;
}

float Volvo::GetFinishTime()
{
	return FinishTime;
}

char* Volvo::GetName()
{
	char* name = new char[15];
	strcpy(name, "Volvo");
	name[5] = '\0';
	return name;
}
