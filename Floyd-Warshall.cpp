#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    const int INF = 1e9;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i=1;i<=n;i++)
        dist[i][i] = 0;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INF) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
