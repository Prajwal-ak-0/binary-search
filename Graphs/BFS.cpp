#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Breadth First Search for a graph represented using adjacency list
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0); // Vector to keep track of visited nodes
    queue<int> q; // Queue to manage the BFS traversal order
    q.push(0); // Starting BFS from node 0
    vector<int> ans; // Vector to store the BFS traversal
    
    while (!q.empty()) {
        int curr = q.front(); // Get the current node from the queue
        q.pop();
        if (!visited[curr]) { // Check if the node has been visited to avoid duplicates in ans
            visited[curr] = 1; // Mark the node as visited
            ans.push_back(curr); // Add the current node to the answer list
            
            // Add all unvisited adjacent nodes to the queue
            for (auto n : adj[curr]) {
                if (!visited[n]) {
                    q.push(n);
                }
            }
        }
    }
    
    return ans; // Return the BFS traversal
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

    // Perform BFS and print the traversal
    vector<int> bfsTraversal = bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for (int v : bfsTraversal) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}