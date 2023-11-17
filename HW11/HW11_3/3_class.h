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
    LoL(int n1, int n2, float A, float B, float X, float dX, int M, string ss) {
		N1 = n1;
		N2 = n2;
		a = A;
		b = B;
		x0 = X;
		dx = dX;
		m = M;
		filename = ss;
		f0(); f1(); f2();
    }
	~LoL() {}
	void f0(); 
	void f1();
	void f2();
};
