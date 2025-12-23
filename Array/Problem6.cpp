// MAJORITY ELEMENT 2 (Find the elements that have counts greater than [n/3])
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> majorityElement2(vector<int> arr) {
    int n = arr.size();
    vector<int> result;
    unordered_map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Collect elements with count > n/3
    for (auto &p : freq) {
        if (p.second > n / 3) {
            result.push_back(p.first);
        }
    }

    return result;
}

int main() {
    vector<int> arr;
    int n, x;

    cout << "Enter total number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    vector<int> brr = majorityElement2(arr);

    cout << "Majority elements (> n/3 times): ";
    for (int i = 0; i < brr.size(); i++) {
        cout << brr[i] << " ";
    }
    cout << endl;

    return 0;
}