#include "3_class.h"
void LoL::f0() {
	dd.open(filename , ios::binary | ios::out);
	dd.write((char*)&N1, sizeof(int));
	dd.write((char*)&N2, sizeof(int));
	dd.write((char*)&a, sizeof(float));
	dd.write((char*)&b, sizeof(float));
	dd.write((char*)&dx, sizeof(float));
	dd.write((char*)&m, sizeof(int));
}
void LoL::f1() {
	int* f1d;
	f1d = new int[N2 - N1 + 1];
	for (int i = N1; i <= N2; i++) {
		f1d[i - N1] = i * (i + 1) / 2;
	}
	dd.write((char*)f1d, sizeof(int) * (N2 - N1 + 1));
	delete f1d;
}
void LoL::f2() {
	float* f2d, x;
	x = x0;
	f2d = new float[m];
	for (int i = 0; i < m; i++, x += dx) {
		f2d[i] = a * x + b;
	}
	dd.write((char*)f2d, sizeof(int) * m);
	delete f2d;
	dd.close();
}
