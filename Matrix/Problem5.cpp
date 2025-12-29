// SEARCH IN A SORTED MATRIX
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // if x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // if x is greater than mat[row][col], search 
        // in right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // if x is less than mat[row][col], search 
        // in left half
        else 
            hi = mid - 1;
    }
    return false;
}

/* ----------- Main Function ----------- */
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

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}