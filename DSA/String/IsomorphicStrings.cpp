#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
Idea: Determine if two strings are isomorphic.

Approach:
1. Use two unordered maps to keep track of character mappings from s to t and t to s.
2. If the lengths of the strings are different, return false.
3. Traverse both strings simultaneously.
4. For each character pair, check if the characters are already mapped.
5. If not, create the mapping in both maps.
6. If the characters are already mapped, check if the existing mapping is consistent.
7. If any inconsistency is found, return false.
8. If the traversal completes without inconsistencies, return true.

Time Complexity: O(n) - We traverse both strings once.
Space Complexity: O(1) - The unordered maps will have at most 256 entries (for ASCII characters).
*/

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mp_s, mp_t;
    int i = s.size(), j = t.size();

    if (i != j)
        return false;

    for (int i_1 = 0; i_1 < i; i_1++) {
        if (mp_s.find(s[i_1]) == mp_s.end() && mp_t.find(t[i_1]) == mp_t.end()) {
            mp_s[s[i_1]] = t[i_1];
            mp_t[t[i_1]] = s[i_1];
        } else if (mp_s[s[i_1]] != t[i_1] || mp_t[t[i_1]] != s[i_1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test case 1: "egg" and "add" are isomorphic
    // Explanation: 'e' -> 'a', 'g' -> 'd'
    string s1 = "egg";
    string t1 = "add";
    cout << "Are \"" << s1 << "\" and \"" << t1 << "\" isomorphic? " << (isIsomorphic(s1, t1) ? "Yes" : "No") << endl;

    // Test case 2: "foo" and "bar" are not isomorphic
    // Explanation: 'f' -> 'b', 'o' -> 'a' (inconsistent mapping)
    string s2 = "foo";
    string t2 = "bar";
    cout << "Are \"" << s2 << "\" and \"" << t2 << "\" isomorphic? " << (isIsomorphic(s2, t2) ? "Yes" : "No") << endl;

    // Test case 3: "paper" and "title" are isomorphic
    // Explanation: 'p' -> 't', 'a' -> 'i', 'e' -> 'l', 'r' -> 'e'
    string s3 = "paper";
    string t3 = "title";
    cout << "Are \"" << s3 << "\" and \"" << t3 << "\" isomorphic? " << (isIsomorphic(s3, t3) ? "Yes" : "No") << endl;

    // Test case 4: "ab" and "cc" are not isomorphic
    // Explanation: 'a' -> 'c', 'b' -> 'c' (inconsistent mapping)
    string s4 = "ab";
    string t4 = "cc";
    cout << "Are \"" << s4 << "\" and \"" << t4 << "\" isomorphic? " << (isIsomorphic(s4, t4) ? "Yes" : "No") << endl;

    return 0;
}