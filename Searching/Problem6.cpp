// AGGRESSIVE COWS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ----------- Brute Force Approach ----------- */
int aggressiveCows1(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int res = 0;

    while (true) {
        int cowCount = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= res) {
                cowCount++;
                lastPos = stalls[i];
            }
        }

        if (cowCount < k)
            break;

        res++;
    }

    return res - 1;
}

/* ----------- Optimal Binary Search Approach ----------- */
bool check(vector<int> &stalls, int k, int dist) {
    int cnt = 1;
    int prev = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - prev >= dist) {
            cnt++;
            prev = stalls[i];
        }
    }
    return cnt >= k;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int lo = 1;
    int hi = stalls.back() - stalls.front();
    int res = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(stalls, k, mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return res;
}

/* ----------- Main Function ----------- */
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Brute force result
    cout << aggressiveCows1(stalls, k) << endl;

    // Optimal result
    cout << aggressiveCows(stalls, k) << endl;

    return 0;
}