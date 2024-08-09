#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>>& adj, int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

int primMST(const vector<vector<pii>>& adj, int V, int start, vector<int>& parent) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    pq.push({0, start});
    key[start] = 0;
    int total_length = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        total_length += key[u];

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    return total_length;
}

void printMSTPath(const vector<vector<pii>>& adj, const vector<int>& parent, int start) {
    cout << "Minimum Spanning Tree Path:" << endl;
    for (int i = 0; i < parent.size(); i++) {
        if (i != start) {
            cout << parent[i] << " - " << i << " (Weight: ";
            for (auto& neighbor : adj[parent[i]]) {
                if (neighbor.first == i) {
                    cout << neighbor.second;
                    break;
                }
            }
            cout << ")" << endl;
        }
    }
}

int main() {
    int V = 6;
    vector<vector<pii>> adj(V);
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 2);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 0, 4, 4);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 3, 4, 3);
    addEdge(adj, 3, 5, 7);
    addEdge(adj, 4, 5, 8);
    
    vector<int> parent(V, -1);
    int start = 5;
    int total_length = primMST(adj, V, start, parent);
    cout << "Total length of piping needed: " << total_length << " meters" << endl;

    printMSTPath(adj, parent, start);

    return 0;
}