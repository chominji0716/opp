#pragma once
#include <iostream>
using namespace std;
class animal {
    public:
    animal() : nLegs(2) {
        cout << nLegs << " Animal \n";
    };
    int nLegs;
    void eat() {cout << "I eat \n";}
};