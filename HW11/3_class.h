#pragma once
#include <fstream>
using namespace std;

class LoL {
public:
	LoL() {};
    int N1, N2, m;
    float a, b, x0, dx;
    string filename;
    ofstream dd;
    LoL(int N1, int N2, float a, float b, float x0, float dx, int m, string filename) {
        f0(); f1(); f2();
    }
    ~LoL() {}

	void f0();
	void f1();
	void f2();
};
