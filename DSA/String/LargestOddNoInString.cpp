#include <iostream>
#include <string>

using namespace std;

/*
Idea: Find the largest odd number that can be formed from the given string of digits.

Approach:
1. Traverse the string from the end to the beginning.
2. Check each digit to see if it is odd.
3. If an odd digit is found, return the substring from the start to that digit (inclusive).
4. If no odd digit is found, return an empty string.

Time Complexity: O(n) - We traverse the string once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    // Test case 1: Largest odd number is "5"
    string num1 = "52";
    cout << "Largest odd number in " << num1 << ": " << largestOddNumber(num1) << endl;

    // Test case 2: Largest odd number is "35427"
    string num2 = "354270";
    cout << "Largest odd number in " << num2 << ": " << largestOddNumber(num2) << endl;

    // Test case 3: No odd number, should return an empty string
    string num3 = "24680";
    cout << "Largest odd number in " << num3 << ": " << largestOddNumber(num3) << endl;

    // Test case 4: Largest odd number is "13579"
    string num4 = "13579";
    cout << "Largest odd number in " << num4 << ": " << largestOddNumber(num4) << endl;

    return 0;
}