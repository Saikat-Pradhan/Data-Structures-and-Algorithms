// ALLOCATE MINIMUM PAGES
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/* ---------- Check Function ---------- */
bool check(vector<int> &arr, int k, int pageLimit) {
    int cnt = 1;       // number of students
    int pageSum = 0;  // pages allocated to current student

    for (int i = 0; i < arr.size(); i++) {
        if (pageSum + arr[i] > pageLimit) {
            cnt++;               // allocate to next student
            pageSum = arr[i];
        } else {
            pageSum += arr[i];
        }
    }

    return cnt <= k;
}

/* ---------- Find Minimum Pages ---------- */
int findPages(vector<int> &arr, int k) {
    if (k > arr.size())
        return -1;

    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(arr, k, mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return res;
}

/* ---------- Main Function ---------- */
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findPages(arr, k);
    return 0;
}