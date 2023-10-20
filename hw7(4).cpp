#include <iostream>
#include <fstream>

using namespace std;

void All(ofstream& file) {
    int Value1 = 1234;
    file.write((char*)(&Value1), sizeof(int));

    for (int i = 1000; i <= 5000; i += 1000) {
        int Value2 = i * 5;
        file.write((char*)(&Value2), sizeof(int));
    }


    for (float i = -0.5; i < 1.5; i += 0.5) {
        float Value3 = i*i;
        file.write(( char*)(&Value3), sizeof(float));
    }
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
