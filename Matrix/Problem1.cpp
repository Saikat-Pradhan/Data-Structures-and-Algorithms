// SPIRAL MATRIX TRAVERSAL
#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> res;

    while (top <= bottom && left <= right) {

        // Top row
        for (int i = left; i <= right; i++)
            res.push_back(mat[top][i]);
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            res.push_back(mat[i][right]);
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                res.push_back(mat[bottom][i]);
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                res.push_back(mat[i][left]);
            left++;
        }
    }

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = spirallyTraverse(mat);

    for (int x : ans)
        cout << x << " ";

    return 0;
}