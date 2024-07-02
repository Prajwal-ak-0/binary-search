#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    if (st.find(endWord) == st.end()) return 0; // End word not in list

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord) return steps;

        for (int i = 0; i < word.size(); i++) {
            char originalChar = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = originalChar;
        }
    }
    return 0;
}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    int length = ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << length << endl;
    return 0;
}

/*
Idea:
Solve the "Word Ladder" problem by finding the shortest transformation sequence from beginWord to endWord using BFS.

Approach:
1. Use a queue to perform BFS, starting from beginWord.
2. For each word, iterate through its characters, changing one character at a time to every letter from 'a' to 'z'.
3. If the new word is in the wordList, it's a valid transformation. Add it to the queue and remove it from the wordList to avoid revisiting.
4. Continue until the endWord is found or the queue is empty.

Time Complexity: O(N*M^2), where N is the number of words in the wordList and M is the length of each word.
Space Complexity: O(N), for storing the words in a set.

Example Test Case:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
*/