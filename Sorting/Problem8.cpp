// MEDIAN OF TWO SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;

// Function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap + 1) / 2;
}

// Function to find median of two sorted arrays
double medianOf2(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    int gap = nextGap(n + m);

    // Gap-based merge
    while (gap > 0) {
        int i = 0, j = gap;

        while (j < n + m) {
            // a vs a
            if (i < n && j < n) {
                if (a[i] > a[j])
                    swap(a[i], a[j]);
            }
            // a vs b
            else if (i < n && j >= n) {
                if (a[i] > b[j - n])
                    swap(a[i], b[j - n]);
            }
            // b vs b
            else {
                if (b[i - n] > b[j - n])
                    swap(b[i - n], b[j - n]);
            }
            i++;
            j++;
        }
        gap = nextGap(gap);
    }

    int total = n + m;

    // Odd total length
    if (total % 2 == 1) {
        int idx = total / 2;
        if (idx < n) return a[idx];
        else return b[idx - n];
    }

    // Even total length
    int idx1 = total / 2 - 1;
    int idx2 = total / 2;

    double val1 = (idx1 < n) ? a[idx1] : b[idx1 - n];
    double val2 = (idx2 < n) ? a[idx2] : b[idx2 - n];

    return (val1 + val2) / 2.0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << medianOf2(a, b) << endl;

    return 0;
}