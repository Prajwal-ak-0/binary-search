#include <iostream>
#include <vector>
using namespace std;

// Function to perform Depth First Search from a given node
void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &ans) {
    visited[node] = 1; // Mark the current node as visited
    ans.push_back(node); // Add the current node to the answer list
    
    // Recursively visit all the adjacent nodes that are not visited yet
    for (auto n : adj[node]) {
        if (!visited[n]) dfs(n, adj, visited, ans);
    }
}

// Function to perform DFS for a graph represented using adjacency list
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0); // Vector to keep track of visited nodes
    vector<int> ans; // Vector to store the DFS traversal
    
    // Start DFS from node 0 (assuming 0 as the starting node)
    dfs(0, adj, visited, ans);
    
    return ans; // Return the DFS traversal
}

int main() {
    // Example usage
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    // Perform DFS and print the traversal
    vector<int> dfsTraversal = dfsOfGraph(V, adj);
    cout << "DFS Traversal: ";
    for (int v : dfsTraversal) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}