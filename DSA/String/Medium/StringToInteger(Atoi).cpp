#include <iostream>
#include <string>
#include <climits>

using namespace std;

/*
Idea: Convert a string to a 32-bit signed integer (similar to C/C++'s atoi function).

Approach:
1. Initialize an index `i` to 0, a sign variable to 1, and a result variable `res` to 0.
2. Skip leading whitespace characters.
3. Check for an optional sign character ('+' or '-'). Update the sign variable accordingly.
4. Traverse the string and convert each digit character to an integer, updating the result.
5. Check for overflow and underflow conditions. If the result exceeds the 32-bit signed integer range, return INT_MAX or INT_MIN.
6. Return the final result multiplied by the sign.

Time Complexity: O(n) - We traverse the string once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int myAtoi(string s) {
    int i = 0, sign = 1;
    long res = 0;

    // Skip leading whitespace characters
    while (i < s.size() && s[i] == ' ')
        i++;

    // Check for an optional sign character
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        sign = s[i++] == '+' ? 1 : -1;

    // Convert digits to integer
    while (i < s.size() && isdigit(s[i])) {
        res = res * 10 + s[i] - '0';
        if (res * sign >= INT_MAX) return INT_MAX;
        else if (res * sign <= INT_MIN) return INT_MIN;
        i++;
    }

    return res * sign;
}

int main() {
    // Test case 1: Convert "42" to integer
    // Explanation: The string "42" is converted to the integer 42.
    string s1 = "42";
    cout << "String: \"" << s1 << "\", Integer: " << myAtoi(s1) << endl;

    // Test case 2: Convert "   -42" to integer
    // Explanation: The string "   -42" is converted to the integer -42.
    string s2 = "   -42";
    cout << "String: \"" << s2 << "\", Integer: " << myAtoi(s2) << endl;

    // Test case 3: Convert "4193 with words" to integer
    // Explanation: The string "4193 with words" is converted to the integer 4193.
    string s3 = "4193 with words";
    cout << "String: \"" << s3 << "\", Integer: " << myAtoi(s3) << endl;

    // Test case 4: Convert "words and 987" to integer
    // Explanation: The string "words and 987" is converted to the integer 0.
    string s4 = "words and 987";
    cout << "String: \"" << s4 << "\", Integer: " << myAtoi(s4) << endl;

    // Test case 5: Convert "-91283472332" to integer
    // Explanation: The string "-91283472332" is converted to the integer -2147483648 (INT_MIN).
    string s5 = "-91283472332";
    cout << "String: \"" << s5 << "\", Integer: " << myAtoi(s5) << endl;

    return 0;
}