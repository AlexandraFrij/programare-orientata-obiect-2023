#pragma once
#include "Car.h"
#include "Weather.h"
class BMW : public Car
{
public:
	BMW();
	float GetFuelConsumption();
	float GetTotalFuel();
	float GetSpeed(Weather w);
	void SetOutOfFuel(bool b);
	bool GetOutOfFuel();
    void SetFinishTime(float time);
	float GetFinishTime();
    char* GetName();
};

