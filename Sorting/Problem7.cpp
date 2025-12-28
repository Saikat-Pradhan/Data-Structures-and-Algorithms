// MERGE WITHOUT EXTRA SPACE
#include <bits/stdc++.h>
using namespace std;

/* -------------------- APPROACH 1 -------------------- */

// Helper function to insert last element at correct position
void insert(vector<int>& a) {
    int n = a.size();

    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] <= a[i])
            break;
        swap(a[i - 1], a[i]);
    }
}

void mergeArrays1(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();

    for (int i = m - 1; i >= 0; i--) {
        if (a[n - 1] > b[i]) {
            swap(a[n - 1], b[i]);
            insert(a);
        }
    }
}

/* -------------------- APPROACH 2 -------------------- */

void mergeArrays2(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int i = n - 1, j = 0;

    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
        i--;
        j++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

/* -------------------- APPROACH 3 (GAP METHOD) -------------------- */

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void mergeArrays3(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int gap = nextGap(n + m);

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
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // Choose any one approach
    // mergeArrays1(a, b);
    // mergeArrays2(a, b);
    mergeArrays3(a, b);   // Efficient gap method

    // Print result
    for (int x : a) cout << x << " ";
    for (int x : b) cout << x << " ";

    return 0;
}