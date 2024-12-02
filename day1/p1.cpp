// Day 1, Question 1.
// Given two arrays, find the distance between adjacent elements after sorting them.

#include <bits/stdc++.h>
using namespace std;

// quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// construct array from file input
// the file contains two columns of integers
// the first column is the first array
// the second column is the second array

void constructArrayFromFile(string filename, int arr1[], int arr2[]) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File not found" << endl;
        exit(1);
    }

    string line;
    int i = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            if (i % 2 == 0) {
                arr1[i / 2] = stoi(word);
            }
            else {
                arr2[i / 2] = stoi(word);
            }
            i++;
        }
    }
}

int main() {
    int arr1[1000], arr2[1000];

    string filename;
    cout << "Enter the filename in relative format: ";
    cin >> filename;

    constructArrayFromFile(filename, arr1, arr2);

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    quickSort(arr1, 0, n1 - 1);
    quickSort(arr2, 0, n2 - 1);

    int distance = 0;

    for (int i = 0; i < n1; i++) {
        distance += abs(arr1[i] - arr2[i]);
    }

    cout << distance << endl;
}