// SEARCH IN A ROW-WISE SORTED MATRIX
#include <iostream>
#include <vector>
using namespace std;

/* -------- Binary Search in a Row -------- */
bool bSearch(vector<int> &arr, int low, int high, int k) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return true;
        else if (arr[mid] > k)
            return bSearch(arr, low, mid - 1, k);
        else
            return bSearch(arr, mid + 1, high, k);
    }
    return false;
}

/* -------- Search in Row-Column Sorted Matrix -------- */
bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        // Check if x can be present in this row
        if (x >= mat[i][0] && x <= mat[i][m - 1]) {
            if (bSearch(mat[i], 0, m - 1, x))
                return true;
        }
    }
    return false;
}

/* -------- Main Function -------- */
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int x;
    cin >> x;

    if (searchRowMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}