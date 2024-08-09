#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

vector<int> dfs(int v, vector<int> adj[], vector<int>& vis)
{
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

bool isConnected(int v, vector<int> adj[]){
    vector<int> vis(v+1, 0);
    dfs(v, adj, vis );
    
    for(int i = 1; i<=v ;i++){
        if(adj[i].size() > 0 && !vis[i]) return false;
    }
    
    return true;
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

    if (isConnected(5, adj))
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
