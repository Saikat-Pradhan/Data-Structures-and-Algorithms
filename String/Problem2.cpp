// ADD TWO BINARY STRINGS
#include <bits/stdc++.h>
using namespace std;

string trimLeadingZeros(string s) {
    int i = 0;
    while (i < s.length() && s[i] == '0') {
        i++;
    }
    if (i == s.length()) return "0";
    return s.substr(i);
}

string addBinary(string s1, string s2) {
    s1 = trimLeadingZeros(s1);
    s2 = trimLeadingZeros(s2);

    if (s1.length() < s2.length()) {
        return addBinary(s2, s1);
    }

    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;

    while (i >= 0) {
        int sum = (s1[i] - '0') + carry;
        if (j >= 0) sum += (s2[j] - '0');

        s1[i] = (sum % 2) + '0';
        carry = sum / 2;

        i--; j--;
    }

    if (carry) s1 = '1' + s1;

    return s1;
}

int main() {
    string s1, s2;

    cout<<"Enter 1st string: ";
    cin >> s1;
    
    cout<<"Enter 2nd string: ";
    cin>> s2;

    cout <<"Sum of this two binary strings is: "<< addBinary(s1, s2);
    return 0;
}