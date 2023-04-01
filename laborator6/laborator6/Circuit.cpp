#include "Circuit.h"

void Circuit::SetLength(float length)
{
	this->length = length;

}

void Circuit::AddCar(Car* car)
{
	cars[carsNumber] = car;
	carsNumber++;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::Race()
{
	for (int i = 0; i < carsNumber; i++)
	{
		float time = length / cars[i]->GetSpeed(weather);
		cars[i]->SetFinishTime(time);
		float fuelConsumed = (length / 100)  * cars[i]->GetFuelConsumption();
		if (fuelConsumed > cars[i]->GetTotalFuel())
			cars[i]->SetOutOfFuel(true);
		else cars[i]->SetOutOfFuel(false);
	}
}

void Circuit::ShowFinalRanks()
{
	Car** carsFinish = new Car * [10];
	int finishedCars = 0;
	for(int i = 0; i < carsNumber; i++)
		if (cars[i]->GetOutOfFuel() == false)
		{
			carsFinish[finishedCars] = cars[i];
			finishedCars++;
		}
	 for(int i = 0; i < finishedCars -1; i++)
		for (int j = i + 1; j < finishedCars; j++)
				if( carsFinish[i]->GetFinishTime()< carsFinish[j]->GetFinishTime())
				{
					Car* aux = carsFinish[i];
				    carsFinish[i] = carsFinish[j];
				    carsFinish[j] = aux;
				}
	 printf("%s\n", "Cars at finish: ");
	 for (int i = 0; i < finishedCars; i++)
	 {
		 printf("%s\n", carsFinish[i]->GetName());
	 }
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("%s\n", "Cars that didn't finish:");
	for (int i = 0; i < carsNumber; i++)
		if (cars[i]->GetOutOfFuel() == true)
			printf("%s\n", cars[i]->GetName());
}
