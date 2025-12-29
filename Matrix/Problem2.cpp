// ROTATE MATRIX BY 90 DEGREES
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ----------- Rotate Matrix Function ----------- */
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

/* ----------- Main Function ----------- */
int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    rotateMatrix(mat);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}