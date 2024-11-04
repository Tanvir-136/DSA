#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (!vis[cur])
            vis[cur] = true;
            
        cout << cur << ' ';
        for(auto child: graph[cur]){
            if(!vis[child]){
                q.push(child);
            }
        }
    }
}
int main() {
    int n, e; 
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;
    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }

    cout << "BFS Traversal from node 1: ";
    bfs(1); 
    cout << endl;
    return 0;
}