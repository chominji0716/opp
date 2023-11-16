#include <iostream>
using namespace std;

int main() {
	//matrix in 2D
	int N = 2, K = 3, M = 2;
	float A[2][3] = { { 1,2,3},{4,5,6} }, ** B, ** C;
	B = new float* [K];
	for (int k = 0; k < K; k++) B[k] = new float[M];
	C = new float* [N];
	for (int n = 0; n < N; n++) C[n] = new float[M];
	B[0][0] = 1; B[0][1] = 4;
	B[1][0] = 2; B[1][1] = 5;
	B[2][0] = 3; B[2][1] = 6;

	C[0][0] = 0; C[0][1] = 0;
	C[1][0] = 0; C[1][1] = 0;

	//C = A * B
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			for (int k = 0; k < K; k++) {
				C[n][m] += A[n][k] * B[k][m];
			}
		}
	}
	//show results
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << C[n][m] << "  ";
		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) { delete[] B[n]; delete C[n]; }
	delete[] B;
	delete[] C;
}
