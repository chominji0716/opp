#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <numeric>
#include <Windows.h>

class Queue {
private:
    int NI;                       // 최대 입력 패킷 수
    int NO;                       // 최대 송출 패킷 수
    int capacity;                 // 큐의 최대 용량
    std::vector<int> packets;     // 패킷 큐
    int totalPacketsLost;         // 총 손실된 패킷 수
    int totalGeneratedPackets;    // 총 생성된 패킷 수
    std::vector<double> fullnessPercentageList; // 각 시간 간격의 큐 가득 참 정도를 저장하는 리스트
    std::vector<double> lossRateList;           // 각 시간 간격의 손실률을 저장하는 리스트

public:
    Queue(int ni, int no, int cap) : NI(ni), NO(no), capacity(cap), totalPacketsLost(0), totalGeneratedPackets(0) {
        // 랜덤 시드 초기화
        std::srand(static_cast<unsigned>(std::time(0)));
        elapsedSeconds = 0;
    }
    int elapsedSeconds;

    void simulate(int totalTime, int timeInterval) {
        std::ofstream resultFile("result.txt");

        while (elapsedSeconds < totalTime) {
            Sleep(timeInterval * 1000);
            // 시간 경과를 시뮬레이션합니다.
            std::vector<int> incomingPackets, outgoingPackets;

            // 랜덤으로 입력 및 송출 패킷을 생성합니다.
            int ni = std::rand() % NI;
            int no = std::rand() % NO;

            totalGeneratedPackets += ni;

            // 큐에 입력 패킷이 수용 가능한 용량인지 확인합니다.
            if (ni > capacity) {
                // Overflow: 큐 용량보다 많은 입력 패킷이 들어오면 발생하는 상황
                int lost = ni - capacity;
                totalPacketsLost += lost;
                ni = capacity; // 손실된 패킷을 고려하여 ni를 조정합니다.
                std::cout << "용량 초과로 " << lost << "개의 패킷이 손실되었습니다." << std::endl;
            }

            // 송출할 패킷이 큐에 있는 패킷 수보다 많은지 확인합니다.
            if (no > packets.size()) {
                // Underflow: 큐에 있는 패킷 수보다 많은 패킷을 송출하려고 할 때 발생하는 상황
                no = packets.size();
                std::cout << "큐에 있는 패킷이 부족하여 송출되지 않았습니다." << std::endl;
            }

            // 입력 패킷을 큐에 추가합니다.
            for (int i = 0; i < ni; ++i) {
                if (packets.size() < capacity) {
                    packets.push_back(std::rand() % 20);
                }
                else {
                    // 큐가 이미 가득 차 있으면 손실된 패킷 수를 증가시킵니다.
                    totalPacketsLost++;
                }
            }

            // 큐에서 송출할 패킷을 제거합니다.
            for (int i = 0; i < no && !packets.empty(); ++i) {
                packets.erase(packets.begin());
            }

            // 큐의 가득 참 정도를 계산합니다.
            double fullnessPercentage = static_cast<double>(packets.size()) / capacity * 100;
            fullnessPercentageList.push_back(fullnessPercentage);

            // 손실률을 계산합니다.
            double lossRate = static_cast<double>(totalPacketsLost) / totalGeneratedPackets * 100;
            lossRateList.push_back(lossRate);

            // 큐에 있는 패킷 수를 출력합니다.
            std::cout << "Packets[" << elapsedSeconds + timeInterval << "]: " << packets.size() << std::endl;

            // 결과를 파일에 기록합니다.
            resultFile << elapsedSeconds + timeInterval << " " << packets.size() << std::endl;

            elapsedSeconds += timeInterval;
        }

        // 평균 큐의 가득 참 정도를 출력합니다.
        double averageFullness = std::accumulate(fullnessPercentageList.begin(), fullnessPercentageList.end(), 0.0) / fullnessPercentageList.size();
        std::cout << "평균 큐 가득 참 정도: " << averageFullness << "%" << std::endl;

        // 평균 손실률을 출력합니다.
        double averageLossRate = std::accumulate(lossRateList.begin(), lossRateList.end(), 0.0) / lossRateList.size();
        std::cout << "평균 손실률: " << averageLossRate << "%" << std::endl;

        // 결과 파일을 닫습니다.
        resultFile.close();
    }
};

int main() {
    // NI=700, NO=100, capacity=100인 Queue 객체를 생성합니다.
    Queue myQueue(700, 100, 100);

    // 120초 동안 1초 간격으로 시뮬레이션을 실행합니다.
    myQueue.simulate(120, 1);

    return 0;
}
