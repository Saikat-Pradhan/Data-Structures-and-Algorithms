// STRING ROTATIONS OF EACH OTHER
#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2) {
    // If lengths are different, cannot be rotations
    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s1;

    // Check if s2 is substring of temp
    if (temp.find(s2) == string::npos)
        return false;
    else
        return true;
}

int main() {
    string s1, s2;

    cout<<"Enter 1st string: ";
    cin >> s1;
    
    cout<<"Enter 2nd string: ";
    cin>> s2;

    if (areRotations(s1, s2))
        cout <<"Is they are rotations? : "<< "Yes";
    else
        cout <<"Is they are rotations? : "<< "No";

    return 0;
}