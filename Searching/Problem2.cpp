// FIND MINIMUM IN ROTATED ARRAY
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {

        // If array part is already sorted
        if (arr[low] < arr[high]) {
            return arr[low];
        }

        int mid = (low + high) / 2;

        // Minimum lies in right half
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        // Minimum lies in left half (including mid)
        else {
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findMin(arr) << endl;

    return 0;
}