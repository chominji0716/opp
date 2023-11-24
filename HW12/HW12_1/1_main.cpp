#include <iostream>
#include "animal.h"
#include "human.h"
#include "bird.h"
#include "fish.h"
using namespace std;

int main(void) {
    animal a;
    human b;
    bird c;
    fish d;
    a.eat();
    b.walk();
    c.fly();
    d.eat();
    d.swim();
    cout << " b " << b.nLegs << "\n";
    cout << " size \n";
    cout << " a " << sizeof(a) << "\n";
    cout << " b " << sizeof(b) << "\n";
    cout << " c " << sizeof(c) << "\n";
    return 0;
}
