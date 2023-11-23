#pragma once

class Car {
public:
	Car() :speed(0.1), wheels(0), price(0.2) {};
	Car(float, int, float);
	Car& operator+(const Car&);
	
	void setPrice(float);
	float getPrice();
	float speed;
	void speedChange(float);
	void speedUp(float);
	void speedDown(float);
	int wheels;
	void setWheels(int);
	int getWheels();
	float price;
};

