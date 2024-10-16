#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Approach 1: Horizontal Scanning
Idea: Compare the prefix of the first string with each subsequent string and reduce the prefix length until it matches.
1. Initialize the prefix as the first string.
2. Iterate through the rest of the strings.
3. While the current string does not start with the prefix, reduce the prefix length by one character.
4. If the prefix becomes empty, return an empty string.
5. Return the final prefix.

Time Complexity: O(n * m) - where n is the number of strings and m is the length of the prefix.
Space Complexity: O(1) - Only a few extra variables are used.
*/

string longestCommonPrefixHorizontal(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        string s = strs[i];

        while (s.find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix == "")
                return "";
        }
    }

    return prefix;
}

/*
Approach 2: Vertical Scanning
Idea: Compare characters of each string at the same position until a mismatch is found.
1. If the input vector is empty, return an empty string.
2. Initialize an index to 0 to keep track of the current character position.
3. Use a while loop to iterate through the characters of the first string.
4. For each character, check if it is present at the same position in all other strings.
5. If a mismatch is found or the end of any string is reached, return the substring from the start to the current index.
6. If no mismatch is found, increment the index and continue.

Time Complexity: O(n * m) - where n is the number of strings and m is the length of the shortest string.
Space Complexity: O(1) - Only a few extra variables are used.
*/

string longestCommonPrefixVertical(vector<string>& strs) {
    if (strs.empty()) return "";

    int index = 0; 
    while (true) {
        char currentChar; 

        if (index >= strs[0].size()) return strs[0];

        currentChar = strs[0][index];

        for (int i = 1; i < strs.size(); i++) {
            if (index >= strs[i].size() || strs[i][index] != currentChar) {
                return strs[0].substr(0, index);
            }
        }
        index++; 
    }
}

int main() {
    // Test case 1: Common prefix is "fl"
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Horizontal Scanning - Longest common prefix: " << longestCommonPrefixHorizontal(strs1) << endl;
    cout << "Vertical Scanning - Longest common prefix: " << longestCommonPrefixVertical(strs1) << endl;

    // Test case 2: No common prefix
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Horizontal Scanning - Longest common prefix: " << longestCommonPrefixHorizontal(strs2) << endl;
    cout << "Vertical Scanning - Longest common prefix: " << longestCommonPrefixVertical(strs2) << endl;

    // Test case 3: Common prefix is "a"
    vector<string> strs3 = {"a"};
    cout << "Horizontal Scanning - Longest common prefix: " << longestCommonPrefixHorizontal(strs3) << endl;
    cout << "Vertical Scanning - Longest common prefix: " << longestCommonPrefixVertical(strs3) << endl;

    // Test case 4: Common prefix is "inters"
    vector<string> strs4 = {"interspecies", "interstellar", "interstate"};
    cout << "Horizontal Scanning - Longest common prefix: " << longestCommonPrefixHorizontal(strs4) << endl;
    cout << "Vertical Scanning - Longest common prefix: " << longestCommonPrefixVertical(strs4) << endl;

    return 0;
}