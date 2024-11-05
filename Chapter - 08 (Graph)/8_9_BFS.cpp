#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

void bfs(int start){
    queue<int>  q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (vis[cur])
            continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(auto it : graph[cur]){
            if (vis[it])
                continue;
            q.push(it);
            
        }

    }
}
int main(){
    int node, edge;
    cout << "Enter the number of vertex and edge: ";
    cin >> node >> edge;
    cout << "Enter the Number(v1, v2) of vertex which are connected by the edge: \n";
    for (int i = 0; i < edge; ++i){
        int v1 , v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // for undirected graph
    }
    cout << " DFS traversal of this graph from vertex 1: ";
    bfs(1);
    return 0;
}