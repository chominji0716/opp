#include <iostream>
using namespace std;
#include "Car.h"
#include "SUV.h"
#include "Engineer.h"
int main(int argc,char* argv[]) {
	Car* newSUV =  new SUV();
	newSUV->setPrice(45000);
	std::cout << "The wheels are " << newSUV->getWheels()<<std::endl;
	Engineer engineer;
	std::cout << "The Price is " << engineer.getCarPrice(newSUV) << " dollars\n";

	std::cout << "without virtual \n";
	newSUV->klaxon(3);
	newSUV->light(2);

	delete newSUV;
	getchar();
	return 123;
}
