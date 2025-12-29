// K-TH ELEMENT OF TWO SORTED ARRAY
#include <iostream>
#include <vector>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int pos = 0, i = 0, j = 0;

    // Merge-like traversal
    while (i < a.size() && j < b.size()) {
        pos++;

        if (a[i] <= b[j]) {
            if (pos == k)
                return a[i];
            i++;
        } else {
            if (pos == k)
                return b[j];
            j++;
        }
    }

    // Remaining elements of a
    while (i < a.size()) {
        pos++;
        if (pos == k)
            return a[i];
        i++;
    }

    // Remaining elements of b
    while (j < b.size()) {
        pos++;
        if (pos == k)
            return b[j];
        j++;
    }

    return -1; // safety
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << kthElement(a, b, k);
    return 0;
}