#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class LoL {
public:
    LoL() : N1(0), N2(0), a(0), b(0), x(0), dx(0), m(0), sum(nullptr), result(nullptr) {}

    LoL(int n1, int n2, float A, float B, float X, float dX, int M) {
        N1 = n1;
        N2 = n2;
        a = A;
        b = B;
        x = X;
        dx = dX;
        m = M;
        sum = new int[n2-n1+1];
        f1();
        result = new float[M]; // 동적 할당 전에 배열을 초기화
        f2();
    }

    ~LoL() {
        delete[] result;
        delete[] sum;
    }

    // 결과를 파일에 쓰는 함수
    void writeToFile(char* filename) {
        ofstream outf(filename, ios::binary | ios::out);
        if(!outf) {
            cout << "Unable to open file: " << filename << endl;
        }
        outf.write((char*)&N1, sizeof(int));
        outf.write((char*)&N2, sizeof(int));
        outf.write((char*)&a, sizeof(float));
        outf.write((char*)&b, sizeof(float));
        outf.write((char*)&x, sizeof(float));
        outf.write((char*)&dx, sizeof(float));
        outf.write((char*)&m, sizeof(int));
        outf.write((char*)sum, (N2-N1+1)*sizeof(int));
        outf.write((char*)result, m*sizeof(float));
        
    }

    void f1() {
        for (int i = N1; i <= N2; i++) {
            sum[i-N1] = i * (i + 1) / 2;
        }
    }

    void f2() {
        float currentX = x; // 임시 변수
        for (int i = 0; i < m; i++) {
            result[i] = a * currentX + b;
            currentX += dx;
        }
    }

private:
    int N1, N2, m;
    float a, b, x, dx;
    int *sum;
    float *result; // 동적으로 할당된 배열을 가리키는 포인터
};
