#include <iostream>
#include <fstream>

using namespace std;

void savemultiple(int* arr) {
    for (int i = 1000; i <= 5000; i += 1000) {
        *arr = i * 5;
        arr++;
    }
}

void savesquare(float* arr) {
    for (float i = -0.5; i < 1.0; i += 0.5) {
        *arr = i * i;
        arr++;
    }
}

void All(ofstream& file) {
    int Value1 = 1234;
    int intArray[5];
    savemultiple(intArray);
    float floatArray[3];
    savesquare(floatArray);

    file.write((char*)(&Value1), sizeof(int));
    file.write((char*)(&intArray), sizeof(intArray));
    file.write((char*)(&floatArray), sizeof(floatArray));
}

int main() {
    ofstream file("mybin4.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    All(file);

    file.close();

    return 0;
}
