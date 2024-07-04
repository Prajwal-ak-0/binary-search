#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Detect cycle in an undirected graph using Depth First Search (DFS)
// Idea: Traverse the graph using DFS. If we visit a node that is already visited and is not the parent of the current node, a cycle exists.
// Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for storing the visited array and the recursion stack.
bool detectCycleUsingDFS(int node, int parent, int visited[], vector<int> adj[]) {
    visited[node] = 1;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (detectCycleUsingDFS(neighbour, node, visited, adj))
                return true;
        } else if (neighbour != parent)
            return true;
    }

    return false;
}

// Detect cycle in an undirected graph using Breadth First Search (BFS)
// Idea: Traverse the graph using BFS. If we find an already visited node which is not the parent of the current node, a cycle exists.
// Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for storing the visited array and the queue.
bool detectCycleUsingBFS(int src, vector<int> adj[], int visited[]) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                q.push({neighbour, node});
            } else if (parent != neighbour) {
                return true;
            }
        }
    }

    return false;
}

// Main function to check if a cycle exists in the graph
// Approach: Use both DFS and BFS to detect a cycle in the graph.
// Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for storing the visited array.
bool isCycle(int V, vector<int> adj[]) {
    int visited[V];

    fill_n(visited, V, 0);

    // First, try to detect a cycle using BFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycleUsingBFS(i, adj, visited)) return true;
        }
    }

    // Reset visited array for DFS check
    fill_n(visited, V, 0);

    // Then, try to detect a cycle using DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycleUsingDFS(i, -1, visited, adj)) return true;
        }
    }

    // If no cycle is found using both methods, return false
    return false;
}

// Example main function
int main() {
    // Example graph with a cycle: 0-1-2-0
    int V = 3;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};

    // Test case explanation: This graph has 3 vertices and 3 edges forming a triangle. Thus, it contains a cycle.
    if (isCycle(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}