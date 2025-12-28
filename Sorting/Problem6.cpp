// NON-OVERLAPPING INTERVALS
#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<vector<int>>& intervals) {
    int cnt = 0;

    // Sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // Overlapping case
        if (intervals[i][0] < end) {
            cnt++;
            end = min(end, intervals[i][1]);
        }
        // Non-overlapping case
        else {
            end = intervals[i][1];
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    cout << minRemoval(intervals) << endl;

    return 0;
}