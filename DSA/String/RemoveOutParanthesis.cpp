#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
Idea: Remove the outermost parentheses of every primitive string in the given valid parentheses string.

Approach:
1. Use a stack to keep track of the parentheses.
2. Traverse the string character by character.
3. For each '(', if the stack is not empty, add it to the result string and push it onto the stack.
4. For each ')', pop the stack and if the stack is not empty, add it to the result string.
5. This ensures that the outermost parentheses are not added to the result string.

Time Complexity: O(n) - We traverse the string once.
Space Complexity: O(n) - We use a stack to keep track of the parentheses.
*/

string removeOuterParentheses(string s) {
    string result = "";
    stack<char> stk;

    for (char c : s) {
        if (c == '(') {
            if (!stk.empty()) result += c;
            stk.push(c);
        } else {
            stk.pop();
            if (!stk.empty()) result += c;
        }
    }

    return result;
}

int main() {
    // Test case 1: Remove outer parentheses from "(()())(())"
    // Explanation: The result should be "()()()"
    string s1 = "(()())(())";
    cout << "Original: " << s1 << endl;
    cout << "After removing outer parentheses: " << removeOuterParentheses(s1) << endl;

    // Test case 2: Remove outer parentheses from "(()())(())(()(()))"
    // Explanation: The result should be "()()()()(())"
    string s2 = "(()())(())(()(()))";
    cout << "Original: " << s2 << endl;
    cout << "After removing outer parentheses: " << removeOuterParentheses(s2) << endl;

    // Test case 3: Remove outer parentheses from "()()"
    // Explanation: The result should be ""
    string s3 = "()()";
    cout << "Original: " << s3 << endl;
    cout << "After removing outer parentheses: " << removeOuterParentheses(s3) << endl;

    // Test case 4: Remove outer parentheses from "((()))"
    // Explanation: The result should be "(())"
    string s4 = "((()))";
    cout << "Original: " << s4 << endl;
    cout << "After removing outer parentheses: " << removeOuterParentheses(s4) << endl;

    return 0;
}