#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> par, rank;
public:
    DisjointSet(int n){
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++){
            par[i] = i;
        }
    }
    int find_parent(int node){
        if (node == par[node])
            return node;
        else
            return par[node] = find_parent(par[node]);
    }
    void union_by_rank(int u, int v){
        int ult_u = find_parent(u);
        int ult_v = find_parent(v);
        if (ult_u == ult_v)
            return;
        else if (rank[ult_u] < rank[ult_v]){
            par[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v]){
            par[ult_v] = ult_u;
        }else{
            par[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};

int main(){
    int node, edge, total_cost = 0;
    cin >> node >> edge;
    DisjointSet s(node + 5);
    vector<pair<int, pair<int, int>>> st;
    for (int i = 0; i < edge; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        st.pb({w, {v1, v2}});
    }
    sort(all(st));
    for (int i = 0; i < edge; i++){
        if (s.find_parent(st[i].second.first) == s.find_parent(st[i].second.second))
            continue;
        s.union_by_rank(st[i].second.first, st[i].second.second);
        total_cost += st[i].first;
    }
    cout << total_cost;
}