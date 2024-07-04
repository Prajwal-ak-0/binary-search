#include <iostream>
#include <vector>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto n : adj[node])
    {
        if (!vis[n])
        {
            if (dfsCheck(n, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[n])
            return true;
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int vis[V];
    int pathVis[V];

    fill_n(vis, V, 0);
    fill_n(pathVis, V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis))
                return true;
        }
    }

    return false;
}

int main()
{
    // Example graph with a cycle: 0 -> 1 -> 2 -> 3 -> 4 -> 2
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(2); // Back edge creating a cycle

    // Test case explanation: In this graph, there's a cycle formed by the vertices 2 -> 3 -> 4 -> 2.
    if (isCyclic(V, adj))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}