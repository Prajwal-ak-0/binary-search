#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

vector<int> bfs(int v, vector<int> adj[])
{
    vector<int> vis(v + 1, 0);
    vector<int> ans;
    queue<int> q;

    vis[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    int v = 5;
    vector<int> adj[v+1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 2);
    addEdge(adj, 5, 1);
    vector<int> result = bfs(v, adj);
    for (auto it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}