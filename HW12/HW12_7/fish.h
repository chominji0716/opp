#pragma once
#include "ani.h"
class fish : public animal {
public:
	fish() { Fin = 2; };
	int Fin;
	void sea() { std::cout << " Under the sea~ \n"; }
};
