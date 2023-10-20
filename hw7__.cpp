int main() {
    ifstream file("mybin4.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int intValue;
    file.read(reinterpret_cast<char*>(&intValue), sizeof(int));
    cout << "Value1: " << intValue << endl;

    int intArray[5];
    file.read(reinterpret_cast<char*>(intArray), sizeof(intArray));
    cout << "Int Array:" << endl;
    printArray(intArray, 5);

    float floatArray[3];
    file.read(reinterpret_cast<char*>(floatArray), sizeof(floatArray));
    cout << "Float Array:" << endl;
    printArray(floatArray, 3);

    file.close();

    return 0;
}
