#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
Idea: Sort characters in a string by their frequency in descending order.

Approach:
1. Use an unordered map to count the frequency of each character in the string.
2. Store the characters and their frequencies in a vector of pairs.
3. Sort the vector of pairs in descending order based on the frequency.
4. Construct the result string by appending each character the number of times it appears.
5. Return the result string.

Time Complexity: O(n log n) - Sorting the vector of pairs.
Space Complexity: O(n) - Storing the frequency of each character and the result string.
*/

string frequencySort(string s) {
    unordered_map<char, int> mp;

    for (char c : s) mp[c]++;

    vector<pair<int, char>> chars;
    for (auto [ch, count] : mp) chars.push_back({count, ch});

    sort(chars.rbegin(), chars.rend());

    string result;
    for (auto [count, ch] : chars) result.append(count, ch);

    return result;
}

int main() {
    // Test case 1: Frequency sort of "tree"
    // Explanation: 'e' appears twice, 't' and 'r' appear once. Possible outputs: "eert", "eetr"
    string s1 = "tree";
    cout << "Original: " << s1 << endl;
    cout << "Frequency sorted: " << frequencySort(s1) << endl;

    // Test case 2: Frequency sort of "cccaaa"
    // Explanation: 'c' and 'a' appear three times each. Possible outputs: "cccaaa", "aaaccc"
    string s2 = "cccaaa";
    cout << "Original: " << s2 << endl;
    cout << "Frequency sorted: " << frequencySort(s2) << endl;

    // Test case 3: Frequency sort of "Aabb"
    // Explanation: 'b' appears twice, 'A' and 'a' appear once. Possible outputs: "bbAa", "bbaA"
    string s3 = "Aabb";
    cout << "Original: " << s3 << endl;
    cout << "Frequency sorted: " << frequencySort(s3) << endl;

    // Test case 4: Frequency sort of "abacabad"
    // Explanation: 'a' appears four times, 'b' appears twice, 'c' and 'd' appear once. Possible outputs: "aaaabbcd", "aaaabdbc", etc.
    string s4 = "abacabad";
    cout << "Original: " << s4 << endl;
    cout << "Frequency sorted: " << frequencySort(s4) << endl;

    return 0;
}