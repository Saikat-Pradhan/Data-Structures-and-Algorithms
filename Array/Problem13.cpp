// MOVE ALL ZEROS TO END
#include<iostream>
#include<vector>
using namespace std;

int smallestMissingPositive(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Place each number at its correct index
    for (int i = 0; i < n; i++) {
        // Keep swapping until arr[i] is either:
        // - out of range [1, n]
        // - already in correct position
        while (arr[i] >= 1 && arr[i] <= n &&
               arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // Step 2: Find the first index where value is incorrect
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    // Step 3: If all numbers 1..n are present
    return n + 1;
}

int main() {
    vector<int> arr;
    int n,x,firstMisPositive;

    cout<<"Enter total number of elements:";
    cin>>n;

    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    firstMisPositive = smallestMissingPositive(arr);

    cout<<"After moving all zeros to end the array is became: "<<firstMisPositive;
   
    return 0;
}
