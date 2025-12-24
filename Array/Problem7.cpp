// STOCK BUY AND SELL WITH MAXIMUM PROFIT(With No Limit)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int> arr){
    int n=arr.size();
    int profit=0;

    for(int i=0;i<n-1;i++){
       if(arr[i] < arr[i+1]) {
         profit+=(arr[i+1] - arr[i]);
       }
    }

    return profit;
}

int main() {
    vector<int> arr;
    int n,x,profit;

    cout<<"Enter total number of days:";
    cin>>n;

    cout<<"Enter the stock price of each days:";
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    profit = maxProfit(arr);

    cout<<"Maximum profit with multiple transactions is: "<<profit;
    
    return 0;
}
