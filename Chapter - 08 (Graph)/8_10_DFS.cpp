#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> graph[MAX_N];
bool vis[MAX_N];

void dfs(int vertex){
    vis[vertex] = true;
    cout << vertex << ' ';
    for (auto child : graph[vertex]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main(){
    cout << "Enter The Number of nodes and edges: ";
    int n , e;
    cin >> n >> e;
    for(int i = 0; i < e; ++i){
        int v1 , v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout << "DFS traversal:  ";
    dfs(2);
    cout << endl;
    return  0;
}