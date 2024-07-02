#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    queue<pair<string, int>> q;
    q.push({startGene, 0});

    unordered_set<string> st(bank.begin(), bank.end());
    if (st.find(endGene) == st.end())
        return -1;
    st.erase(startGene);

    char arr[] = {'A', 'C', 'G', 'T'};

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endGene) {
            return steps;
        }

        for (int i = 0; i < word.size(); i++) {
            char originalChar = word[i];
            for (auto ch : arr) {
                word[i] = ch;
                if (st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = originalChar;
        }
    }

    return -1;
}

int main() {
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    int mutations = minMutation(startGene, endGene, bank);
    cout << "Minimum mutations needed: " << mutations << endl;
    return 0;
}

/*
Idea:
Solve the "Minimum Genetic Mutation" problem by finding the shortest transformation sequence from startGene to endGene using BFS.

Approach:
1. Use a queue to perform BFS, starting from startGene.
2. For each gene, iterate through its characters, changing one character at a time to 'A', 'C', 'G', or 'T'.
3. If the new gene is in the bank, it's a valid mutation. Add it to the queue and remove it from the bank to avoid revisiting.
4. Continue until the endGene is found or the queue is empty.

Time Complexity: O(N*M^2), where N is the number of genes in the bank and M is the length of each gene.
Space Complexity: O(N), for storing the genes in a set.

Example Test Case:
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
Output: 2
*/