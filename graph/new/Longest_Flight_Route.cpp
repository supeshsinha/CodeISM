#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<bool> vis;
vector<int> child;

void dfs(int node){
    vis[node] = 1;

    for(auto ch: adj[node]){
        if(!vis[ch]) dfs(ch);
        if(dist[ch] > dist[node]){
            dist[node] = dist[ch];
            child[node] = ch;
        }
    }
    if(dist[node] != -1) dist[node]++;
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    dist.assign(n+1, -1);
    vis.assign(n+1,0);
    child.resize(n+1,-1);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    dist[n] = 0;

    dfs(1);

    if(dist[1] == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[1]<<endl;
        int t = 1;
        while(t!= -1){
            cout<<t<<" ";
            t = child[t];
        }
        cout<<endl;
    }

    return 0;
}
