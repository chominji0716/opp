#include<iostream>
#include <fstream>
#include <cmath> // for pow()
using namespace std;

int main() {
    float p = 1.0 / 6.0;
    int k, N = 1000;
    int max_k = 20;
    float* biex = new float[max_k + 1];
    float* bitheory = new float[max_k + 1];

    for (k = 0; k <= max_k; k++) {
        biex[k] = 0;
    }

    for (int nn = 0; nn < N; nn++) {
        int count = 0;
        int consecutive_non_six = 0;

        while (true) {
            if ((rand() / (float)RAND_MAX) < p) {
                count = consecutive_non_six + 1;
                break;
            }
            else {
                consecutive_non_six++;
            }
        }

        if (count <= max_k) {
            biex[count]++;
        }
    }

    for (k = 0; k <= max_k; k++) {
        biex[k] /= (float)N; // count --> probability
    }

    ofstream xxx("geometric.txt");
    for (k = 1; k <= max_k; k++) {
        bitheory[k] = pow(1 - p, k - 1) * p;
        xxx << k << " " << bitheory[k] << " " << biex[k] << endl;
    }
    xxx.close();

    delete[] biex;
    delete[] bitheory;

    return 1;
}
