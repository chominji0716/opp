#include <iostream>
using namespace std;

int main() {
	//matrix in 2D
	int N = 2, M = 3;
	float A[2][3] = { {1,3,4},{5,7,9} }, * *B;
	B = new float* [M];
	for (int m = 0; m < M; m++) B[m] = new float[N];

	//transfer of A
	for (int n = 0; n < M; n++) {
		for (int m = 0; m < N; m++) {
			B[n][m] = A[m][n];
		}
	}
	
	//show results
	for (int n = 0; n < M; n++) {
		for (int m = 0; m < N; m++) {
			cout << B[n][m] << "  ";
		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) { delete[] B[n]; }
	delete[] B;
}
