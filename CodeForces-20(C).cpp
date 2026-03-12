#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adjNode=it.first;
            int adjWeight=it.second;
            if(weight+adjWeight<dist[adjNode]){
                dist[adjNode]=weight+adjWeight;
                
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX){
            cout<<"-1 ";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }
}
