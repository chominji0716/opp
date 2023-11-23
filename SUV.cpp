#include "SUV.h"
#include <iostream>
void SUV::setSparewheels(int ii) {
	spareWheels = ii;
}
int SUV::getSparewheels() {
	return spareWheels;
};
float SUV::getTotalPrice() {
	return (this->wheels * 100.0 + this->price);
}
void SUV::klaxon(int ii) {
	for (int i = 0; i < ii; i++) {
		std::cout << "Beep\n";
	}
}

void SUV::light(int n) {
	std::string x;
	if (n == 1) { x = "orange"; }
	else if (n == 2) { x = "yellow"; }
	else { x = "The light doesn't turn on"; }
	std::cout << "My light is " << x << "\n";
}