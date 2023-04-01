#include "RangeRover.h"

RangeRover::RangeRover()
{
	FuelCapacity = 47.65;
	FuelConsumption = 16.89;
	AverageSpeed[Rain] = 62;
	AverageSpeed[Sunny] = 76.457;
	AverageSpeed[Snow] = 50;
}

float RangeRover::GetFuelConsumption()
{
	return FuelConsumption;
}

float RangeRover::GetTotalFuel()
{
	return FuelCapacity;
}

float RangeRover::GetSpeed(Weather w)
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
void RangeRover::SetOutOfFuel(bool b)
{
	this->IsOutofFuel = b;
}

bool RangeRover::GetOutOfFuel()
{
	return IsOutofFuel;
}

void RangeRover::SetFinishTime(float time)
{
	this->FinishTime = time;
}

float RangeRover::GetFinishTime()
{
	return FinishTime;
}

char* RangeRover::GetName()
{
	char* name = new char[15];
	strcpy(name, "RangeRover");
	name[10] = '\0';
	return name;
}
