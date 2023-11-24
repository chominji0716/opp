#include "animal.h"
using namespace std;

class bird : public animal {
    public:
    bird() : nWings(2) {};
    int nWings;
    void fly() {cout << "I fly \n";}
};