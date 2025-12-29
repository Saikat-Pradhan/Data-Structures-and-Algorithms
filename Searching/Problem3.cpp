// SEARCH IN ROTATED SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> &arr, int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Find pivot (index of minimum element)
int findPivot(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        if (arr[low] <= arr[high])
            return low;

        int mid = (low + high) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Search function
int searchRotated(vector<int> &arr, int key) {
    int n = arr.size();
    int pivot = findPivot(arr);

    // If key is at pivot
    if (arr[pivot] == key)
        return pivot;

    // If array is not rotated
    if (pivot == 0)
        return binarySearch(arr, 0, n - 1, key);

    // Decide which side to search
    if (key >= arr[0])
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot, n - 1, key);
}

int main() {
    int n, key;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    cout << searchRotated(arr, key) << endl;
    return 0;
}