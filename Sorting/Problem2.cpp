// FIND H-INDEX
#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();

    for (int i = 0; i < n; i++) {
        if (citations[i] >= n - i) {
            return n - i;
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> citations(n);
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    cout << hIndex(citations) << endl;

    return 0;
}