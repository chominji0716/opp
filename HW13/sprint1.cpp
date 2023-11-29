#include <iostream>
#include <Windows.h>
using namespace std;

int main(void) {
    int elapsedSeconds = 0, x, T = 1;
    cout << " RANDMAX " << RAND_MAX << endl;
    while (elapsedSeconds < 18) {
        Sleep(T * 1000);
        x = rand() % 100;
        elapsedSeconds += T;
        cout << " Elapsed time[sec] = " << elapsedSeconds << " " << x << endl;
    }
    return 0;
}
