// JUMP GAME - REACH LAST INDEX
#include <bits/stdc++.h>
using namespace std;

bool canReachLastIndex(vector<int>& arr) {
    int maxReach = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // If current index is not reachable
        if (i > maxReach)
            return false;

        // Update the farthest reachable index
        maxReach = max(maxReach, i + arr[i]);

        // If last index is reachable
        if (maxReach >= n - 1)
            return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (canReachLastIndex(arr))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}