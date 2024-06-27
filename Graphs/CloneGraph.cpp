#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> cloneMap; // Used in approach2

public:
    Node* cloneGraph_approach1(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> toVisit;

        Node* clone = new Node(node->val);
        cloneMap[node] = clone;
        toVisit.push(node);

        while (!toVisit.empty()) {
            Node* curr = toVisit.front();
            toVisit.pop();

            for (Node* neighbor : curr->neighbors) {
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    Node* neighborClone = new Node(neighbor->val);
                    cloneMap[neighbor] = neighborClone;
                    toVisit.push(neighbor);
                }
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return clone;
    }

    Node* cloneGraph_approach2(Node* node) {
        if (node == nullptr)
            return nullptr;
        if (cloneMap.find(node) != cloneMap.end())
            return cloneMap[node];

        Node* clone = new Node(node->val);
        cloneMap[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph_approach2(neighbor));
        }

        return clone;
    }
};

int main() {
    // Example usage
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;
    Node* clonedGraph = solution.cloneGraph_approach1(node1);

    // Output or further processing of clonedGraph can be done here

    // Cleanup (not shown) to prevent memory leaks, especially in a real-world scenario
    return 0;
}

/*
Idea:
Clone a graph represented as a node structure by either BFS (approach1) or DFS (approach2).

Approach 1 (BFS):
1. Use a queue to perform BFS on the original graph.
2. Use a hash map to keep track of cloned nodes to avoid duplicates.
3. For each node, clone it and its neighbors, updating the clone map and queue accordingly.

Approach 2 (DFS):
1. Use recursion to perform DFS on the original graph.
2. Use a hash map to keep track of cloned nodes to avoid duplicates and to serve as a visited set.
3. For each node, clone it and recursively clone its neighbors.

Time Complexity:
Both approaches run in O(V+E) time, where V is the number of vertices and E is the number of edges in the graph.

Space Complexity:
O(V) for the hash map (and O(V) for the call stack in approach 2).

Example Test Case:
Given a graph:
1 -- 2
|    |
4 -- 3

The output will be a deep copy of the given graph.
*/