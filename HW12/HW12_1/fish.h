#include "animal.h"

class fish : public animal {
    public:
    fish() : nFin(2) {};
    int nFin;
    void swim();
};