#include <iostream>
using namespace std;

int main() {
	//matrix in 1D
	int N = 2, M = 3;
	float A[] = { 1,3,4,5,7,9 }, * B;
	B = new float[M*N];


	//transfer of A
	for (int n = 0; n < M; n++) {
		for (int m = 0; m < N; m++) {
			B[n * N + m] = A[m * M + n];
		}
	}
	
	//show results
	for (int n = 0; n < M; n++) {
		for (int m = 0; m < N; m++) {
			cout << B[n * N + m] << "  ";
		}
		cout << endl;
	}
	delete[] B;
}
