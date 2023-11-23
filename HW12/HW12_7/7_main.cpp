#include <iostream>
#include "ani.h"
#include "hum.h"
#include "bird.h"
#include "fish.h"
using namespace std;
int main() {
	animal *a[3];
	for (int i = 0; i < 2; i++) a[i] = new fish;
	fish c;
	a[2] = &c;
	c.sea();
	a[2]->sea;
	((fish*)a[2])->sea();
	return 123;
}
