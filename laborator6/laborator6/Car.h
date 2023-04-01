#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include "Weather.h"

class Car
{
protected:
	float FuelCapacity;
	float FuelConsumption;
	float AverageSpeed[3];
	float FinishTime;
	bool IsOutofFuel;
public:
	virtual float GetSpeed(Weather w) = 0;
	virtual float GetFuelConsumption() = 0;
	virtual float GetTotalFuel() = 0;
	virtual float GetFinishTime() = 0;
	virtual bool GetOutOfFuel() = 0;
	virtual char* GetName() = 0;
	virtual void SetOutOfFuel(bool b) = 0;
	virtual void SetFinishTime(float time) = 0;

};