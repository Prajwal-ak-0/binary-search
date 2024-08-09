#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

vector<int> dfs(int v, vector<int> adj[])
{
    vector<int> vis(v + 1, 0);
    vector<int> ans;
    stack<int> s;

    vis[1] = 1;
    s.push(1);

    while (!s.empty())
    {
        int node = s.top();
        ans.push_back(node);
        s.pop();
        
        for (auto it : adj[node])
            if (!vis[it])
            {
                s.push(it);
                vis[it] = 1;
            }
    }
    return ans;
}

int main()
{
    vector<int> adj[6];
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
    vector<int> res = dfs(5, adj);
    for (auto it : res)
        cout << it << " " << endl;
    return 0;
}