#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 4; // Example size

void findMaxMin(double arr[], int size, string name) {
    double maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < size; i++) {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }
    cout << "Max " << name << ": " << maxVal << ", Min " << name << ": " << minVal << endl;
}

void calculateAverage(double arr[], int size, string name) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Average " << name << ": " << sum / size << endl;
}

void sortByParameter(double arr[], int size, string name) {
    sort(arr, arr + size);
    cout << name << " sorted in ascending order." << endl;
}

int main() {
    double temperature[SIZE] = {32.5, 30.8, 28.1, 34.0};
    double humidity[SIZE] = {65.0, 70.2, 60.4, 80.0};
    double pollution[SIZE] = {40.2, 55.3, 20.8, 60.1};

    findMaxMin(temperature, SIZE, "Temperature");
    findMaxMin(humidity, SIZE, "Humidity");
    findMaxMin(pollution, SIZE, "Pollution");

    calculateAverage(temperature, SIZE, "Temperature");
    calculateAverage(humidity, SIZE, "Humidity");
    calculateAverage(pollution, SIZE, "Pollution");

    sortByParameter(temperature, SIZE, "Temperature");

    return 0;
}
