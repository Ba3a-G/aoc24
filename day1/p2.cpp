// Day 1, Question 2.
// Given two arrays, find how many times an element in arr1 appears in arr2 and multiply and sum them.

#include <bits/stdc++.h>
using namespace std;

void constructArrayAndMapFromFile(string filename, int arr1[], unordered_map<string, int> &freq) {
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
                if (freq.find(word) == freq.end()) {
                    freq[word] = 1;
                }
                else {
                    freq[word]++;
                }
            }
            i++;
        }
    }
}

int main() {
    int arr1[1000];
    unordered_map<string, int> freq;

    string filename;
    cout << "Enter the filename in relative format: ";
    cin >> filename;

    constructArrayAndMapFromFile(filename, arr1, freq);

    int sum = 0;

    for (int i = 0; i < 1000; i++) {
        string key = to_string(arr1[i]);
        if (freq.find(key) != freq.end()) {
            sum += freq[key] * arr1[i];
        }
    }

    cout << sum << endl;

}