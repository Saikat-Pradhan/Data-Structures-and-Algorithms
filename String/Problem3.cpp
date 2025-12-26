// ANAGRAM CHECK
#include <bits/stdc++.h>
using namespace std;

// Method 1: Using sorting
bool areAnagrams1(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2);
}

// Method 2: Using frequency count (unordered_map)
bool areAnagrams2(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> mp;

    for (char c : s1) {
        mp[c]++;
    }

    for (char c : s2) {
        mp[c]--;
    }

    for (auto p : mp) {
        if (p.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1, s2;

    cout<<"Enter 1st string: ";
    cin >> s1;
    
    cout<<"Enter 2nd string: ";
    cin>> s2;

    cout << "Using sorting method: ";
    if (areAnagrams1(s1, s2))
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << "Using map method: ";
    if (areAnagrams2(s1, s2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}