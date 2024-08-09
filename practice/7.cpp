#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &s){
    vis[node] = true;
    
    for(auto n : adj[node]){
        if(!vis[n]){
            dfs(n, adj, vis, s);
        }
    }
    
    s.push(node);
}

vector<int> topo(int v, vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(v+1, 0);
    stack<int> s;
    
    for(int i = 1; i<=v; i++){
        if(!vis[i]){
            dfs(i, adj, vis, s);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

int main()
{
    vector<int> adj[7];
    
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);

    vector<int> topoSortResult = topo(6, adj);

    cout << "Topological Sort Order:" << endl;
    for (auto it : topoSortResult)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
