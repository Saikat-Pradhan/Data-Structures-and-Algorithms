// FIND Second Largest Element
#include<iostream>
#include<vector>
using namespace std;

void findSecondLargest(vector<int> arr){
    int max=arr[0];
    int secMax=arr[0];
    int n=arr.size();

    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]<max && arr[i]>secMax){
            secMax=arr[i];
        }
    }

    cout<<"Second Largest Element of the array is: "<<secMax;
}

int main() {
    vector<int> arr;
    int n,x;

    cout<<"Enter total number of elements: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    findSecondLargest(arr);
    
    return 0;
}
