// INSERT AND MERGE INTERVAL
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int>& newInterval) {
    // Step 1: Insert new interval
    intervals.push_back(newInterval);

    // Step 2: Sort intervals
    sort(intervals.begin(), intervals.end());

    int idx = 0;

    // Step 3: Merge intervals
    for (int i = 1; i < intervals.size(); i++) {
        // Overlapping case
        if (intervals[idx][1] >= intervals[i][0]) {
            intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
        }
        // Non-overlapping case
        else {
            idx++;
            intervals[idx] = intervals[i];
        }
    }

    // Step 4: Resize to remove extra intervals
    intervals.resize(idx + 1);
    return intervals;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    // Print result
    for (auto& interval : result) {
        cout << interval[0] << " " << interval[1] << "\n";
    }

    return 0;
}
