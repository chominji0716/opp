#include "1_class.h"
void LoL::f0(string ss) {
	aa.open(ss, ios::binary | ios::out);
	aa.write((char*)&N1, sizeof(int));
	aa.write((char*)&N2, sizeof(int));
	aa.write((char*)&a, sizeof(float));
	aa.write((char*)&b, sizeof(float));
	aa.write((char*)&x0, sizeof(float));
	aa.write((char*)&dx, sizeof(float));
	aa.write((char*)&m, sizeof(int));
}

void LoL::f1() {
	int* f1a;
	f1a = new int[N2 - N1 + 1];
	for (int i = N1; i <= N2; i++) {
		f1a[i - N1] = i * (i + 1) / 2;
	}
	aa.write((char*)f1a, sizeof(float) * (N2 - N1 + 1));
	delete[] f1a;
}
void LoL::f2() {
	float* f2a, x;
	x = x0;
	f2a = new float[m];
	for (int i = 0; i < m; i++, x += dx) {
		f2a[i] = a * x + b;
	}
	aa.write((char*)f2a, sizeof(int) * m);
	delete[] f2a;
	aa.close();
}
