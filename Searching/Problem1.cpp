// COUNT FREQUENCY  IN A SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;

/* -------------------- METHOD 1: Binary Search -------------------- */

int firstOcc(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;   // search left
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;   // search right
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int countFreq_BinarySearch(vector<int>& arr, int target) {
    int first = firstOcc(arr, target);
    if (first == -1) return 0;

    int last = lastOcc(arr, target);
    return last - first + 1;
}

/* -------------------- METHOD 2: STL (lower_bound & upper_bound) -------------------- */

int countFreq_STL(vector<int>& arr, int target) {
    int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return r - l;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    cout << "Using Binary Search method: "
         << countFreq_BinarySearch(arr, target) << endl;

    cout << "Using STL method: "
         << countFreq_STL(arr, target) << endl;

    return 0;
}