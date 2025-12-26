// MIN CHARACTERS TO ADD IN FRONT FOR MAKING THE STRING PALINDROME
#include <bits/stdc++.h>
using namespace std;

// Function to create LPS array
vector<int> lpsCreation(string pat) {
    int n = pat.length();
    vector<int> lps(n, 0);

    int len = 0;
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

// Function to find minimum characters to add at front
int minChar(string s) {
    int n = s.length();

    string rev = s;
    reverse(rev.begin(), rev.end());

    // Create combined string
    string temp = s + "$" + rev;

    vector<int> lps = lpsCreation(temp);

    // Last LPS value gives longest palindromic prefix
    int longestPalPrefix = lps[temp.length() - 1];

    return n - longestPalPrefix;
}

int main() {
    string s;

    cout<<"Enter your string: ";
    cin >> s;

    cout <<"To make the string palindrome the minimum numbers of character have to add in front is: "<< minChar(s) << endl;

    return 0;
}