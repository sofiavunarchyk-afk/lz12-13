#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    int n = 0;
    int arr[100];

    ifstream fin("matrix.txt");

    if (!fin) {
        cout << "Error: Could not open 'matrix.txt'" << endl;
        return 1;
    }

    while (n < 100 && fin >> arr[n]) {
        n++;
    }

    fin.close();

    if (n == 0) {
        cout << "File is empty or contains no numbers." << endl;
        return 1;
    }
    
    cout << "Read " << n << " elements from the file." << endl;

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int diff = maxVal - minVal;

    cout << "\nMin element: " << minVal << endl;
    cout << "Max element: " << maxVal << endl;
    cout << "Difference (max - min): " << diff << endl;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "\nArray after sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int diffSorted = arr[n - 1] - arr[0];
    cout << "\nCheck: last - first = " << diffSorted << endl;

    if (diffSorted == diff)
        cout << "Check passed: results match.\n";
    else
        cout << "Check failed: results mismatch.\n";

    return 0;
}