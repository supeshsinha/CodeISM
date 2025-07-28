#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> pt;
vector<int> sz;
int ans = 0;

void dfs(int node, int par){
    for(auto ch: adj[node]){
        if(ch == par) continue;
        dfs(ch, node);
        pt[node] += pt[ch];
        sz[node] += sz[ch];
    }
    pt[node] += sz[node];
}

void dfs1(int node, int par){
    ans = max(ans, pt[node]);

    for(auto ch: adj[node]){
        if(ch== par) continue;

        pt[node] -= (pt[ch] + sz[ch]);
        sz[node] -= sz[ch];
        pt[ch] += (pt[node] + sz[node]);
        sz[ch] += sz[node];

        dfs1(ch, node);

        sz[ch] -= sz[node];
        pt[ch] -= (pt[node] + sz[node]);
        sz[node] += sz[ch];
        pt[node] += (pt[ch] + sz[ch]);
    }
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    pt.assign(n+1, 0);
    sz.assign(n+1, 1);

    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    dfs1(1, -1);
    
    cout<<ans<<endl;


    return 0;
}
