#include "animal.h"
using namespace std;

class human : public animal {
    public:
    human() {nArms = 2;};
    int nArms;
    void walk() {cout << "I walk \n";}
};