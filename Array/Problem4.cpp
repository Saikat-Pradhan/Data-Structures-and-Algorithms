// ROTATE AN ARRAY
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseArray(vector<int> &arr,int i, int j){
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void rotateArray(vector<int> &arr, int r){
    int n=arr.size();

    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, n-r-1);
    reverseArray(arr, n-r, n-1);
}

int main() {
    vector<int> arr;
    int n,x,r;

    cout<<"Enter total number of elements: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    cout<<"Enter the total rotation: ";
    cin>>r;

    rotateArray(arr, r);

    cout<<"After rotation the array is became: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
