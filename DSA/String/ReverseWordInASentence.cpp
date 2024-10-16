#include <iostream>
#include <string>

using namespace std;

/*
Idea: Reverse the words in a given sentence.

Approach:
1. Reverse the entire string.
2. Traverse the reversed string and reverse each word back to its original order.
3. Append each reversed word to the result string.
4. Remove any trailing spaces from the result string.

Time Complexity: O(n) - We traverse the string twice.
Space Complexity: O(n) - We use additional space for the result string and temporary strings.
*/

string rev(string s) {
    string temp = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        temp += s[i];
    }
    return temp;
}

string reverseWords(string s) {
    s = rev(s);

    string S = "", temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (!temp.empty()) {
                S += rev(temp) + ' ';
                temp = "";
            }
        } else {
            temp += s[i];
        }
    }
    if (!temp.empty()) {
        S += rev(temp);
    }

    if (S.back() == ' ') S.pop_back();

    return S;
}

int main() {
    // Test case 1: Reverse words in "hello world"
    // Explanation: The reversed sentence should be "world hello"
    string sentence1 = "hello world";
    cout << "Original: " << sentence1 << endl;
    cout << "Reversed: " << reverseWords(sentence1) << endl;

    // Test case 2: Reverse words in "The quick brown fox"
    // Explanation: The reversed sentence should be "fox brown quick The"
    string sentence2 = "The quick brown fox";
    cout << "Original: " << sentence2 << endl;
    cout << "Reversed: " << reverseWords(sentence2) << endl;

    // Test case 3: Reverse words in "a b c d e"
    // Explanation: The reversed sentence should be "e d c b a"
    string sentence3 = "a b c d e";
    cout << "Original: " << sentence3 << endl;
    cout << "Reversed: " << reverseWords(sentence3) << endl;

    // Test case 4: Reverse words in "singleword"
    // Explanation: The reversed sentence should be "singleword"
    string sentence4 = "singleword";
    cout << "Original: " << sentence4 << endl;
    cout << "Reversed: " << reverseWords(sentence4) << endl;

    return 0;
}