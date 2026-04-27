#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<bool> visited(n, false);

    pq.push({0,0});

    int total_weight = 0;

    while(!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        total_weight += wt;

        for(auto [next, edgeWt] : adj[node]) {
            if(!visited[next]) {
                pq.push({edgeWt, next});
            }
        }
    }

    cout << total_weight << endl;
}
