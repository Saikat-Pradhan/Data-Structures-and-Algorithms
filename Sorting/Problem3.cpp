// COUNT INVERSIONS
#include <bits/stdc++.h>
using namespace std;

// Merge two sorted halves and count inversions
int countAndMerge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    int res = 0;

    // Merge and count inversions
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            res += (n1 - i); // all remaining elements in left are greater
        }
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Recursive function to count inversions
int countInv(vector<int>& arr, int l, int r) {
    int res = 0;

    if (l < r) {
        int m = (l + r) / 2;

        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }

    return res;
}

// Wrapper function
int inversionCount(vector<int>& arr) {
    int n = arr.size();
    return countInv(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << inversionCount(arr) << endl;

    return 0;
}