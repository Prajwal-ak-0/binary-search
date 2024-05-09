#include <iostream>
#include <string>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    /* 
    Idea/Approach:
    This function uses the sliding window approach to find the length of the longest substring without repeating characters.
    The sliding window is a substring of `s` that starts at index `i` and ends at index `j`.
    The window expands by moving `j` to the right and shrinks by moving `i` to the right.
    An unordered_set `ch` is used to check if a character is repeated in the current window.
    */

    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        
        int i = 0, j = 0, n = s.length(), max_len = INT_MIN;
        unordered_set<char> ch;
        while(j < n){
            char curr = s[j];
            if(ch.find(curr) == ch.end()){
                ch.insert(curr);
                j++;
                max_len = max(max_len, j - i);
            }
            else{
                ch.erase(s[i]);
                i++;
            }
        }
        return max_len;
    }
};

int main() {
    // Test Case:
    // Input: s = "abcabcbb"
    // Output: 3
    // Explanation: The answer is "abc", with the length of 3.
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);

    // Print the result
    cout << "The length of the longest substring without repeating characters in \"" << s << "\" is " << result << "." << endl;

    return 0;
}