#include <iostream>
using namespace std;

int main() {
	//matrix in 1D
	int N = 2, K = 3, M = 2;
	float A[] = { 1,2,3,4,5,6 }, * B, * C;
	B = new float[K * M];
	C = new float[N * M];
	B[0] = 1; B[1] = 4;
	B[2] = 2; B[3] = 5; 
	B[4] = 3; B[5] = 6;

	C[0] = 0; C[1] = 0; 
	C[2] = 0; C[3] = 0;

	//C= A*B
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			for (int k = 0; k < K; k++) {
				C[n * M + m] += A[n * K + k] * B[k * M + m];
			}
		}
	}
	//show results
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << C[n * N + m] << "  ";
		}
		cout << endl;
	}
	
	delete[] B;
	delete[] C;
}

