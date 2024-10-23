#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
Idea: Find the length of the longest substring without repeating characters.

Approach:
1. Use a sliding window approach with two pointers `i` and `j`.
2. Use an unordered map to keep track of the characters in the current window.
3. Traverse the string with the right pointer `j`.
4. If the current character is already in the map, move the left pointer `i` to the right until the character is removed from the map.
5. Update the maximum length of the substring.
6. Return the maximum length.

Time Complexity: O(n) - We traverse the string once.
Space Complexity: O(min(n, m)) - We use an unordered map to store the characters in the current window, where n is the length of the string and m is the size of the character set.
*/

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int i = 0, j = 0, mx = 0;

    while (j < s.size()) {
        if (mp.find(s[j]) == mp.end()) {
            mp[s[j]] = j;
            mx = max(mx, j - i + 1);
            j++;
        } else {
            while (i < j && mp.find(s[j]) != mp.end()) {
                mp.erase(s[i]);
                i++;
            }
        }
    }

    return mx;
}

int main() {
    // Test case 1: "abcabcbb"
    // Explanation: The longest substring without repeating characters is "abc", which has length 3.
    string s1 = "abcabcbb";
    cout << "String: \"" << s1 << "\", Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s1) << endl;

    // Test case 2: "bbbbb"
    // Explanation: The longest substring without repeating characters is "b", which has length 1.
    string s2 = "bbbbb";
    cout << "String: \"" << s2 << "\", Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s2) << endl;

    // Test case 3: "pwwkew"
    // Explanation: The longest substring without repeating characters is "wke", which has length 3.
    string s3 = "pwwkew";
    cout << "String: \"" << s3 << "\", Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s3) << endl;

    // Test case 4: "dvdf"
    // Explanation: The longest substring without repeating characters is "vdf", which has length 3.
    string s4 = "dvdf";
    cout << "String: \"" << s4 << "\", Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s4) << endl;

    return 0;
}