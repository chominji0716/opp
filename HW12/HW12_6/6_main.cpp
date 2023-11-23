#include <iostream>
using namespace std;
#include "Car.h"
int main(int argc, char* argv[]) {
	Car* A = new Car(5, 2, 50000);
	Car* B = new Car(10, 4, 100000);
	Car C = *A + *B;
	cout << "The speed is " << C.speed << "\n";
	cout << "The number of wheels "<< C.wheels <<"\n";
	cout << "The number of wheels " << C.price << "\n";

	delete A,B;
	getchar();
	return 123;
}
