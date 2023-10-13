#include <iostream>
#include <fstream>
using namespace std;

float getfrequency(const string& note) {
    float f;
    if (note == "A1") f = 220;
    else if (note == "B1") f = 246.94;
    else if (note == "C") f = 261.63;
    else if (note == "D") f = 293.66;
    else if (note == "E") f = 329.63;
    else if (note == "F") f = 349.23;
    else if (note == "G") f = 392.00;
    else if (note == "A") f = 440.00;
    else if (note == "B") f = 493.88;
    else if (note == "Db") f = 277.18;
    else if (note == "Eb") f = 311.13;
    else if (note == "Ab") f = 415.30;
    else if (note == "Bb") f = 466.16;
    else if (note == "A1b") f = 207.65;
    else if (note == "B1b") f = 233.08;
    else return -1;
    return f;
}
int getAmplitude(int strength) {
    float a;
    if (strength == 1) a = 1000;
    else if (strength == 2) a = 2000;
    else if (strength == 3) a = 3000;
    else if (strength == 4) a = 4000;
    else if (strength == 5) a = 5000;
    else if (strength == 6) a = 6000;
    else if (strength == 7) a = 7000;
    else if (strength == 8) a = 8000;
    else if (strength == 9) a = 9000;
    else if (strength == 10) a = 10000;
    else return -1;
    return a;
}
float getLength(int eumpyo) {
    float T;
    if (eumpyo == 2) T = 2.0;
    else if (eumpyo == 4) T = 1.0;
    else if (eumpyo == 8) T = 0.5;
    else if (eumpyo == 16) T = 0.25;
    else return -1;
    return T;
}

int main() {
    ifstream xx("my.wav", ios::binary | ios::in);
    if (!xx) return 999;  // if the file is not found
    char header[44];
    // Sprint 1
    xx.read(header, 44);
    xx.close();
    int* sampleRate = (int*)(header + 24);
    cout << "   sampleRate = " << *sampleRate << endl;
    short* n;   n = (short*)(header + 22);  cout << *n << endl; // numChannels
    int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; // sampleRate
    int* b;   b = (int*)(header + 28);  cout << *b << endl;  //  byteRate
    *n = 2;  // streo
    int N = fs[0] * 10; // number of samples for 1 second
    short* data;
    data = new short[N]; // allocate memory for 1 seconds mono
    const float pi = 3.141592;
    float dt = 1. / fs[0];

    ofstream yy("my3.wav", ios::binary | ios::out);
    if (!yy) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
    yy.write(header, 100 * sizeof(char)); // 헤더를 쓴다. 
    ifstream zz("note.txt");
    int f, a, T, tt, ss;
    float t = 0;
    string hh;
    int k;
    zz >> k;
    for (int i = 0; i < k; i++) {
        zz >> tt >> hh >> ss;
        f = getfrequency(hh);
        a = getAmplitude(ss);
        T = getLength(tt);
        for (int j = 0; j < fs[0]; j++, t += dt) {
            data[j] = (short)(a * sin(2.0 * pi * f * t));   // a 진폭, f 주파수, N 샘플수(1초는 fs[0] samples, 44100 또는 8000)
        }
        yy.write((char*)data, fs[0] * sizeof(short));    // 1초 분량 쓴다.
    }
    yy.close();
    return 1;
}
