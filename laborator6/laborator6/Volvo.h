#pragma once
#include "Car.h"
#include "Weather.h"
class Volvo : public Car
{

public:
	Volvo();
	float GetFuelConsumption();
	float GetTotalFuel();
	float GetSpeed(Weather w);
	void SetOutOfFuel(bool b);
	bool GetOutOfFuel();
	void SetFinishTime(float time);
	float GetFinishTime();
	char* GetName();
};

