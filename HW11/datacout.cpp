#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// LoL 객체의 데이터를 파일에서 읽는 함수
void readFromFile(char* filename) {
    ifstream inf(filename, ios::binary | ios::in);
    if (!inf) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }

    int N1, N2, m, Sum;
    float a, b, x, dx;
    inf.read((char*)&N1, sizeof(int));
    inf.read((char*)&N2, sizeof(int));
    inf.read((char*)&a, sizeof(float));
    inf.read((char*)&b, sizeof(float));
    inf.read((char*)&x, sizeof(float));
    inf.read((char*)&dx, sizeof(float));
    inf.read((char*)&m, sizeof(int));
    inf.read((char*)&Sum, sizeof(int));

    // 메모리 할당과 결과값 읽기
    float* result = new float[m];
    inf.read((char*)result, m * sizeof(float));

    // 읽은 데이터를 출력
    cout << "N1: " << N1 << endl;
    cout << "N2: " << N2 << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "x: " << x << endl;
    cout << "dx: " << dx << endl;
    cout << "m: " << m << endl;
    cout << "Sum: " << Sum << endl;
    for (int i = 0; i < m; i++) {
        cout << "result[" << i << "]: " << result[i] << endl;
    }

    delete[] result; // 할당된 메모리를 해제
}

int main() {
    readFromFile((char*)"akali.dat");
    readFromFile((char*)"amumu.dat");
    readFromFile((char*)"annie.dat");
    readFromFile((char*)"ashe.dat");
    return 0;
}
