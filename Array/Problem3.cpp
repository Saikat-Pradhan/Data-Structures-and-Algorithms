// REVERSE AN ARRAY
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseArray(vector<int> &arr){
    int n=arr.size();
    int i=0, j=n-1;

    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> arr;
    int n,x;

    cout<<"Enter total number of elements:";
    cin>>n;

    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    reverseArray(arr);

    cout<<"After reversing the array is became: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
