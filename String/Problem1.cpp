//IMPLEMENT ATOI
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string &s) {
    int idx = 0, n = s.length();
    int sign = 1, res = 0;

    // Skip leading spaces
    while (idx < n && s[idx] == ' ') {
        idx++;
    }

    // Check sign
    if (idx < n && (s[idx] == '+' || s[idx] == '-')) {
        if (s[idx] == '-') {
            sign = -1;
        }
        idx++;
    }

    // Convert digits
    while (idx < n && s[idx] >= '0' && s[idx] <= '9') {

        // Overflow handling
        if (res > INT_MAX / 10 || 
           (res == INT_MAX / 10 && (s[idx] - '0') > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + (s[idx] - '0');
        idx++;
    }

    return res * sign;
}

int main() {
    string s;

    cout<<"Enter your string: ";
    getline(cin, s);

    int ans = myAtoi(s);
    cout << "Atoi of this string is: " << ans << endl;

    return 0;
}