#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
using namespace std;
int main(void) {
    int elapsedSeconds = 0, T = 1;
    int NI = 200, NO = 200, ni, no;
    int NofPackets[120];
    vector <int> queue;
    while (elapsedSeconds < 120) {
        Sleep(T * 1000);
        int capacity = 100;
        int lost = 0;
        ni = rand() % 100;
        no = rand() % 100;
        if (capacity < queue.size() + ni) {
            lost += queue.size() + ni - capacity;
            ni = capacity - queue.size();
        }
        for (int i = 0; i < ni; i++) {
            queue.push_back(rand() % 20);
        }

        for (int i = 0; i < no; i++) {
            if (queue.size() != 0) {
                queue.erase(queue.begin());
            }
        }
        cout << "packets" << "[" << elapsedSeconds + 1 << "]: " << queue.size() << endl;
        NofPackets[elapsedSeconds] = queue.size();
        elapsedSeconds += T;
    }
    int packet_max = NofPackets[0];
    int average = 0;

    ofstream aa("result.txt");
    for (int i = 0; i < 120; i++) {
        aa << i << " " << NofPackets[i] << endl;
        average += NofPackets[i];
        if (NofPackets[i] > packet_max) {
            packet_max = NofPackets[i];
        }
    }
    average /= 120;
    aa.close();
    cout << "average: " << average << "\n";
    cout << "maximum: " << packet_max << endl;

    return 0;
}
