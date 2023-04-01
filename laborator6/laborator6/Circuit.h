#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{
private:
	float length;
	Weather weather;
	Car** cars = new Car*[10];
	int carsNumber = 0;
public:
	void SetLength(float length);
	void AddCar(Car* car);
	void SetWeather(Weather weather);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

