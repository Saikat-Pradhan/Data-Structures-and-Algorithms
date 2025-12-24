/*
  FIND OUT THE MINIMUM POSSIBLE DIFFERENCE BETWEEN THE HEIGHT OF THE SHORTEST AND TALLEST TOWERS AFTER INCREASE OR DECRESE
  THE HEIGHT OF THE TOWERS BY K.
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDiffOfHeights(vector<int> &arr, int k){
    int n = arr.size();
    if (n == 1) return 0;  

    sort(arr.begin(), arr.end());

    int res = arr[n-1] - arr[0];  

    for (int i = 0; i < n-1; i++) {
        int minH = min(arr[0] + k, arr[i+1] - k);
        int maxH = max(arr[n-1] - k, arr[i] + k);
        res = min(res, maxH - minH);
    }

    return res;
}

int main() {
    vector<int> arr;
    int n,x,k,diff;

    cout<<"Enter total number of the towers: ";
    cin>>n;

    cout<<"Enter the heights of the towers: ";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    cout<<"Enter the value of k: ";
    cin>>k;

    diff = minDiffOfHeights(arr, k);

    cout<<"Minimum difference of the heights by increase or decrease is: "<<diff;
    
    return 0;
}

