// CALCULATE NEXT PERMUTATION
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int> &arr, int i, int j) {
    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

vector<int> nextPermutation(vector<int> arr) {
    int n = arr.size();
    int pivot = -1;

    // Step 1: Find the pivot (rightmost index where arr[i] < arr[i+1])
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Step 2: If no pivot, reverse entire array and return (last permutation → first permutation)
    if (pivot == -1) {
        reverseArray(arr, 0, n - 1);
        return arr;
    }

    // Step 3: Find rightmost element greater than pivot
    int pos = -1;
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            pos = i;
            break;
        }
    }

    // Step 4: Swap pivot and pos
    swap(arr[pivot], arr[pos]);

    // Step 5: Reverse suffix (pivot+1 to end)
    reverseArray(arr, pivot + 1, n - 1);

    return arr;
}

int main() {
    vector<int> arr;
    int n, x;

    cout << "Enter total number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    vector<int> brr = nextPermutation(arr);

    cout << "Next permutation: ";
    for (int i = 0; i < n; i++) {
        cout << brr[i] << " ";
    }
    cout << endl;

    return 0;
}