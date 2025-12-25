// MAXIMUM PRODUCT SUBARRAY
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubArrProduct(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MIN;

    int leftProd = 1, rightProd = 1;

    for (int i = 0; i < n; i++)
    {

        // Left to Right
        leftProd *= arr[i];
        ans = max(ans, leftProd);
        if (leftProd == 0)
            leftProd = 1;

        // Right to Left
        rightProd *= arr[n - i - 1];
        ans = max(ans, rightProd);
        if (rightProd == 0)
            rightProd = 1;
    }

    return ans;
}

int main()
{
    vector<int> arr;
    int n, x, maxProduct;

    cout << "Enter total number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    maxProduct = maxSubArrProduct(arr);

    cout << "Maximum product subarray is: " << maxProduct;

    return 0;
}
