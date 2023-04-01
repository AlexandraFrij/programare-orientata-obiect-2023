#include "Fiat.h"

Fiat::Fiat()
{
	FuelCapacity = 50;
	FuelConsumption = 10;
	AverageSpeed[Rain] = 65;
	AverageSpeed[Sunny] = 80;
	AverageSpeed[Snow] = 55;
}

float Fiat::GetFuelConsumption()
{
	return FuelConsumption;
}

float Fiat::GetTotalFuel()
{
	return FuelCapacity;
}

float Fiat::GetSpeed(Weather w)
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

void Fiat::SetOutOfFuel(bool b)
{
	this->IsOutofFuel = b;
}

bool Fiat::GetOutOfFuel()
{
	return IsOutofFuel;
}

void Fiat::SetFinishTime(float time)
{
	this->FinishTime = time;
}

float Fiat::GetFinishTime()
{
	return FinishTime;
}

char* Fiat::GetName()
{
	char* name = new char[15];
	strcpy(name, "Fiat");
	name[4] = '\0';
	return name;
}
