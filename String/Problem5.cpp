// KMP ALGORITHM FOR PATTERN SEARCHING
#include <bits/stdc++.h>
using namespace std;

// Function to create LPS array
vector<int> lpsCreation(string pat) {
    int n = pat.length();
    vector<int> lps(n, 0);

    int len = 0;   // length of previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP search function
vector<int> search(string pat, string txt) {
    vector<int> lps = lpsCreation(pat);
    vector<int> res;

    int i = 0, j = 0;
    int n = txt.length();
    int m = pat.length();

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            res.push_back(i - j); // 0-based index
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return res;
}

int main() {
    string txt, pat;

    cout<<"Enter text: ";
    cin >> txt;
    
    cout<<"Enter pattern: ";
    cin>> pat;

    vector<int> result = search(pat, txt);

    if (result.empty()) {
        cout << "No match found";
    } else {
        cout<<"Pattern matches in points: ";
        for (int idx : result) {
            cout << idx << " ";
        }
    }

    return 0;
}