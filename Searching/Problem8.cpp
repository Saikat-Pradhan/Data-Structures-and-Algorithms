// K-TH MISSING POSITIVE NUMBER
#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int> &arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int res = arr.size() + k;

    // Binary search
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        // Missing numbers till index mid = arr[mid] - (mid + 1)
        if (arr[mid] > mid + k) {
            res = mid + k;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << kthMissing(arr, k);
    return 0;
}