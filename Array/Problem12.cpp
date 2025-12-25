// MAXIMUM CIRCULAR SUBARRAY SUM
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxCircularSum(vector<int> &arr)
{
    int totalSum = 0;
    int maxSum = INT_MIN, minSum = INT_MAX;
    int currMax = 0, currMin = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        totalSum += arr[i];

        currMax = max(arr[i], currMax + arr[i]);
        maxSum = max(maxSum, currMax);

        currMin = min(arr[i], currMin + arr[i]);
        minSum = min(minSum, currMin);
    }

    // all elements negative
    if (maxSum < 0)
        return maxSum;

    return max(maxSum, totalSum - minSum);
}

int main()
{
    vector<int> arr;
    int n, x, maxSum;

    cout << "Enter total number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    maxSum = maxCircularSum(arr);

    cout << "Maximum circular subarray sum is: " << maxSum;

    return 0;
}
