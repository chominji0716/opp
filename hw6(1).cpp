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
