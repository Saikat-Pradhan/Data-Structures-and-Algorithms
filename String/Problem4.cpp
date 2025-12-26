// FIRST NON REPEATING CHARACTER
#include <bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string s) {
    unordered_map<char, int> mp;

    // Count frequency of each character
    for (char c : s) {
        mp[c]++;
    }

    // Find first non-repeating character
    for (char c : s) {
        if (mp[c] == 1) {
            return c;
        }
    }

    return '$';
}

int main() {
    string s;

    cout<<"Enter your string: ";
    cin >> s;

    char result = nonRepeatingChar(s);
    cout <<"First Non repeating character: "<< result << endl;

    return 0;
}