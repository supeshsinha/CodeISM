#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> a;
vector<vector<pair<int,int>>> adj;
vector<int> sz;

int ans = 0;

void dfs(int node, int par){

    for(auto ch: adj[node]){
        if(ch.first == par) continue;
        dfs(ch.first, node);
        sz[node] += sz[ch.first];
    }
}

void dfs1(int node, int par, int dist){
    if(dist > a[node]){
        ans += sz[node];
        return;
    }
    for(auto ch: adj[node]){
        if(ch.first == par) continue;
        dfs1(ch.first, node, max(0ll, dist + ch.second));
    }
}


int32_t main(){
    int n;
    cin>>n;
    a.resize(n+1);
    adj.resize(n+1);
    sz.assign(n+1,1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n-1; i++){
        int p,c;
        cin>>p>>c;
        adj[p].push_back({i+1,c});
        adj[i+1].push_back({p,c});
    }
    dfs(1,-1);
    dfs1(1,-1,0);
    cout<<ans<<endl;

    return 0;
}
