#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>  // for pow()
using namespace std;

// Selection Sort
void selectionSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Bubble Sort
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// Insertion Sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Shell Sort
void shellSort(float arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
}

// Quick Sort helper
int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Quick Sort
void quickSort(float arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort helper - counting sort by digit
void countingSort(float arr[], int n, int exp) {
    float output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = ((int)(arr[i] * 100) / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int digit = ((int)(arr[i] * 100) / exp) % 10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort (for floating points scaled by 100)
void radixSort(float arr[], int n) {
    // Find max to know number of digits
    float maxVal = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal) maxVal = arr[i];

    // Scale values to integers (2 decimals precision)
    int maxInt = (int)(maxVal * 100);

    // Do counting sort for every digit (exp = 1, 10, 100, ...)
    for (int exp = 1; maxInt / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Display array
void display(float arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Display top five scores (or less)
void displayTopFive(float arr[], int n) {
    cout << "\nTop 5 Scores: ";
    int start = (n >= 5) ? n - 5 : 0;
    for (int i = n - 1; i >= start; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, choice, inputChoice;
    cout << "Enter number of students: ";
    cin >> n;
    float marks[n];

    cout << "Input marks manually (1) or generate randomly (2)? ";
    cin >> inputChoice;

    if(inputChoice == 1) {
        cout << "Enter marks:\n";
        for(int i = 0; i < n; i++)
            cin >> marks[i];
    } else {
        srand(time(0));
        for(int i = 0; i < n; i++)
            marks[i] = (rand() % 101) + ((rand() % 100)/100.0);  // 0.00 to 100.99 approx
        cout << "Random marks generated: ";
        display(marks, n);
    }

    cout << "\nChoose sorting method:\n";
    cout << "1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Shell Sort\n5. Quick Sort\n6. Radix Sort\nEnter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: selectionSort(marks, n); break;
        case 2: bubbleSort(marks, n); break;
        case 3: insertionSort(marks, n); break;
        case 4: shellSort(marks, n); break;
        case 5: quickSort(marks, 0, n-1); break;
        case 6: radixSort(marks, n); break;
        default: cout << "Invalid choice. Exiting.\n"; return 0;
    }

    cout << "\nSorted marks in ascending order:\n";
    display(marks, n);
    displayTopFive(marks, n);

    return 0;
}
