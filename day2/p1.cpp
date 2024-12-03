// Day 2, Problem 1

// Considerations:
// 1. This question can also be solved with just reading the file and counting the rows.
//    I'm creating a 2D vector just for elegance.

#include <bits/stdc++.h>
using namespace std;

void constructArrayFromFile(string filename, vector<vector<int>> &arr)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "File not found" << endl;
        exit(1);
    }
    int lineCount = 0;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        arr.push_back(vector<int>());
        while (ss >> word)
        {
            arr[lineCount].push_back(stoi(word));
        }
        lineCount++;
    }
}

int main()
{
    vector<vector<int>> arr;

    string filename;
    cout << "Enter the filename in relative format: ";
    cin >> filename;

    constructArrayFromFile(filename, arr);

    int safeRows = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].size() < 2)
        {
            safeRows++;
            continue;
        }
        bool isAscending = arr[i][0] < arr[i][1];
        bool isSafe = true;

        for (int j = 0; j < arr[i].size() - 1; j++)
        {
            if (isAscending) {
                if (arr[i][j] >= arr[i][j + 1] || arr[i][j + 1] - arr[i][j] > 3) {
                    isSafe = false;
                    break;
                }
            } else {
                if (arr[i][j] <= arr[i][j + 1] || arr[i][j] - arr[i][j + 1] > 3) {
                    isSafe = false;
                    break;
                }
            }
        }

        if (isSafe) {
            safeRows++;
        }
    }
    cout << safeRows << endl;
}