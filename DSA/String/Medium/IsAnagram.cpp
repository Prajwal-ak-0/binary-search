#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

/*
Idea: Check if two strings are anagrams using an unordered map.

Approach:
1. If the sizes of the strings are different, return false.
2. Use an unordered map to count the frequency of each character in both strings.
3. Increment the count for characters in the first string and decrement for characters in the second string.
4. If all counts are zero, the strings are anagrams.

Time Complexity: O(n) - We traverse both strings once.
Space Complexity: O(1) - The unordered map will have at most 26 entries (for lowercase English letters).
*/

bool isAnagramUsingMap(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        mp[t[i]]--;
    }

    for (auto count : mp) {
        if (count.second != 0) return false;
    }

    return true;
}

/*
Idea: Check if two strings are anagrams using a vector.

Approach:
1. If the sizes of the strings are different, return false.
2. Use a vector of size 26 to count the frequency of each character in both strings.
3. Increment the count for characters in the first string and decrement for characters in the second string.
4. If all counts are zero, the strings are anagrams.

Time Complexity: O(n) - We traverse both strings once.
Space Complexity: O(1) - The vector will have exactly 26 entries.
*/

bool isAnagramUsingVector(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> count(26, 0);

    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

int main() {
    // Test case 1: "anagram" and "nagaram" are anagrams
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Using Map - Are \"" << s1 << "\" and \"" << t1 << "\" anagrams? " << (isAnagramUsingMap(s1, t1) ? "Yes" : "No") << endl;
    cout << "Using Vector - Are \"" << s1 << "\" and \"" << t1 << "\" anagrams? " << (isAnagramUsingVector(s1, t1) ? "Yes" : "No") << endl;

    // Test case 2: "rat" and "car" are not anagrams
    string s2 = "rat";
    string t2 = "car";
    cout << "Using Map - Are \"" << s2 << "\" and \"" << t2 << "\" anagrams? " << (isAnagramUsingMap(s2, t2) ? "Yes" : "No") << endl;
    cout << "Using Vector - Are \"" << s2 << "\" and \"" << t2 << "\" anagrams? " << (isAnagramUsingVector(s2, t2) ? "Yes" : "No") << endl;

    // Test case 3: "listen" and "silent" are anagrams
    string s3 = "listen";
    string t3 = "silent";
    cout << "Using Map - Are \"" << s3 << "\" and \"" << t3 << "\" anagrams? " << (isAnagramUsingMap(s3, t3) ? "Yes" : "No") << endl;
    cout << "Using Vector - Are \"" << s3 << "\" and \"" << t3 << "\" anagrams? " << (isAnagramUsingVector(s3, t3) ? "Yes" : "No") << endl;

    // Test case 4: "a" and "a" are anagrams
    string s4 = "a";
    string t4 = "a";
    cout << "Using Map - Are \"" << s4 << "\" and \"" << t4 << "\" anagrams? " << (isAnagramUsingMap(s4, t4) ? "Yes" : "No") << endl;
    cout << "Using Vector - Are \"" << s4 << "\" and \"" << t4 << "\" anagrams? " << (isAnagramUsingVector(s4, t4) ? "Yes" : "No") << endl;

    return 0;
}