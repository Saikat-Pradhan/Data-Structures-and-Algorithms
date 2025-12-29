// SET MATRIX ZEROES
#include <iostream>
#include <vector>
using namespace std;

/* ----------- Method 1: Using Extra Space ----------- */
void setMatrixZeroes1(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> row(n, 1), col(m, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 0 || col[j] == 0)
                mat[i][j] = 0;
        }
    }
}

/* ----------- Method 2: Without Extra Space ----------- */
void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    bool firstRow = false, firstCol = false;

    // Check first column
    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 0)
            firstCol = true;
    }

    // Check first row
    for (int j = 0; j < m; j++) {
        if (mat[0][j] == 0)
            firstRow = true;
    }

    // Use first row and column as markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    // Set matrix zeroes
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0)
                mat[i][j] = 0;
        }
    }

    // Zero first row
    if (firstRow) {
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;
    }

    // Zero first column
    if (firstCol) {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
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

    // Call any one
    setMatrixZeroes(mat);
    // setMatrixZeroes1(mat);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}