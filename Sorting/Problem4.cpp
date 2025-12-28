// MERGE OVERLAPPING INTERVALS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    // Sort intervals
    sort(arr.begin(), arr.end());

    int idx = 0;

    for (int i = 1; i < arr.size(); i++) {
        // Overlapping case
        if (arr[idx][1] >= arr[i][0]) {
            arr[idx][1] = max(arr[idx][1], arr[i][1]);
        }
        // Non-overlapping case
        else {
            idx++;
            arr[idx] = arr[i];
        }
    }

    // Resize to remove extra elements
    arr.resize(idx + 1);
    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> result = mergeOverlap(arr);

    // Print merged intervals
    for (auto& interval : result) {
        cout << interval[0] << " " << interval[1] << "\n";
    }

    return 0;
}