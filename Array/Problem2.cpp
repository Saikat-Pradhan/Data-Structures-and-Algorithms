// MOVE ALL ZEROS TO END
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sendZerosToEnd(vector<int> &arr){
    int n=arr.size();
    int count=0;

    for(int i=0;i<n;i++){
       if(arr[i]!=0) {
         swap(arr[i],arr[count]);
         count++;
       }
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

    sendZerosToEnd(arr);

    cout<<"After moving all zeros to end the array is became: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
