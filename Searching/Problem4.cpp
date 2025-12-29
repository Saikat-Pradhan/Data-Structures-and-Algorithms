// PEAK ELEMENT
#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();
    
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        // If rising slope, peak is on right
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;   // peak index
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << peakElement(arr);
    return 0;
}