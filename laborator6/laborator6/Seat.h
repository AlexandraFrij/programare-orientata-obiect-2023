#pragma once
#include "Car.h"
#include "Weather.h"
class Seat: public Car
{

public:
	Seat();
	float GetFuelConsumption();
	float GetTotalFuel();
	float GetSpeed(Weather w);
	void SetOutOfFuel(bool b);
	bool GetOutOfFuel();
	void SetFinishTime(float time);
	float GetFinishTime();
	char* GetName();
};

