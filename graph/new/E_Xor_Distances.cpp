#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

const int mod = 1e9+7;
vector<vector<pair<int,int>>> adj;
vector<int> dist;
vector<bool> vis;


void dfs(int node){
    vis[node] = 1;

    for(auto ch: adj[node]){
        if(!vis[ch.first]){
            dist[ch.first] = dist[node]^ch.second;
            dfs(ch.first);
        }
    }
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    dist.assign(n+1,0);
    vis.assign(n+1, 0);

    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dfs(1);

    vector<int> one(60,0);
    vector<int> zero(60,0);
    for(int i=1; i<=n; i++) for(int j=0; j<60; j++){
        if(dist[i] & 1ll<<j) one[j]++;
        else zero[j]++;
    }
    int ans = 0;

    for(int i=0; i<60; i++){
        ans += (((1ll<<i)%mod) * ((one[i]*zero[i])%mod))%mod;
        ans %= mod;
    }
    cout<<ans<<endl;

    return 0;
}
