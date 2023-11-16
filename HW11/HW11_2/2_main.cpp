#include <iostream>
#include <fstream>
#include <cmath>
#include "2_class.h"
using namespace std;

int main() {
    LoL akali(5, 10, 2, 3, -5, 0.1, 10);
    LoL amumu(7, 100, -3.5, 4, 100, 10, 15);
    LoL annie(12, 17, 0.01, 0.2, 1.5, 0.08, 20);
    LoL ashe(10, 20, 4.2, -5.3, 2.1, 0.2, 5);
    akali.writeToFile((char*)"akali.dat"); // 파일 이름을 string으로 변경
    amumu.writeToFile((char*)"amumu.dat");
    annie.writeToFile((char*)"annie.dat");
    ashe.writeToFile((char*)"ashe.dat");
    return 0;
}
