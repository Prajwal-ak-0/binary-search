#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Idea: Calculate the maximum nesting depth of parentheses in a given string.

Approach:
1. Initialize two variables: `cnt` to keep track of the current depth and `mx` to store the maximum depth.
2. Traverse the string character by character.
3. For each '(', increment the `cnt` and update `mx` with the maximum of `mx` and `cnt`.
4. For each ')', decrement the `cnt`.
5. Return the value of `mx` after traversing the entire string.

Time Complexity: O(n) - We traverse the string once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int maxDepth(string s) {
    int cnt = 0, mx = 0;
    for (char c : s) {
        if (c == '(') {
            cnt++;
            mx = max(mx, cnt);
        } else if (c == ')') {
            cnt--;
        }
    }
    return mx;
}

int main() {
    // Test case 1: Maximum depth is 3
    // Explanation: The maximum depth of nested parentheses is 3 in "((()))"
    string s1 = "((()))";
    cout << "Maximum depth of \"" << s1 << "\": " << maxDepth(s1) << endl;

    // Test case 2: Maximum depth is 1
    // Explanation: The maximum depth of nested parentheses is 1 in "()()"
    string s2 = "()()";
    cout << "Maximum depth of \"" << s2 << "\": " << maxDepth(s2) << endl;

    // Test case 3: Maximum depth is 2
    // Explanation: The maximum depth of nested parentheses is 2 in "(())"
    string s3 = "(())";
    cout << "Maximum depth of \"" << s3 << "\": " << maxDepth(s3) << endl;

    // Test case 4: Maximum depth is 0
    // Explanation: There are no parentheses in the string "abc"
    string s4 = "abc";
    cout << "Maximum depth of \"" << s4 << "\": " << maxDepth(s4) << endl;

    return 0;
}