#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e18));
    for(int i=1; i<=n; i++) dist[i][i] = 0;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = min(w,dist[u][v]);
        dist[v][u] = min(w,dist[v][u]);
    }

    for(int k=1; k<=n ;k++){
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        cout<<(dist[a][b] == 1e18 ? -1 : dist[a][b])<<endl;
    }

    return 0;
}
