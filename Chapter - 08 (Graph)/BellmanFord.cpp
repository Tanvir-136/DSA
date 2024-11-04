#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int source) {
    vector<int> dis(V, 1e8);
    dis[source] = 0; 
    for (int i = 0; i < V - 1; ++i) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt; 
            }
        }
    }
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
            return {-1};
        }
    }
    return dis; 
}

int main() {
    int V, E, source;
    cout << "Enter number of vertices, edges, and source vertex: ";
    cin >> V >> E >> source;

    vector<vector<int>> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<int> distances = bellman_ford(V, edges, source);

    if (distances[0] == -1) {
        cout << "Negative-weight cycle detected.\n";
    } else {
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (distances[i] == 1e8)
                cout << "Node " << i << " is unreachable\n";
            else
                cout << "Node " << i << " : " << distances[i] << '\n';
        }
    }
    return 0;
}