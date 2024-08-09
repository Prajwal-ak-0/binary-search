#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>> &adj, int u, int v, int w)
{
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

vector<int> dijkstra(const vector<vector<pii>> &adj, int V, int src, vector<int> &parent)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(V, INT_MAX);

    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &n : adj[u])
        {
            int v = n.first;
            int w = n.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }

    return dis;
}

void printPath(const vector<int> &parent, int j, const vector<string> &cities)
{
    if (parent[j] == -1)
    {
        cout << cities[j];
        return;
    }

    printPath(parent, parent[j], cities);
    cout << " -> " << cities[j];
}

int main()
{
    int V = 7;
    int src = 0;
    vector<vector<pii>> adj(V);
    vector<int> parent(V, -1);
    vector<string> cities = {"San Francisco", "Los Angeles", "Denver", "Dallas", "Chicago", "New York", "Boston"};

    addEdge(adj, 0, 1, 3);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 4, 7);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 2, 4, 6);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 5, 6);
    addEdge(adj, 3, 4, 5);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 4, 6, 3);
    addEdge(adj, 5, 6, 2);

    vector<int> distance = dijkstra(adj, V, src, parent);

    for (int i = 0; i < distance.size(); i++)
    {
        cout << "Distance to " << cities[i] << " is " << distance[i] << endl;
        cout << "Path : ";
        printPath(parent, i, cities);
        cout << endl
             << endl;
    }
    cout << endl;
}