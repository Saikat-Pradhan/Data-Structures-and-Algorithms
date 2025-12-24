// MAXIMUM SUM SUBARRAY
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxSubArrSum(vector<int> arr){
    int n=arr.size();
    int maxEnding = arr[0];
    int res = arr[0];

    for(int i=0;i<n;i++){
       maxEnding = max(maxEnding + arr[i], arr[i]);

       res = max(res, maxEnding);
    }

    return res;
}

int main() {
    vector<int> arr;
    int n,x,maxSum;

    cout<<"Enter total number of elements: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    maxSum = maxSubArrSum(arr);

    cout<<"Maximum sum subarray is: "<<maxSum;
   
    return 0;
}
