// SORT 0S, 1S AND 2S
#include <bits/stdc++.h>
using namespace std;

// TC - O(2n), SC - O(1)
void sort012(vector<int>& arr) {
    int n = arr.size();
    int c0 = 0, c1 = 0, c2 = 0;

    // Count number of 0s, 1s and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }

    int idx = 0;

    // Place all 0s
    for (int i = 0; i < c0; i++)
        arr[idx++] = 0;

    // Place all 1s
    for (int i = 0; i < c1; i++)
        arr[idx++] = 1;

    // Place all 2s
    for (int i = 0; i < c2; i++)
        arr[idx++] = 2;
}

// TC - O(n), SC - O(1)
void sort012(vector<int> &arr) {
    int n = arr.size();
    
    // initialize three pointers:
    // lo: boundary for 0s
    // mid: current element being checked
    // hi: boundary for 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    
    // process elements until mid crosses hi
    while (mid <= hi) {
        if (arr[mid] == 0) {
            
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort012(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}