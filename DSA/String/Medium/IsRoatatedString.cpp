#include <iostream>
#include <string>

using namespace std;

/*
Idea: Check if one string is a rotation of another string.

Approach:
1. If the sizes of the strings are different, return false.
2. Use a loop to rotate the first string by one character at a time.
3. After each rotation, check if the rotated string matches the goal string.
4. If a match is found, return true.
5. If no match is found after all rotations, return false.

Time Complexity: O(n^2) - We perform n rotations, and each rotation takes O(n) time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    int i = 0;

    while (i < s.size()) {
        if (s == goal) return true;
        else {
            char c = s.front();
            s.erase(s.begin());
            s.push_back(c);
            i++;
        }
    }

    return false;
}

int main() {
    // Test case 1: "abcde" and "cdeab" are rotations of each other
    // Explanation: Rotating "abcde" by 2 positions to the left gives "cdeab"
    string s1 = "abcde";
    string goal1 = "cdeab";
    cout << "Are \"" << s1 << "\" and \"" << goal1 << "\" rotations of each other? " << (rotateString(s1, goal1) ? "Yes" : "No") << endl;

    // Test case 2: "abcde" and "abced" are not rotations of each other
    // Explanation: No rotation of "abcde" gives "abced"
    string s2 = "abcde";
    string goal2 = "abced";
    cout << "Are \"" << s2 << "\" and \"" << goal2 << "\" rotations of each other? " << (rotateString(s2, goal2) ? "Yes" : "No") << endl;

    // Test case 3: "aaaaa" and "aaaaa" are rotations of each other
    // Explanation: Any rotation of "aaaaa" gives "aaaaa"
    string s3 = "aaaaa";
    string goal3 = "aaaaa";
    cout << "Are \"" << s3 << "\" and \"" << goal3 << "\" rotations of each other? " << (rotateString(s3, goal3) ? "Yes" : "No") << endl;

    // Test case 4: "abc" and "cab" are rotations of each other
    // Explanation: Rotating "abc" by 2 positions to the left gives "cab"
    string s4 = "abc";
    string goal4 = "cab";
    cout << "Are \"" << s4 << "\" and \"" << goal4 << "\" rotations of each other? " << (rotateString(s4, goal4) ? "Yes" : "No") << endl;

    return 0;
}